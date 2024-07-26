/*********************************************
 * @FileName: TypeDef.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 14:34:02 2024
 * @Descript:
 */

#pragma once
#include "string"
#include <unistd.h>
struct file_descriptor {
    int m_fd = -1;

    file_descriptor() = default;

    explicit file_descriptor(int fd) : m_fd(fd) {
    }

    file_descriptor(file_descriptor &&that) noexcept : m_fd(that.m_fd) {
        that.m_fd = -1;
    }

    file_descriptor &operator=(file_descriptor &&that) noexcept {
        std::swap(m_fd, that.m_fd);
        return *this;
    }

    ~file_descriptor() {
        if (m_fd == -1) {
            return;
        }
        close(m_fd);
    }
};

struct Address {
    int fd;
    std::string ip;
    u_int16_t port;
    std::string pass = "";

    bool operator==(const Address &other) const {
        return (ip == other.ip) && (port == other.port);
    }
};