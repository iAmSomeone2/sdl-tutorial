#include "SDLException.hpp"

#include <fmt/format.h>
#include <SDL_error.h>

SDLException::SDLException(const std::string& message) {
    this->m_message = fmt::format("[SDLError] {:s}: {:s}", message, SDL_GetError());
}

const char* SDLException::what() const throw() {
    return this->m_message.c_str();
}
