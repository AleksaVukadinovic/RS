#include <iostream>
#include <vector>
#include <complex>
#include <numeric>

class HttpRequest {};
class MiddlewareFunction {};

MiddlewareFunction f1;
MiddlewareFunction f2;
MiddlewareFunction f3;

HttpRequest req;

// ... req >> f1 >> f2 >> f3;

int main() {
    std::vector<std::complex<double>> numbers;
    std::complex<double> number;

    while (std::cin >> number) {
        numbers.push_back(number);
    }

    //      auto &x
    for (const std::complex<double> &x: numbers)
        std::cout << x << '\n';

    // std::complex<double> sum = 0;
    unsigned n = numbers.size();
    // for (unsigned i=0u; i < n; i++)
    //     sum+= numbers[i];

    std::complex sum = std::accumulate(numbers.begin(), numbers.end(), std::complex<double>());

    std::cout << "Average: " << sum/static_cast<double>(n) << std::endl;

    return 0;
}