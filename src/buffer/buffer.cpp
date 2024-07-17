/*********************************************
 * @FileName: buffer.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 15:25:34 2024
 * @Descript: 双端缓冲区
 */

#include "buffer.h"
#include <unistd.h>

Buffer::Buffer(int size)
{
    readBuff.reserve(size);
    writeBuff.reserve(size);
}

size_t Buffer::readByFd(int fd)
{
    int ret;
    char buff[65536];

    if ((ret = read(fd, buff, sizeof(buff))) <= 0) {
        return ret;
    }
    if (readBuff.capacity() - readBuff.size() < ret) {
        readBuff.reserve(readBuff.capacity() + ret);
    }

    readBuff.insert(readBuff.end(), buff, buff + ret);
    return ret;
}
size_t Buffer::writeByFd(int fd)
{
    ssize_t len = write(fd, writeBuff.data(), writeBuff.size());
    return len;
}

void Buffer::append(const char *s, size_t len)
{
    if (writeBuff.capacity() - writeBuff.size() < len) {
        writeBuff.reserve(writeBuff.size() + len);
    }
    writeBuff.insert(writeBuff.end(), s, s + len);
}

void Buffer::append(std::vector<char> s)
{
    append(s.data(), s.size());
}

void Buffer::clear()
{
    readBuff.clear();
    writeBuff.clear();
}