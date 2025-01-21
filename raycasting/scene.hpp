#ifndef SCENE_HPP
#define SCENE_HPP

#include "player.hpp"
#include "map.hpp"
#include "image.hpp"
#include <SDL2/SDL_render.h>

class Scene
{
  public:
    Scene();
    ~Scene();
    void init(Uint32 w, Uint32 h, SDL_Renderer* pRenderer);
    void build();
    Map* get_map();
    Player* get_player();
  private:
    Player m_player;
    Map m_map;
    Image m_image;
};

#endif
