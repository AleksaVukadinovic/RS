#include <vector>
#include <iostream>

namespace matf {
    template<typename iter>
    iter largest_element(iter begin, iter end) {
        iter largest = begin++;
        for(; begin != end; ++begin)
            if (*largest < *begin)
                largest = begin;
        return largest;
    }
}

int main() {

    std::vector<int> xs{5, 9, -7, 18, -25, 0, 9, 25, 18, 19};
    std::cout << "Largest element: " << *matf::largest_element(xs.cbegin(), xs.cend()) << std::endl;

    std::vector<std::string> ys{"C++", "C#", "Java", "Rust", "TypeScript"};
    std::cout << "Largest element: " << *matf::largest_element(ys.cbegin(), ys.cend()) << std::endl;

    return 0;
}
