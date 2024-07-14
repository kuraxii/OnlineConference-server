/*********************************************
 * @FileName: ConferenceManager.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 14 20:13:56 2024
 * @Descript:  会议管理类
 */

#include <vector>
#include <atomic>
class ConferenceManager {
public:
    explicit ConferenceManager(int nudp = 3)
    {
    }

    void run();
    bool addFd(); // 添加成员 使用http协议向客户端发送响应的udp的端口
    bool removeFd(); // 删除成员

private:
    std::atomic<int> next_udp_index; // 下一个udp描述符的索引 按会议为一组分配端口实现负载均衡
    int max_udp_index; // 最大udp号
    std::vector<int> fds;           // 当前会议所有的文件描述符
    std::vector<int> udps;          // udp文件描述符  默认3个
};