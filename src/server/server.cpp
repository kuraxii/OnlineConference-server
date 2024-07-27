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
#include "../protobuf/message_info.pb.h"

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

    epoll.addFd(lfd, EPOLLIN | EPOLLET);
}

int server::run() {
    int ret;
    while (1) {
        // 删除或读取最近的定时节点
        auto dt = timer.duration_to_next_timer();
        std::chrono::milliseconds ms{-1};
        if (dt.count() >= 0) {
            ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt);
        }
        if ((ret = epoll.wait(ms.count())) < 0) {
            perror("epool.wait...");
        }

        for (int i = 0; i < ret; i++) {
            /* 处理事件 */
            int fd = epoll.getFd(i);
            uint32_t events = epoll.getEvent(i);
            if (fd == lfd) {
                do_listen();
            } else if (events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR)) { // 异常
                do_close(fd);
            } else if (events & EPOLLIN) {

                kuraxii::Task task{std::bind(&server::do_read, this, fd)};
                GlobalResourceManager::getInstance().addTask(task);
            }
        }
    }
}

void server::do_listen() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int fd = accept(lfd, (struct sockaddr *)&addr, &len);
    Address address{fd, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port)};
    std::shared_ptr<HttpConn> conn = std::make_shared<HttpConn>(fd, address);

    unassignedHttpConnections.insert(fd, conn);
    GlobalResourceManager::getInstance().addHttpConn(fd, conn);
}

void server::do_read(int fd) {
    // 注意：TCP 基于流，可能粘包
    // fmt::println("开始读取...");
    // 设置一个 3 秒的定时器，若 3
    // 秒内没有读到任何请求，则视为对方放弃，关闭连接
    auto conn = unassignedHttpConnections.get(fd);
    assert(conn != std::nullopt);
    if ((*conn)->request_finished()) {
        (*conn)->reset_state();
        timer.set_timeout(std::chrono::seconds(3), [=] { (*conn)->reset_state(); });
    }
    (*conn)->read();
    (*conn)->parse();

    // if ((*conn)->method() != "POST") {
    //     // debug
    //     return;
    // } else {
    // }

    if ((*conn)->request_finished()) {
        message_info::MessageInfo msg;
        msg.ParseFromArray((*conn)->body().data(), (*conn)->body().size());
        // if()
        // {

        // }
    }
}

void server::do_close(int fd) {
    unassignedHttpConnections.remove(fd);
    GlobalResourceManager::getInstance().removeHttpConn(fd);
}
