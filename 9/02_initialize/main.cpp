#include <iostream>
#include <vector>

namespace matf {
    template<typename ForwardIterator, typename T>
    void initialize(ForwardIterator begin, ForwardIterator end, T value) {
        while (begin != end)
            *begin++ = value++;
    }
}

int main() {
    std::vector<int> v(5u);

    matf::initialize(v.begin(), v.end(), 1);
    for (const auto &i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
