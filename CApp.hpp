#ifndef CAPP_HPP
#define CAPP_HPP

#include <SDL2/SDL.h>
#include <stdlib.h>
#include "raycasting/map.hpp"
#include "raycasting/player.hpp"
#include "raycasting/input.hpp"
#include "raycasting/scene.hpp"

class CApp
{
  public:
    CApp(Uint32 width, Uint32 height);

    int on_execute();
    bool on_init();
    void on_event(SDL_Event *event);
    void on_loop();
    void on_render();
    void on_exit();

  private:
    bool is_running;
    Scene m_scene;
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Uint32 m_width;
    Uint32 m_height;
};

#endif
