#pragma once

#include <SDL_render.h>
#include <SDL_surface.h>

#include <string>
#include <cstdint>
#include <map>
#include <memory>

class Game {
public:
    /**
     * Game instance destructor
     */
    ~Game();

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
    static Game init(const std::string& title, uint_fast16_t width, uint_fast16_t height);

    /**
     * Execute the game loop.
     */
    void run();

    void loadImg(const std::string& imgPath);
protected:
    /**
     * Creates a new instance of Game
     * 
     * \param window pointer to target SDL_Window
     */
    Game(SDL_Window *window);

    /**
     *  
     */
    void render();
private:
    /** Window pointer */
    std::shared_ptr<SDL_Window> m_window;
    /** The surface contained by the window */
    SDL_Surface *m_screenSurface = nullptr;

    std::map<std::string, std::shared_ptr<SDL_Surface>> m_images;
};