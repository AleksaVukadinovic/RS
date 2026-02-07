#pragma once
#include <memory>
#include <iostream>
#include <ostream>

namespace matf {

    class List {
    private:
        struct Element {
            int m_value;
            std::unique_ptr<Element> m_next;

            Element(int value = 0, std::unique_ptr<Element> next = nullptr)
                : m_value(value), m_next(std::move(next)) {
            }
        };

        size_t m_size = 0u;
        std::unique_ptr<Element> m_start = nullptr;

    public:
        List() = default;

        // 1) Copy constructor
        List(const List &other): m_size(0u) {
             for (auto i =  0u; i<other.m_size; ++i) {
                 push_back(other[i]);
             }
        }

        // 2) Assign operator
        List &operator=(const List& other) {
            // "Copy and swap"
            auto tmp(other);
            std::swap(tmp.m_start, m_start);
            std::swap(tmp.m_size, m_size);
            return *this;
        }

        ~List() {
            while (m_start) pop_front();
        }

        void push_back(const int x) {
           auto new_element = std::make_unique<Element>(x);
           if (new_element == nullptr) {
               m_start = std::move(new_element);
           } else {
               auto element = m_start.get();
               while (element->m_next) {
                   element = element->m_next.get();
               }
               element->m_next = std::move(new_element);
           }
           ++m_size;
        }

        void push_front(const int x) {
            auto new_element = std::make_unique<Element>(x,std::move(m_start));
            m_start = std::move(new_element);
            ++m_size;
        }

        void pop_front() {
            if (m_size == 0u) {
                throw "Cannot pop from an empty list";
            }

            auto old_start = std::move(m_start);
            m_start = std::move(old_start->m_next);
            m_size--;
        }

        size_t size() const { return m_size; }

        int operator[](size_t index) const {
            if (m_start == nullptr) {
                throw "Index out of bounds";
            }

            auto current = m_start.get();
            for (auto i = 0u; i < index; i++) {
                current = current->m_next.get();
                if (current == nullptr) {
                    throw "Index out of bounds";
                }
            }
            return current->m_value;
        }
    };
}; // namespace matf

std::ostream& operator<<(std::ostream& out, const matf::List& l);
