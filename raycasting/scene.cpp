#include "scene.hpp"

Scene::Scene()
{
  m_map.set_horizontal_size(8);
  m_map.set_vertical_size(8);
  m_map.set_chunk_size(9);
}

Scene::~Scene()
{
  m_map.unload();
}

void Scene::init(Uint32 w, Uint32 h, SDL_Renderer *pRenderer)
{
  m_image.init(w, h, pRenderer);
  m_player.init(50, 50);
}

void Scene::build()
{
  int chunk_size = m_map.get_chunk_size();
  int vertical_size = m_map.get_vertical_size();
  int horizontal_size = m_map.get_horizontal_size();

  for (int y = 0; y < vertical_size; ++y)
  {
    for (int x = 0; x < horizontal_size; ++x)
    {
      double red, green, blue;
      if (m_map.get_map()[x + y * vertical_size])
      { 
        red = 255.0;
        blue = 255.0;
        green = 255.0;
      }
      else
      {
        red = 0.0;
        blue = 0.0;
        green = 0.0;
      }
      for (int j = 0; j < chunk_size * chunk_size; ++j)
      {
        m_image.set_pixel(x * chunk_size + j % chunk_size, y * chunk_size + j / chunk_size, red, green, blue);
      }
    }
  }

  m_image.set_pixel(m_player.get_pos_x(), m_player.get_pos_y(), 255.0, 255.0, 255.0);
  m_image.display();
}

void Scene::act()
{
  m_player.move(&m_map, 1);
}

Map* Scene::get_map()
{
  return &m_map;
}

Player* Scene::get_player()
{
  return &m_player;
}
