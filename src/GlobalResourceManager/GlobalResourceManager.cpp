/*********************************************
 * @FileName: GlobalResourceManager.cpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 21 23:17:22 2024
 * @Descript:
 */

#include "GlobalResourceManager.h"

GlobalResourceManager::GlobalResourceManager() {
    threadPool.init();
}

void GlobalResourceManager::addHttpConn(std::shared_ptr<HttpConn> conn) {
    allHttpConn.push_back(conn);
}

void GlobalResourceManager::addTask(KURAXII::Task &&task) {
    threadPool.addTask(std::move(task));
}
