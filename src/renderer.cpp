#include "renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <fmt/base.h>
#include <stdexcept>

Renderer::Renderer(
    const std::string_view &title, const int &width, const int &height)
    : window{}, renderer{}
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("Failed to initialize SDL");

    if (!(this->window = SDL_CreateWindow(
              title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)))
        throw std::runtime_error("Failed to create a SDL window");

    if (!(this->renderer =
              SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED))) {
        SDL_DestroyWindow(this->window);
        throw std::runtime_error("Failed to create a SDL renderer");
    }
}

Renderer::~Renderer()
{
    if (this->renderer)
        SDL_DestroyRenderer(this->renderer);

    if (this->window)
        SDL_DestroyWindow(this->window);

    SDL_Quit();
}

void Renderer::run(void)
{
    SDL_RaiseWindow(this->window);
    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT: {
                fmt::println("Quitting...");
                return;
            }
            default:
                break;
            }
        }

        SDL_RenderClear(this->renderer);
        SDL_RenderPresent(this->renderer);
    }
}