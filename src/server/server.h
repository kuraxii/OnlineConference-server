/*********************************************
 * @FileName: server.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 21 16:26:00 2024
 * @Descript:
 */

#pragma once
#include <list>
#include <arpa/inet.h>
#include <memory>
#include "../epoll/epoll.h"
#include "../http/HttpConn.h"
#include "../template/template.hpp"
class server {
public:
    server();
    void init(int ip = INADDR_ANY, unsigned short port = 8888);
    int run();
    void dealListen();
    void closeConn(int fd);
    void dealRead(int fd);
    void dealWrite(int fd);

private:
    int lfd;
    EPOLL epoll;
    std::unordered_map<int, std::shared_ptr<HttpConn>> unassignedHttpConnections;
};
