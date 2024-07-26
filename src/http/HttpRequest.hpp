/*********************************************
 * @FileName: HttpRequest.h
 * @Author: kuraxii
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: 周一 7月 15 22:33:13 2024
 * @Descript:
 */

#pragma once
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <assert.h>
#include <algorithm>

// 解析请求
class HttpRequest {
private:
    std::string m_header;
    std::string m_headline;
    std::unordered_map<std::string, std::string> m_header_keys;
    std::string m_body;
    size_t m_content_length;
    size_t m_body_length;
    size_t body_accumulated_size;
    bool m_header_finished = false;
    bool m_body_finished = false;

public:
    void reset_state() {
        m_header.clear();
        m_headline.clear();
        m_header_keys.clear();
        m_body.clear();
        body_accumulated_size = 0;
        m_header_finished = false;
        m_body_finished = false;
    }

    [[nodiscard]] inline bool request_finished() {
        return m_body_finished;
    }
    [[nodiscard]] inline bool header_finished() {
        return m_header_finished;
    }

    inline std::string &headline() {
        return m_headline;
    }
    inline std::string url() {
        return _headline_second();
    }
    inline std::string method() {
        return _headline_first();
    }
    inline std::unordered_map<std::string, std::string> &header_keys() {
        return m_header_keys;
    }
    inline std::string &body() {
        return m_body;
    }
    std::string &headers_raw() {
        return m_header;
    }

    void push_chunk(const std::vector<char> &chunk) {
        assert(!m_body_finished);
        if (!m_header_finished) {
            header_push_chunk(chunk);
            if (m_header_finished) {
                body_accumulated_size = m_body.size();
                m_content_length = _extract_content_length();
                if (body_accumulated_size >= m_content_length) {
                    assert(m_body.size() == m_content_length);
                    m_body_finished = true;
                }
            }
        } else {
            m_body.insert(m_body.end(), chunk.begin(), chunk.end());
            body_accumulated_size += chunk.size();
            if (body_accumulated_size >= m_content_length) {
                assert(m_body.size() == m_content_length);
                m_body_finished = true;
            }
        }
    }

    void print() {
        // std::cout << "Method: " << m_method << std::endl;
        // std::cout << "URI: " << m_url << std::endl;
        // std::cout << "Version: " << m_version << std::endl;
        std::cout << "Headers:" << std::endl;
        for (const auto &header : m_header_keys) {
            std::cout << "  " << header.first << ": " << header.second << std::endl;
        }
        std::cout << "Body: " << m_body.data() << std::endl;
    }

private:
    std::string _headline_first() {
        // "GET / HTTP/1.1" request
        // "HTTP/1.1 200 OK" response
        auto &line = headline();
        size_t space = line.find(' ');
        if (space == std::string::npos) {
            return "";
        }
        return line.substr(0, space);
    }

    std::string _headline_second() {
        // "GET / HTTP/1.1"
        auto &line = headline();
        size_t space1 = line.find(' ');
        if (space1 == std::string::npos) {
            return "";
        }
        size_t space2 = line.find(' ', space1 + 1);
        if (space2 == std::string::npos) {
            return "";
        }
        return line.substr(space1 + 1, space2 - (space1 + 1));
    }

    std::string _headline_third() {
        // "GET / HTTP/1.1"
        auto &line = headline();
        size_t space1 = line.find(' ');
        if (space1 == std::string::npos) {
            return "";
        }
        size_t space2 = line.find(' ', space1 + 1);
        if (space2 == std::string::npos) {
            return "";
        }
        return line.substr(space2);
    }

    size_t _extract_content_length() {
        auto &headers = header_keys();
        auto it = headers.find("content-length");
        if (it == headers.end()) {
            return 0;
        }
        try {
            return std::stoi(it->second);
        }
        catch (std::logic_error const &) {
            return 0;
        }
    }
    std::string &to_lowercase(std::string &str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
        return str;
    }
    void _extract_headers() {
        std::string_view header = m_header;
        size_t pos = header.find("\r\n", 0);

        if (pos == std::string_view::npos) {
            // 处理没有找到 "\r\n" 的情况
            // 可以根据具体需求抛出异常或进行其他处理
            return;
        }
        // 跳过 "\r\n"
        size_t line_start = pos + 2;
        m_headline = std::string(header.substr(0, pos));

        while ((pos = header.find("\r\n", line_start)) != std::string_view::npos) {
            size_t line_len = pos - line_start;

            std::string_view line = header.substr(line_start, line_len);
            size_t colon = line.find(": ", 0);
            if (colon != std::string_view::npos) {
                std::string key = std::string(line.substr(0, colon));
                std::string_view value = line.substr(colon + 2);
                // 转小写
                to_lowercase(key);
                m_header_keys.insert_or_assign(std::move(key), value);
            }

            line_start = pos + 2;
        }
    }
    void header_push_chunk(const std::vector<char> &chunk) {
        assert(!m_header_finished);
        size_t old_size = m_header.size();
        m_header.insert(m_header.end(), chunk.begin(), chunk.end());
        std::string_view header = m_header;
        // 如果还在解析头部的话，尝试判断头部是否结束
        if (old_size < 4) {
            old_size = 4;
        }
        old_size -= 4;
        size_t header_len = header.find("\r\n\r\n", old_size, 4);
        if (header_len != std::string::npos) {
            // 头部已经结束
            m_header_finished = true;
            // 把不小心多读取的正文留下
            m_body = header.substr(header_len + 4);
            m_header.resize(header_len + 2);
            // 开始分析头部，尝试提取 Content-length 字段
            _extract_headers();
        }
    }
};