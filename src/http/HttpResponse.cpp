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
HttpResponse &HttpResponse::setStatusCode(int code)
{
    statuscode_ = code;
    return *this;
}

HttpResponse &HttpResponse::setContentType(HttpResponseHeaderContentType contentType)
{
    headers_["Content-Type"] = std::string(CONTENTTYPE.at(static_cast<int>(contentType)));
    return *this;
}
HttpResponse &HttpResponse::setContentLength(int len)
{
    headers_["Content-Length"] = std::to_string(len);
    return *this;
}

HttpResponse &HttpResponse::setBody(const char *data, size_t len)
{
    body_.insert(body_.begin(), data, data + len);
    return *this;
}

std::string &HttpResponse::toResponse()
{
    response = "HTTP/1.1 " + std::to_string(statuscode_) + CODE_STATUS.find(statuscode_)->second + "\r\n";
    for (const auto &it : headers_) {
        response += it.first + ':' + it.second + "\r\n";
    }
    response += "\r\n\r\n";
    response.append(body_.data(), body_.size());
    return response;
}