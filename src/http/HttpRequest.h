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
#include <unordered_map>

// 解析请求
class HttpRequest {
public:
    void parse(std::string str);
    const std::string &get_url() const;
    const std::map<std::string, std::string> &get_headers() const;
    const std::vector<char> &get_Body() const;

private:
    std::unordered_map<std::string, std::string> header_;
    std::unordered_map<std::string, std::string> post_;
};