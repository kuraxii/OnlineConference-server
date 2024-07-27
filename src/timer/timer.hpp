/*********************************************
 * @FileName: heaptimer.hpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周六 7月 27 15:24:37 2024
 * @Descript:
 */
#include <iostream>
#include <queue>
#include <chrono>
#include <thread>
#include <functional>
#include <vector>
#include <map>

struct timer_context {
    struct _timer_entry {
        std::function<void()> m_cb;
    };

    std::multimap<std::chrono::steady_clock::time_point, _timer_entry> m_timer_heap;

    timer_context() = default;
    timer_context(timer_context &&) = delete;

    void set_timeout(std::chrono::steady_clock::duration dt, std::function<void()> cb) {
        auto expire_time = std::chrono::steady_clock::now() + dt;
        auto it = m_timer_heap.insert({expire_time, _timer_entry{cb}});
    }

    std::chrono::steady_clock::duration duration_to_next_timer() {
        while (!m_timer_heap.empty()) {
            auto it = m_timer_heap.begin();
            auto now = std::chrono::steady_clock::now();
            if (it->first <= now) {
                auto cb = it->second.m_cb;
                m_timer_heap.erase(it);
                cb();
            } else {
                return it->first - now;
            }
        }
        return std::chrono::nanoseconds(-1);
    }

    bool is_empty() const {
        return m_timer_heap.empty();
    }
};
