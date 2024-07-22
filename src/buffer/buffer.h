/*********************************************
 * @FileName: buffer.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 15:25:39 2024
 * @Descript:
 */
#pragma once
#include <vector>

class Buffer {
public:
    Buffer(int size = 512);
    ~Buffer() = default;
    size_t readByFd(int fd);
    size_t writeByFd(int fd);
    void append(const char *, size_t len);
    void append(std::vector<char>);
    void clear();



    void getReadBuff();
    void getWriteBuff();
private:
    std::vector<char> readBuff;
    std::vector<char> writeBuff;
};