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
#include "../template/template.hpp"
#include <mutex>
#include <memory>
#include "kuraxii_utils/utils/list/atomic_list.h"
#include "kuraxii_utils/utils/map/AtomicUnorderedMap.h"
class GlobalResourceManager : public Singleton<GlobalResourceManager> {
    friend class Singleton<GlobalResourceManager>;

public:
    void addHttpConn(int fd, std::shared_ptr<HttpConn>);
    void removeHttpConn(int fd);
    void addTask(kuraxii::Task &task);

private:
    GlobalResourceManager();
    ~GlobalResourceManager() = default;
    kuraxii::AtomicUnorderedMap<int, std::shared_ptr<HttpConn>> allHttpConn; // 保存所有的http连接
    kuraxii::AtomicList<std::shared_ptr<ConferenceManager>> allConferenceManager;
    UDPManager udpUDPManager;
    kuraxii::ThreadPool threadPool;

    std::mutex mutex;
};
