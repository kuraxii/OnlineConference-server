/*********************************************
 * @FileName: GlobalResourceManager.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 22:01:26 2024
 * @Descript:
 */

#pragma once
#include "http/HttpConn.h"
#include "udp/udp.h"
#include "ConferenceManager.h"
#include <list>
#include "kuraxii_utils/utils/threadpool/ThreadPool.h"
#include <mutex>
class GlobalResourceManager {

public:
private:
    std::list<HttpConn> httpConns;
    UDPManager udpUDPManager;
    KURAXII::ThreadPool threadPool;
    std::list<ConferenceManager> ConferenceManager;

    std::mutex mutex;
};