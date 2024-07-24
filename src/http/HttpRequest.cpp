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
HttpRequest::HttpRequest()
    : requestState(State::START), requestContentLength_(0), requestBodyLength_(0), requestParsed_(false) {
}

void HttpRequest::parse(const std::vector<char> &data) {
    std::istringstream stream(data.data());
    std::string line;
    while (std::getline(stream, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        switch (requestState) {
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
            requestParsed_ = true;
        default:
            return;
        }
    }
}

void HttpRequest::parseRequestLine(const std::string &line) {
    static const std::regex requestLineRegex(R"((\w+)\s+(\S+)\s+(HTTP/\d+\.\d+))");
    std::smatch match;
    if (std::regex_match(line, match, requestLineRegex)) {
        requestMethod_ = match[1];
        requestUrl_ = match[2];
        requestVersion_ = match[3];
        requestState = State::HEADERS;
    }
}
void HttpRequest::parseHeader(const std::string &line) {
    if (line.empty()) {
        if (requestMethod_ == "POST" && requestContentLength_ > 0) {

            requestState = State::BODY;
        } else {
            requestState = State::END;
        }
        return;
    }

    std::string::size_type pos = line.find(": ");
    if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 2);
        requestHeaders_[key] = value;

        if (key == "Content-Length") {
            requestContentLength_ = std::stoi(value);
        }
    }
}
void HttpRequest::parseBody(const std::string &line) {
    thread_local size_t len = 0;

    requestPost_.insert(requestPost_.end(), line.begin(), line.end());
    requestPost_.push_back('\n');
    requestBodyLength_ += line.length() + 1; // Include '\n' in length

    if (requestBodyLength_ >= requestContentLength_) {
        requestState = State::END;
        requestParsed_ = true;
    }
}

std::string HttpRequest::getPath() const {
    return requestUrl_;
}

std::string HttpRequest::getHeader(std::string key) const {
    if (requestHeaders_.find(key) != requestHeaders_.end()) {
        return requestHeaders_.find(key)->second;
    }
    return {""};
}
std::vector<char> HttpRequest::getPost() const {
    return requestPost_;
}

std::string HttpRequest::getMethod() const {
    return requestMethod_;
}
std::string HttpRequest::getVersion() const {
    return requestVersion_;
}

bool HttpRequest::isParsed() {
    return requestParsed_;
}

void HttpRequest::print() {

    std::cout << "Method: " << requestMethod_ << std::endl;
    std::cout << "URI: " << requestUrl_ << std::endl;
    std::cout << "Version: " << requestVersion_ << std::endl;
    std::cout << "Headers:" << std::endl;
    for (const auto &header : requestHeaders_) {
        std::cout << "  " << header.first << ": " << header.second << std::endl;
    }
    std::cout << "Body: " << requestPost_.data() << std::endl;
}