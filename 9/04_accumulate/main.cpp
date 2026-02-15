#include "HttpRequest.hpp"
#include "Middleware.hpp"
#include <iostream>
#include <numeric>
#include <vector>

namespace matf {
    template <typename ForwardIterator, typename T>
    T accumulate(ForwardIterator first, ForwardIterator last, T init) {
        for (; first != last; ++first)
            init = std::move(init) + *first; // std::move is for strings
        return init;
    }
} // namespace matf

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5};
    std::cout << "Sum std::accumulate: " << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
    std::cout << "Sum matf::accumulate: " << matf::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;

    std::vector<MiddlewareFunction> requestHandling {
        MiddlewareFunction("Header", "Content-Type: application/json"),
        MiddlewareFunction("Body", "{\"name\":\"Pera\", \"surname\": \"Peric\" }")
    };
    std::cout << "HTTP request handling using matf::accumulate: "<< std::endl;
    std::cout << matf::accumulate(requestHandling.cbegin(), requestHandling.cend(), HttpRequest{});

    return 0;
}
