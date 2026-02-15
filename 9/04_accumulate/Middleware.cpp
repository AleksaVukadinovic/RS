#include "Middleware.hpp"

HttpRequest &operator+(HttpRequest &&request, const MiddlewareFunction &f) {
    request.add_content(f.m_request_type, f.m_content);
    return request;
}

MiddlewareFunction::MiddlewareFunction(std::string request_type, std::string content) : m_request_type(request_type), m_content(content) {}
