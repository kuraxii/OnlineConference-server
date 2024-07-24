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

void GlobalResourceManager::addHttpConn(int fd, std::shared_ptr<HttpConn> conn) {
    allHttpConn.insert(fd, conn);
}

void GlobalResourceManager::addTask(KURAXII::Task &task) {
    threadPool.addTask(task);
}
