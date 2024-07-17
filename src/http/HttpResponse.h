/*********************************************
 * @FileName: HttpResponse.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:32:54 2024
 * @Descript:
 */

#pragma once
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

enum class HttpResponseHeaderContentType {
    MESSAGE = 0,
    IMAGE,
    CONTROL
};

// 构造响应
class HttpResponse {
public:
    HttpResponse();
    int getStatusCode() const;
    HttpResponse &setStatusCode(int code);
    HttpResponse &setContentType(HttpResponseHeaderContentType contentType);
    HttpResponse &setContentLength(int len);
    HttpResponse &setBody(const char *, size_t len);
    std::string &toResponse();

private:
    int statuscode_;
    std::map<std::string, std::string> headers_;
    std::vector<char> body_;
    std::string response;
    static const std::vector<const char *> CONTENTTYPE;
    static const std::vector<const char *> KEY;
    static const std::vector<const char *> HTTPRESPONSEHEADER;
    static const std::unordered_map<int, std::string> CODE_STATUS;
};