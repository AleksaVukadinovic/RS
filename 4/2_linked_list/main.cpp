#include "List.hpp"
#include <iostream>

int main() {
    std::cout << "Creating a list ..." << std::endl;

    matf::list xs;

    xs.push_back(3);
    xs.push_back(4);
    xs.push_back(5);

    xs.push_front(2);
    xs.push_front(1);
    xs.push_front(0);

    std::cout << "List: " << xs << std::endl;
}