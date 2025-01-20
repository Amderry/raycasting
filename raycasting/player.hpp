#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "image.hpp"

class Player
{
  public:
    Player();
    ~Player();
    void set_pos(Uint32 x, Uint32 y);
    Uint32 get_pos_x();
    Uint32 get_pos_y();
    void draw_player(Image& image);

  private:
    Uint32 m_x;
    Uint32 m_y;
};

#endif
