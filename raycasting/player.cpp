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

/*
  В методе move действуем следующим образом:
  сначала проверяем, насколько мы близки к границе массива, содержащего стЕны для избежания segfault
  затем считаем номер "чанка" карты, в котором расположен игрок формулой: m//n + m_y - (m_y % n), где n - размер стороны чанка
*/

void Player::move(int* map, int map_side_size)
{
  if (Input::is_key_pressed(SDLK_w))
  {
    set_pos(m_x, m_y - ((m_y - 1) / map_side_size > 0 && (m_y - 1) / map_side_size < (map_side_size - 1) ? !map[m_x / map_side_size + (m_y - 1) - ((m_y - 1) % map_side_size)] : 0));
  }
  if (Input::is_key_pressed(SDLK_s))
  {
    set_pos(m_x, m_y + ((m_y + 1) / map_side_size > 0 && (m_y + 1) / map_side_size < (map_side_size - 1) ? !map[m_x / map_side_size + (m_y + 1) - ((m_y + 1) % map_side_size)] : 0));
  }
  if (Input::is_key_pressed(SDLK_a))
  {
    set_pos(m_x - ((m_x - 1) / map_side_size > 0 && (m_x - 1) / map_side_size < (map_side_size - 1) ? !map[(m_x - 1) / map_side_size + m_y - (m_y % map_side_size)] : 0), m_y);
  }
  if (Input::is_key_pressed(SDLK_d))
  {
    set_pos(m_x + ((m_x + 1) / map_side_size > 0 && (m_x + 1) / map_side_size < (map_side_size - 1) ? !map[(m_x + 1) / map_side_size + m_y - (m_y % map_side_size)] : 0), m_y);
  }
}
