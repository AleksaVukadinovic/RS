#include "Fraction.hpp"
#include <iostream>

int main() {
    std::cout << "========================================\n";
    Fraction f1(3, 4);
    Fraction f2(-5);
    Fraction f3;

    std::cout << "f1: " << f1 << std::endl;

    std::cin >> f3;
    std::cout << "f3: " << f3 << std::endl;

    std::cout << f1 + f2 << std::endl;

    return 0;
}