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
    HttpRequest();
    ~HttpRequest() = default;
    void parse(const std::string &data);
    std::string getPath() const;
    std::string getMethod() const;
    std::string getVersion() const;
    std::string getHeader(std::string key) const;
    std::vector<char> getBody() const;

    bool isParse();

    void print();

private:
    void parseRequestLine(const std::string &line);
    void parseHeader(const std::string &line);
    void parseBody(const std::string &line);
    enum class State {
        START,
        HEADERS,
        BODY,
        END
    };
    State state;         // 解析状态
    std::string method;  // 请求方法
    std::string url;     // 请求路径
    std::string version; // http版本
    std::unordered_map<std::string, std::string> posts;
    std::vector<char> body;
    int contentLength;
    int bodyLength;
    bool parsed;
};