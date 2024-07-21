/*********************************************
 * @FileName: server.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 21 17:06:50 2024
 * @Descript:
 */
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "server.h"
#include "../http/TypeDef.h"
#include "../GlobalResourceManager/GlobalResourceManager.h"

server::server() {
}

void server::init(int ip, unsigned short port) {
    int err;
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd <= 0) {
        exit(-1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = ip;
    err = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
    if (err <= 0) {
        exit(-1);
    }
    err = listen(lfd, 255);
    if (err < 0) {
        exit(-1);
    }

    epoll.addFd(lfd, EPOLLIN);
}

int server::run() {
    int ret;
    while (1) {
        if ((ret = epoll.wait()) < 0) {
            perror("epool.wait...");
        }

        for (int i = 0; i < ret; i++) {
            /* 处理事件 */
            int fd = epoll.getFd(i);
            uint32_t events = epoll.getEvent(i);
            if (fd == lfd) {
                dealListen();
            } else if (events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR)) { // 异常
                closeConn(fd);
            } else if (events & EPOLLIN) {

                std::function<void()> func = std::bind(&server::dealRead, this, fd);
                KURAXII::Task task{std::move(func)};
                Singleton<GlobalResourceManager>::getInstance().addTask(std::move(task));
            } else if (events & EPOLLOUT) {
                dealWrite(fd);
            }
        }
    }
}

void server::dealListen() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int fd = accept(lfd, (struct sockaddr *)&addr, &len);
    Address address{fd, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port)};
    std::shared_ptr<HttpConn> conn = std::make_shared<HttpConn>(fd, address);
    httpClinets.push_back(conn);
    Singleton<GlobalResourceManager>::getInstance();
}

void server::dealRead(int fd) {
}