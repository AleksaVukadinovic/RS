#include "HttpRequest.hpp"
#include <utility>

void HttpRequest::add_content(std::string request_type, std::string content) {
    m_content.insert(std::make_pair(request_type, content));
}

std::ostream &operator<<(std::ostream &out, const HttpRequest &http_request) {
    for (const auto [request_type, content] : http_request.m_content)
        out << '\t' << request_type << ": " << content << std::endl;
    return out;
}
