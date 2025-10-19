#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "input.hpp"
#include <SDL2/SDL_scancode.h>

class Player
{
  public:
    Player();
    ~Player();
    Uint32 get_pos_x();
    Uint32 get_pos_y();
    void init(Uint32 x, Uint32 y);
    void move(int* map, int map_side_size); // Указатель на карту для возможности коллизий, пока не придумал, как лучше сделать

  private:
    Uint32 m_x;
    Uint32 m_y;
    void set_pos(Uint32 x, Uint32 y);
};

#endif
