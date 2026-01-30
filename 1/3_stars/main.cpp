#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> messages;
    size_t max_length = 0;

    std::string line;
    while(getline(std::cin, line)) {
        messages.push_back(line);
        line.clear();

        const size_t line_length = messages.back().size();
        max_length = line_length > max_length ? line_length : max_length;
    }

    const std::string bar(max_length + 4, '*');
    std::cout << bar << std::endl;

    for (const auto& line: messages) {
        std::cout << "* " << line 
                  << std::string(max_length - line.size(), ' ') 
                  << " *" << '\n';
    }
    std::cout << bar << std::endl;
    return 0;
}