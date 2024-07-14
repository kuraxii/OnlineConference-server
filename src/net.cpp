/*********************************************
 * @FileName: net.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 14 20:14:12 2024
 * @Descript: 网络相关组件
 */
#include "net.h"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

UDPManager &UDPManager::getInstance(int max_udp_index)
{
    static UDPManager instance(max_udp_index);
    return instance;
}

UDPManager::UDPManager(int max_udp_index) : max_udp_index(max_udp_index)
{
    sockets.resize(max_udp_index, -1);
    createSocket();
}

UDPManager::~UDPManager()
{
    for (int sockfd : sockets) {
        if (sockfd != -1) {
            close(sockfd);
        }
    }
}

bool UDPManager::createSocket()
{
    std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < max_udp_index; ++i) {
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            std::cerr << "Socket creation failed for index " << i << std::endl;
        } else {
            struct sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(0); // 端口号设为0，系统将随机分配端口
            server_addr.sin_addr.s_addr = INADDR_ANY;

            if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                std::cerr << "Bind failed for socket at index " << i << std::endl;
                close(sockfd);
            } else {
                struct sockaddr_in bound_addr;
                socklen_t addr_len = sizeof(bound_addr);
                if (getsockname(sockfd, (struct sockaddr *)&bound_addr, &addr_len) == -1) {
                    std::cerr << "getsockname failed for index " << i << std::endl;
                    close(sockfd);
                } else {
                    sockets[i] = sockfd;
                    index_to_ipport[i] = {"INADDR_ANY", ntohs(bound_addr.sin_port)};
                }
            }
        }
    }
    return true;
}

int UDPManager::getSocketFd(int index) const
{
    std::lock_guard<std::mutex> lock(mtx);
    if (index < 0 || index >= max_udp_index) {
        return -1;
    }
    return sockets[index];
}

// 获取ip与端口号
std::pair<std::string, int> UDPManager::getIpPort(int index) const
{
    std::lock_guard<std::mutex> lock(mtx);
    auto it = index_to_ipport.find(index);
    if (it != index_to_ipport.end()) {
        return it->second;
    }
    return {"", -1};
}

TCPServer::TCPServer(const std::string &ip, int port) : ip(ip), port(port), server_fd(-1)
{
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    server_addr.sin_port = htons(port);
}

TCPServer::~TCPServer()
{
    if (server_fd != -1) {
        close(server_fd);
    }
}

bool TCPServer::start()
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed." << std::endl;
        return false;
    }

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed." << std::endl;
        close(server_fd);
        return false;
    }

    if (listen(server_fd, 5) < 0) {
        std::cerr << "Listen failed." << std::endl;
        close(server_fd);
        return false;
    }

    std::cout << "Server started at " << ip << ":" << port << std::endl;
    return true;
}

int TCPServer::acceptConnection()
{
    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) {
        std::cerr << "Accept failed." << std::endl;
    }
    return client_fd;
}

ssize_t TCPServer::sendMessage(int client_fd, const std::string &message)
{
    return send(client_fd, message.c_str(), message.length(), 0);
}

ssize_t TCPServer::receiveMessage(int client_fd, std::string &message)
{
    char buffer[1024];
    ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        message.assign(buffer, bytes_received);
    }
    return bytes_received;
}