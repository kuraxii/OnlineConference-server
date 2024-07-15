/*********************************************
 * @FileName: HttpRequest.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:33:13 2024
 * @Descript:
 */

#pragma once
#include <string>
#include <map>
#include <vector>

// 解析请求
class HttpRequest {
public:
    HttpRequest(const std::string &url, const std::map<std::string, std::string> &headers = {},
                const std::vector<char> &body = {});

    const std::string &getUrl() const;
    const std::map<std::string, std::string> &getHeaders() const;
    const std::vector<char> &getBody() const;

private:
    std::string url;
    std::map<std::string, std::string> headers;
    std::vector<char> body;
};