#pragma once
#include <memory>

namespace matf 
{

class List 
{
private:
// TODO
    class Element {
        private:

    }

    size_t m_size = 0u;
    std::unique_ptr<Element> m_start = nullptr;

public:
    void push_back(const int x);
    void push_front(const int x);
};  
};