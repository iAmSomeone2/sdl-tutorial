#pragma once

#include <stdexcept>
#include <string>

class SDLException : public std::exception {
public:
    SDLException(const std::string& message);

    const char* what() const throw();
private:
    std::string m_message;
};
