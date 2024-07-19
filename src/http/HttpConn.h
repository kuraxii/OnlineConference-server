/*********************************************
 * @FileName: HttpConn.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 19:30:04 2024
 * @Descript:
 */

/* 设计思路  不支持长连接，只保存 ip port用于提供连接索引
    数据报头

    body 采用protobuf解析
*/
#pragma once

#include <map>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <atomic>
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "TypeDef.h"
#include <memory>
#include "../buffer/buffer.h"
class HttpConn {
public:
    HttpConn();
    HttpConn(int fd, const Address &addr);
    ~HttpConn();

    HttpConn(HttpConn &&other) noexcept = default;
    HttpConn &operator=(HttpConn &&other) noexcept;

    void init(int sockFd, const Address &addr);
    void read();
    void write();
    void close();
    int getFd() const;
    short getPort() const;
    const char *getIp() const;
    const Address &getAddr() const;
    static std::atomic<int> userCount;

private:
    int fd_;
    Address address_;

    std::unique_ptr<Buffer> buffer_;

    // HttpRequest request;
    // HttpResponse response;
};