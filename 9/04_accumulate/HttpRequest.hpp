#pragma once

#include <iostream>
#include <map>
#include <ostream>
#include <string>

class HttpRequest {
  public:
    void add_content(std::string request_type, std::string content);
    friend std::ostream &operator<<(std::ostream &out, const HttpRequest &http_request);

  private:
    std::map<std::string, std::string> m_content;
};
