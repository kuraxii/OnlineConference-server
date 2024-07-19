#include <iostream>
#include <test.pb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../src/http/HttpConn.h"
#include "../src/epoll/epoll.h"
#include "../src/protobuf/message.pb.h"

void sys_err(const char *str) {
    perror(str);
    exit(1);
}
int createSocket() {

    int ret;
    char buf[1024];
    int lfd, ser_fd;
    struct sockaddr_in ser_addr, c_addr;

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) {
        sys_err("socket err");
    }

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(12500);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ret = bind(lfd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
    if (ret == -1) {
        sys_err("bind err");
    }

    ret = listen(lfd, 255);
    if (ret == -1) {
        sys_err("listen err");
    }

    socklen_t cli_addr_len = sizeof(c_addr);
    ser_fd = accept(lfd, (struct sockaddr *)&c_addr, &cli_addr_len);
    if (ser_fd == -1) {
        sys_err("accept err");
    }
    printf("client connect success: ip = %s port = %d\n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port));
    return ser_fd;
}

int main() {

    // Person p;
    // p.set_age(32);
    // p.set_id(12345);
    // p.set_name("zzj");
    // p.set_sex("xy");

    // std::string str;
    // p.SerializeToString(&str);

    // std::cout << str << std::endl;
    // UDPManager::getInstance();

    // HttpConn client;

    // Perform a GET request

    // // Perform a POST request with binary data
    // std::vector<char> postData = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; // "Hello" in binary
    // HttpRequest postRequest("http://www.example.com", {{"Content-Type", "application/octet-stream"}}, postData);
    // HttpResponse postResponse = client.post(postRequest);
    // std::cout << "POST Response Status: " << postResponse.getStatusCode() << std::endl;
    // std::cout << "POST Response Body: " << std::string(postResponse.getBody().begin(), postResponse.getBody().end())
    //           << std::endl;

    // while (1) {
    //     sleep(1);
    // }

    // int fd = createSocket();
    // EPOLL ep{128};
    // ep.addFd(fd, EPOLLIN | EPOLLET);
    // ep.wait();

    // printf("epoll\n");

    packet::Message msg;
    msg.set_ip("192.168.1.1");
    msg.set_port(8080);
    msg.set_body("This is the body data");

    // 序列化到字符串
    std::string serialized_data;
    if (!msg.SerializeToString(&serialized_data)) {
        std::cerr << "Failed to serialize data." << std::endl;
        return -1;
    }

    // 反序列化
    packet::Message new_msg;
    if (!new_msg.ParseFromString(serialized_data)) {
        std::cerr << "Failed to parse data." << std::endl;
        return -1;
    }

    // 输出反序列化后的数据
    std::cout << "IP: " << new_msg.ip() << std::endl;
    std::cout << "Port: " << new_msg.port() << std::endl;
    std::cout << "Body: " << new_msg.body() << std::endl;

    return 0;
}