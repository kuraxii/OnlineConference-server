/*********************************************
 * @FileName: epoll.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 21:39:50 2024
 * @Descript:
 */

#include <sys/epoll.h>
#include <vector>
#include <unistd.h>
class EPOLL {
public:
    explicit EPOLL(int maxEvent = 128);
    ~EPOLL();

    int wait(int timeoutMs = -1);
    bool addFd(int fd, uint32_t events);

    bool modFd(int fd, uint32_t events);

    bool delFd(int fd);

    int getFd(size_t i) const;

    uint32_t getEvent(size_t i) const;

private:
    int is_init;
    int epfd;
    std::vector<struct epoll_event> events;
};