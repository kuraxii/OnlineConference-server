/*********************************************
 * @FileName: HttpResponse.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:33:01 2024
 * @Descript:
 */
#include "HttpResponse.h"

const std::unordered_map<int, std::string> HttpResponse::CODE_STATUS = {
    {200, "OK"},
    {400, "Bad Request"},
    {403, "Forbidden"},
    {404, "Not Found"},
};
const std::vector<const char *> HttpResponse::CONTENTTYPE = {"txt", "image/jpeg", "contorl"};
const std::vector<const char *> HttpResponse::KEY = {"Content-Length", "Content-Type", "Authorization"};
HttpResponse &HttpResponse::setStatusCode(int code) {
    responseStatusCode_ = code;
    return *this;
}

HttpResponse &HttpResponse::setContentType(HttpResponseHeaderContentType contentType) {
    responseHeaders_["Content-Type"] = std::string(CONTENTTYPE.at(static_cast<int>(contentType)));
    return *this;
}
HttpResponse &HttpResponse::setContentLength(int len) {
    responseHeaders_["Content-Length"] = std::to_string(len);
    return *this;
}

HttpResponse &HttpResponse::setBody(const char *data, size_t len) {
    responseBody_.insert(responseBody_.begin(), data, data + len);
    return *this;
}

std::vector<char> &HttpResponse::toResponse(std::vector<char> &data) {
    std::string response =
        "HTTP/1.1 " + std::to_string(responseStatusCode_) + CODE_STATUS.find(responseStatusCode_)->second + "\r\n";
    for (const auto &it : responseHeaders_) {
        response += it.first + ':' + it.second + "\r\n";
    }
    response += "\r\n\r\n";

    response.append(responseBody_.data(), responseBody_.size());
    data.insert(data.begin(), response.begin(), response.end());
    return data;
}