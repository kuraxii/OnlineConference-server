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
#include "../timer/timer.hpp"
#include "kuraxii_utils/utils/map/AtomicUnorderedMap.h"
class server {
public:
    server();
    void init(int ip = INADDR_ANY, unsigned short port = 8888);
    int run();
    void do_listen();
    void do_close(int fd);
    void do_read(int fd);
    void dealWrite(int fd);

private:
    int lfd;
    timer_context timer;
    EPOLL epoll;
    kuraxii::AtomicUnorderedMap<int, std::shared_ptr<HttpConn>> unassignedHttpConnections;
};
