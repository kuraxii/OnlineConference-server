/*********************************************
 * @FileName: GlobalResourceManager.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 22:01:26 2024
 * @Descript:
 */

#pragma once
#include "../http/HttpConn.h"
#include "udp.h"
#include "../ConferenceManager/ConferenceManager.h"
#include <list>
#include "kuraxii_utils/utils/threadpool/ThreadPool.h"
#include <mutex>
#include <memory>
class GlobalResourceManager {
public:
    GlobalResourceManager();
    void addHttpConn(int fd, std::shared_ptr<HttpConn>);
    void addTask(KURAXII::Task &task);

private:
    std::unordered_map<int, std::shared_ptr<HttpConn>> allHttpConn; // 保存所有的http连接
    std::list<std::shared_ptr<ConferenceManager>> allConferenceManager;
    UDPManager udpUDPManager;
    KURAXII::ThreadPool threadPool;

    std::mutex mutex;
};
