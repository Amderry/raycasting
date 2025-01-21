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

void Player::move()
{
  if (Input::is_key_pressed(SDLK_w))
  {
    set_pos(m_x, m_y - 1);
  }
  if (Input::is_key_pressed(SDLK_s))
  {
    set_pos(m_x, m_y + 1);
  }
  if (Input::is_key_pressed(SDLK_a))
  {
    set_pos(m_x - 1, m_y);
  }
  if (Input::is_key_pressed(SDLK_d))
  {
    set_pos(m_x + 1, m_y);
  }
}
