/*********************************************
 * @FileName: HttpResponse.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:32:54 2024
 * @Descript:
 */
#include <map>
#include <string>
#include <vector>


// 构造响应
class HttpResponse {
public:
    HttpResponse(int statusCode, const std::map<std::string, std::string>& headers, const std::vector<char>& body);

    int getStatusCode() const;
    const std::map<std::string, std::string>& getHeaders() const;
    const std::vector<char>& getBody() const;

private:
    int statusCode;
    std::map<std::string, std::string> headers;
    std::vector<char> body;
};
