#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <string_view>

class Renderer {
  public:
    explicit Renderer(
        const std::string_view &title, const int &width, const int &height);
    ~Renderer();
    void run(void);

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif