/*********************************************
 * @FileName: HttpRequest.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:33:51 2024
 * @Descript:
 */

#include "HttpRequest.h"
HttpRequest::HttpRequest(const std::string &url, const std::map<std::string, std::string> &headers,
                         const std::vector<char> &body)
    : url(url), headers(headers), body(body)
{
}

const std::string &HttpRequest::getUrl() const
{
    return url;
}

const std::map<std::string, std::string> &HttpRequest::getHeaders() const
{
    return headers;
}

const std::vector<char> &HttpRequest::getBody() const
{
    return body;
}