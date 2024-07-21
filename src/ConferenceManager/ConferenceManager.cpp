/*********************************************
 * @FileName: ConferenceManager.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周三 7月 17 20:35:56 2024
 * @Descript:
 */

#include "ConferenceManager.h"

void ConferenceManager::addMember(std::shared_ptr<HttpConn> &member) {

    httpConns_.push_back(member);
}

void ConferenceManager::delMember(Address addr) {
    std::lock_guard<std::mutex> lock(mutex);

    auto it = httpConns_.begin();
    while (it != httpConns_.end()) {
        if ((*it)->getAddr() == addr) {
            httpConns_.erase(it);
            break;
        }
        it++;
    }
}

void ConferenceManager::removeAll() {
    std::lock_guard<std::mutex> lock(mutex);

    auto it = httpConns_.begin();
    while (it != httpConns_.end()) {
        it = httpConns_.erase(it);
    }
}
