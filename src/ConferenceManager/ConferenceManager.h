/*********************************************
 * @FileName: ConferenceManager.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 14 20:13:56 2024
 * @Descript:  会议管理类
 */

#include <list>
#include <atomic>
#include <mutex>
#include "../http/HttpConn.h"
#include "kuraxii_utils/utils/queue/AtomicQueue.h"
#include "kuraxii_utils/utils/task/task.h"
class ConferenceManager {
public:
    explicit ConferenceManager(int nudp = 3) {
    }

    void run();
    void addMember(std::shared_ptr<HttpConn> &);
    void addTask();
    void delMember(Address);
    void removeAll();

private:
    std::atomic<int> next_udp_index_; // 下一个udp描述符的索引 按会议为一组分配端口实现负载均衡
    int max_udp_index_;               // 最大udp号
    std::list<std::shared_ptr<HttpConn>> httpConns_; // 当前会议所有的http
    KURAXII::AtomicQueue<KURAXII::Task> task;
    std::mutex mutex;
};