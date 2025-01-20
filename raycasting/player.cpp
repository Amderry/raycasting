#include "player.hpp"

Player::Player()
{ 
  m_x = 0;
  m_y = 0;
}

Player::~Player()
{

}

void Player::set_pos(Uint32 x, Uint32 y)
{
  m_x = x;
  m_y = y;
}

Uint32 Player::get_pos_x()
{
  return m_x;
}

Uint32 Player::get_pos_y()
{
  return m_y;
}

void Player::draw_player(Image& image)
{
  image.set_pixel(m_x, m_y, 255.0, 255.0, 255.0);
}
