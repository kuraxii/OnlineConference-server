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

class UDPManager {
public:
    static UDPManager &getInstance(int max_udp_index = 10);
    std::pair<std::string, int> getIpPort(int index) const;
    int getSocketFd(int index) const;

private:
    UDPManager(int max_udp_index);
    ~UDPManager();
    bool createSocket();
    UDPManager(const UDPManager &) = delete;
    UDPManager &operator=(const UDPManager &) = delete;

    int max_udp_index;
    std::vector<int> sockets;
    std::unordered_map<int, std::pair<std::string, int>> index_to_ipport;
    mutable std::mutex mtx;
};

class TCPServer {
public:
    TCPServer(const std::string &ip, int port);
    ~TCPServer();

    bool start();
    int acceptConnection();
    ssize_t sendMessage(int client_fd, const std::string &message);
    ssize_t receiveMessage(int client_fd, std::string &message);

private:
    std::string ip;
    int port;
    int server_fd;
    struct sockaddr_in server_addr;
};