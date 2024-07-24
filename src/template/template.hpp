/*********************************************
 * @FileName: template.hpp
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周日 7月 21 16:38:21 2024
 * @Descript:
 */

#pragma once

template <typename T>
class Singleton {
public:
    static T &getInstance() {
        static T value_; // 静态局部变量
        return value_;
    }

protected:
    Singleton();
    ~Singleton();

private:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(Singleton &&) = delete;
};