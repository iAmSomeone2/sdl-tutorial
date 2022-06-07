#include <projconfig.h>

#include "Game.hpp"
#include "SDLException.hpp"

#include <fmt/format.h>

#include <iostream>
#include <cstdint>
#include <string>

static const uint_fast16_t WINDOW_WIDTH = 640;
static const uint_fast16_t WINDOW_HEIGHT = 480;
const std::string HELLO_BMP = "bmp/hello.bmp";

int main(int argc, char **argv) {
    if(argc != 1) {
        fmt::print(stderr, "{:s} takes no arguments.\n", argv[0]);
        return 1;
    }

    auto game = Game::init(PROJECT_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
    try {
        game.loadImg(HELLO_BMP);
    } catch (const SDLException& ex) {
        std::cerr << ex.what() << '\n';
    }
    game.run();

    return 0;
}
