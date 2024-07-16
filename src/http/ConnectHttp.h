/*********************************************
 * @FileName: http.h
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

class HttpConn {
public:
    HttpConn();

    ~HttpConn();

    void init(int sockFd, const sockaddr &addr);

    ssize_t read(int *saveErrno);

    ssize_t write(int *saveErrno);

    void Close();

    int GetFd() const;

    int GetPort() const;

    const char *GetIP() const;

    sockaddr GetAddr() const;

    bool process();

    int ToWriteBytes()
    {
        return iov[0].iov_len + iov[1].iov_len;
    }

    static bool isET;
    static const char *srcDir;
    static std::atomic<int> userCount;

private:
    int fd_;
    std::string ip;
    short port;

    bool isClose;

    int iovCnt;
    struct iovec iov[2];

    // Buffer readBuff_;  // 读缓冲区
    // Buffer writeBuff_; // 写缓冲区

    HttpRequest request_;
    HttpResponse response_;
};
