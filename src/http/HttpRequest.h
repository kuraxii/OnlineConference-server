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
    virtual ~HttpRequest() = default;

    std::string getPath() const;
    std::string getMethod() const;
    std::string getVersion() const;
    std::string getHeader(std::string key) const;
    std::vector<char> getPost() const;
    bool isParsed();
    bool isPost();
    void print();
    void parse(const std::vector<char> &data);

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
    State requestState;          // 解析状态
    std::string requestMethod_;  // 请求方法
    std::string requestUrl_;     // 请求路径
    std::string requestVersion_; // http版本
    std::unordered_map<std::string, std::string> requestHeaders_;
    std::vector<char> requestPost_;
    int requestContentLength_;
    int requestBodyLength_;
    bool requestParsed_;
};