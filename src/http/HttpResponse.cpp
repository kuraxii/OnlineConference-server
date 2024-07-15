/*********************************************
 * @FileName: HttpResponse.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:33:01 2024
 * @Descript:
 */
#include "HttpResponse.h"

HttpResponse::HttpResponse(int statusCode, const std::map<std::string, std::string>& headers, const std::vector<char>& body)
    : statusCode(statusCode), headers(headers), body(body) {}

int HttpResponse::getStatusCode() const {
    return statusCode;
}

const std::map<std::string, std::string>& HttpResponse::getHeaders() const {
    return headers;
}

const std::vector<char>& HttpResponse::getBody() const {
    return body;
}