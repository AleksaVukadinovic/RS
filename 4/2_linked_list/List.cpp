#include "List.hpp"

std::ostream& operator<<(std::ostream& out, const matf::List& l) {
    for (auto i = 0u; i < l.size(); i++) {
        out << l[i] << " ";
    }
    return out;
}
