#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "input.hpp"
#include "map.hpp"
#include <SDL2/SDL_scancode.h>

class Player
{
  public:
    Player();
    ~Player();
    Uint32 get_pos_x();
    Uint32 get_pos_y();
    void init(Uint32 x, Uint32 y);
    void move(Map* map, int speed); 

  private:
    Uint32 m_x;
    Uint32 m_y;
    void set_pos(Uint32 x, Uint32 y);
};

#endif
