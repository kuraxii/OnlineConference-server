#include <gtest/gtest.h>
#include <iostream>
#include <test.pb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../src/http/HttpConn.h"
#include "../src/epoll/epoll.h"

#include "../src/http/HttpRequest.hpp"

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

void testepoll() {
    int fd = createSocket();
    EPOLL ep{128};
    ep.addFd(fd, EPOLLIN | EPOLLET);
    ep.wait();

    printf("epoll\n");
}

void testProtobuf() {
    // packet::Message msg;
    // msg.set_ip("192.168.1.1");
    // msg.set_port(8080);
    // msg.set_body("This is the body data");

    // // 序列化到字符串
    // std::string serialized_data;
    // if (!msg.SerializeToString(&serialized_data)) {
    //     std::cerr << "Failed to serialize data." << std::endl;
    //     return;
    // }

    // // 反序列化
    // packet::Message new_msg;
    // if (!new_msg.ParseFromString(serialized_data)) {
    //     std::cerr << "Failed to parse data." << std::endl;
    //     return;
    // }

    // // 输出反序列化后的数据
    // std::cout << "IP: " << new_msg.ip() << std::endl;
    // std::cout << "Port: " << new_msg.port() << std::endl;
    // std::cout << "Body: " << new_msg.body() << std::endl;
}

void httpTest() {
    std::string request_data = "POST /submit HTTP/1.1\r\n"
                               "Host: www.example.com\r\n"
                               "Connection: keep-alive\r\n"
                               "Content-Length: 13\r\n"
                               "\r\n"
                               "Hello, World!";
    HttpRequest parser;
    parser.reset_state();
    parser.push_chunk(std::vector<char>{request_data.begin(), request_data.end()});
    parser.print();
}

// TEST(SocketTest, CreateSocket) {
//     int fd = createSocket();
//     ASSERT_GT(fd, 0);
// }

// TEST(EpollTest, EpollFunction) {
//     EXPECT_NO_THROW(testepoll());
// }

// TEST(ProtobufTest, ProtobufSerialization) {
//     packet::Message msg;
//     msg.set_ip("192.168.1.1");
//     msg.set_port(8080);
//     msg.set_body("This is the body data");

// std::string serialized_data;
// ASSERT_TRUE(msg.SerializeToString(&serialized_data));

// packet::Message new_msg;
// ASSERT_TRUE(new_msg.ParseFromString(serialized_data));
// EXPECT_EQ(new_msg.ip(), "192.168.1.1");
// EXPECT_EQ(new_msg.port(), 8080);
// EXPECT_EQ(new_msg.body(), "This is the body data");
// }

TEST(HttpTest, HttpRequestParsing) {
    std::string request_data1 = "POST /submit HTTP/1.1\r\n"
                                "Host: www.example.com\r\n"
                                "Connection: keep-alive\r\n";

    std::string request_data2 = "Content-Length: 13\r\n"
                                "\r\n"
                                "Hello, World!";
    HttpRequest parser;
    parser.reset_state();
    parser.push_chunk(std::vector<char>{request_data1.begin(), request_data1.end()});
    parser.push_chunk(std::vector<char>{request_data2.begin(), request_data2.end()});
    EXPECT_EQ(parser.method(), "POST");
    EXPECT_EQ(parser.url(), "/submit");

    EXPECT_EQ(parser.header_keys()["host"], "www.example.com");
    EXPECT_EQ(parser.header_keys()["connection"], "keep-alive");
    EXPECT_EQ(parser.header_keys()["content-length"], "13");
    // EXPECT_EQ(parser.getBody(), "Hello, World!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
