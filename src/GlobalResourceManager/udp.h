/*********************************************
 * @FileName: net.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 14 20:39:49 2024
 * @Descript:
 */
#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <mutex>
#include <netinet/in.h>
#include "../http/TypeDef.h"

class UDPManager {
public:
    UDPManager(int max_udp_index = 10);
    ~UDPManager();
    Address getIpPort(int index) const;
    int getSocketFd(int index) const;

private:
    bool createSocket();
    UDPManager(const UDPManager &) = delete;
    UDPManager &operator=(const UDPManager &) = delete;

    int max_udp_index;
    std::vector<int> sockets;
    std::unordered_map<int, Address> index_to_ipport;
    mutable std::mutex mtx;
};
