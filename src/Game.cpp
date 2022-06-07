#include "Game.hpp"
#include "SDLException.hpp"

#include <SDL.h>
#include <fmt/format.h>

/**
 * Initializes the SDL context, then creates a Game instance if successful
 * 
 * \param title application title
 * \param width width -- in pixels -- of application window
 * \param height height -- in pixels -- of application window
 * 
 * \returns a new Game instance if SDL initialization was successful
 * \throws SDLException if SDL initialization fails.
 */
Game Game::init(const std::string& title, uint_fast16_t width, uint_fast16_t height) {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw SDLException("SDL could not initialize!");
        }

        // Create window
        SDL_Window* window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            throw SDLException("Window could not be created!");
        }

        return Game(window);
}

/**
 * Creates a new instance of Game
 * 
 * \param window pointer to target SDL_Window
 */
Game::Game(SDL_Window *window) {
    this->m_window = std::shared_ptr<SDL_Window>(window, SDL_DestroyWindow);
    // Get window surface
    m_screenSurface = SDL_GetWindowSurface(m_window.get());
}

Game::~Game() {
    SDL_Quit();
}

void Game::render() {
    // Fill the surface white
    SDL_FillRect(m_screenSurface, nullptr, SDL_MapRGB(m_screenSurface->format, 0x00, 0x00, 0x00));

    SDL_BlitSurface(this->m_images.at("bmp/hello.bmp").get(), nullptr, m_screenSurface, nullptr);

    // Update the surface
    SDL_UpdateWindowSurface(m_window.get());
}

void Game::run() {
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                fmt::print(stdout, "Quit event received. Exiting...\n");
            }
        }

        this->render();
        SDL_Delay(16);
    }
}

void Game::loadImg(const std::string& imgPath) {
    auto img = std::shared_ptr<SDL_Surface>(SDL_LoadBMP(imgPath.c_str()), SDL_FreeSurface);
    if (img == nullptr) {
        throw SDLException(fmt::format("Unable to load image \"{:s}\"", imgPath));
    }
    this->m_images.insert(std::pair<std::string, std::shared_ptr<SDL_Surface>>(imgPath, img));
}
