#include <iostream>
#include <vector>
#include <complex>
#include <numeric>
#include <algorithm>
#include <iterator>

template<typename C, typename T = typename C::value_type>
void read_print_average_templated(C& numbers) {
    using namespace std;
    copy(istream_iterator<T>(cin), istream_iterator<T>(), back_inserter(numbers));
    copy(cbegin(numbers), cend(numbers), ostream_iterator<T>(cout, "\n"));
    std::cout << "Average: " << accumulate(numbers.begin(), numbers.end(), std::complex<double>{}) / static_cast<double>(numbers.size()) << std::endl;
}

void read_print_average(std::vector<std::complex<double>>& numbers) {
    using namespace std;
    copy(istream_iterator<complex<double>>(cin), istream_iterator<complex<double>>(), back_inserter(numbers));
    copy(cbegin(numbers), cend(numbers), ostream_iterator<complex<double>>(cout, "\n"));
    std::cout << "Average: " << accumulate(numbers.begin(), numbers.end(), std::complex<double>{}) / static_cast<double>(numbers.size()) << std::endl;
}

int main() {
    std::vector<std::complex<double>> numbers;
    read_print_average(numbers);
    read_print_average_templated(numbers);
    return 0;
}