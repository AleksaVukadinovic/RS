#pragma once

#include "HttpRequest.hpp"
#include <string>

class MiddlewareFunction {
private:
    std::string m_request_type;
    std::string m_content;

    friend HttpRequest &operator+(HttpRequest &&request, const MiddlewareFunction &f);

public:
    MiddlewareFunction(std::string request_type, std::string content);
};
