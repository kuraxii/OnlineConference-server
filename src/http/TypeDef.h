/*********************************************
 * @FileName: TypeDef.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 14:34:02 2024
 * @Descript:
 */

#pragma once
#include "string"

struct Address {
    int fd;
    std::string ip;
    u_int16_t port;
    std::string pass = "";

    bool operator==(const Address &other) const {
        return (ip == other.ip) && (port == other.port);
    }
};