/*********************************************
 * @FileName: epoll.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 21:39:47 2024
 * @Descript:
 */
#include <assert.h>
#include "epoll.h"
EPOLL::EPOLL(int maxFd) : epfd(epoll_create(maxFd)), events(maxFd) {
    assert(epfd >= 0 && events.size() > 0);
}
EPOLL::~EPOLL() {
    ::close(epfd);
}

bool EPOLL::addFd(int fd, uint32_t events) {
    epoll_event ev = {0};
    ev.data.fd = fd;
    ev.events = events;
    return 0 == epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
}

bool EPOLL::modFd(int fd, uint32_t events) {
    epoll_event ev = {0};
    ev.data.fd = fd;
    ev.events = events;
    return 0 == epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
}

bool EPOLL::delFd(int fd) {
    epoll_event ev = {0};
    return 0 == epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
}

int EPOLL::getFd(size_t i) const {
    return events[i].data.fd;
}

uint32_t EPOLL::getEvent(size_t i) const {
    return events[i].events;
}

int EPOLL::wait(int timeoutMs) {
    return epoll_wait(epfd, &events[0], static_cast<int>(events.size()), timeoutMs);
}