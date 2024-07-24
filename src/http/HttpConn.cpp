/*********************************************
 * @FileName: HttpConn.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 14 20:15:16 2024
 * @Descript: libcurl 的http封装
 */

#include <sstream>
#include <curl/curl.h>
#include <sstream>
#include <unistd.h>
#include <assert.h>
#include "HttpConn.h"

std::atomic<int> HttpConn::userCount = 0;

HttpConn::HttpConn() : fd_(-1), address_({-1, "0.0.0.0", 0}), buffer_(std::make_unique<Buffer>()) {
}
HttpConn::HttpConn(int fd, const Address &addr) : fd_(-1), address_(addr), buffer_(std::make_unique<Buffer>()) {
}
HttpConn::~HttpConn() {
    close();
}

void HttpConn::close() {
    ::close(fd_);
}

int HttpConn::getFd() const {
    return fd_;
}

const Address &HttpConn::getAddr() const {
    return address_;
}

const char *HttpConn::getIp() const {
    return address_.ip.c_str();
}

short HttpConn::getPort() const {
    return address_.port;
}

void HttpConn::read() {
    ssize_t ret = -1;
    do {
        ret = buffer_->readByFd(fd_);
        if (ret <= 0) {
            break;
        }
    } while (1);
}

void HttpConn::toResponse() {
    HttpResponse::toResponse(buffer_->getWriteBuff());
}

void HttpConn::parse() {
    HttpRequest::parse(buffer_->getReadBuff());
}