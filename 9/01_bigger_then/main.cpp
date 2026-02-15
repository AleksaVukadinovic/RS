#include <iostream>

namespace matf {
    template<typename T>
    T bigger_then(T a, T b) {
        return a > b ? a : b;
    }
}

using namespace std;

int main() {
    std::cout << "matf::bigger_then(2, 3) = " << matf::bigger_then(2, 3) << std::endl;
    std::cout << "matf::bigger_then(2.3, 3.4) = " << matf::bigger_then(2.3, 3.4) << std::endl;
    // std::cout << "matf::bigger_then(2, 3.0) = " << matf::bigger_then(2, 3.0) << std::endl;
    std::cout << "matf::bigger_then(2, 3.0) = " << matf::bigger_then<double>(2, 3.0) << std::endl;

    return 0;
}
