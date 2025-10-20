#include "player.hpp"

Player::Player()
{ 
  m_x = 0;
  m_y = 0;
}

Player::~Player()
{

}

void Player::init(Uint32 x, Uint32 y)
{
  set_pos(x, y);
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

void Player::move(Map *map, int speed)
{
  int dy = m_y;
  int dx = m_x;
  if (Input::is_key_pressed(SDL_SCANCODE_W))
  {
    if (!map->is_colliding(m_x, m_y - speed))
    {
      dy -= speed;
    }
  }
  if (Input::is_key_pressed(SDL_SCANCODE_S))
  {
    if (!map->is_colliding(m_x, m_y + speed))
    {
      dy += speed;
    }
  }
  if (Input::is_key_pressed(SDL_SCANCODE_A))
  {
    if (!map->is_colliding(m_x - speed, m_y))
    {
      dx -= speed;
    }
  }
  if (Input::is_key_pressed(SDL_SCANCODE_D))
  {
    if (!map->is_colliding(m_x + speed, m_y))
    {
      dx += speed;
    }
  }

  set_pos(dx, dy);
}
