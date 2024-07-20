/*********************************************
 * @FileName: HttpRequest.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:33:51 2024
 * @Descript:
 */

#include "HttpRequest.h"
#include <sstream>
#include <regex>
#include <iostream>
HttpRequest::HttpRequest() : state(State::START), contentLength(0), bodyLength(0), parsed(false) {
}

void HttpRequest::parse(const std::string &data) {
    std::istringstream stream(data);
    std::string line;
    while (std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        switch (state) {
        case State::START:
            parseRequestLine(line);
            break;

        case State::HEADERS:
            parseHeader(line);
            break;

        case State::BODY:
            parseBody(line);
            break;

        case State::END:
        default:
            return;
        }
    }
}

void HttpRequest::parseRequestLine(const std::string &line) {
    static const std::regex requestLineRegex(R"((\w+)\s+(\S+)\s+(HTTP/\d+\.\d+))");
    std::smatch match;
    if (std::regex_match(line, match, requestLineRegex)) {
        method = match[1];
        url = match[2];
        version = match[3];
        state = State::HEADERS;
    }
}
void HttpRequest::parseHeader(const std::string &line) {
    if (line.empty()) {
        if (method == "POST" && contentLength > 0) {
            state = State::BODY;
        } else {
            state = State::END;
        }
        return;
    }

    std::string::size_type pos = line.find(": ");
    if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 2);
        posts[key] = value;

        if (key == "Content-Length") {
            contentLength = std::stoi(value);
        }
    }
}
void HttpRequest::parseBody(const std::string &line) {
    thread_local size_t len = 0;

    body.insert(body.end(), line.begin(), line.end());
    body.push_back('\n');
    bodyLength += line.length() + 1; // Include '\n' in length

    if (bodyLength >= contentLength) {
        state = State::END;
        parsed = true;
    }
}

std::string HttpRequest::getPath() const {
    return url;
}

std::string HttpRequest::getHeader(std::string key) const {
    if (posts.find(key) != posts.end()) {
        return posts.find(key)->second;
    }
    return {""};
}
std::vector<char> HttpRequest::getBody() const {
    return body;
}

std::string HttpRequest::getMethod() const {
    return method;
}
std::string HttpRequest::getVersion() const {
    return version;
}

bool HttpRequest::isParse() {
    return parsed;
}

void HttpRequest::print() {

    std::cout << "Method: " << method << std::endl;
    std::cout << "URI: " << url << std::endl;
    std::cout << "Version: " << version << std::endl;
    std::cout << "Headers:" << std::endl;
    for (const auto &header : posts) {
        std::cout << "  " << header.first << ": " << header.second << std::endl;
    }
    std::cout << "Body: " << body.data() << std::endl;
}