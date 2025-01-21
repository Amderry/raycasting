#include "scene.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{
  m_map.unload();
}

void Scene::init(Uint32 w, Uint32 h, SDL_Renderer *pRenderer)
{
  m_image.init(w, h, pRenderer);
}

void Scene::build()
{
  for (int y = 0; y < 8; ++y)
  {
    for (int x = 0; x < 8; ++x)
    {
      double red, green, blue;
      if (m_map.get_map()[x + y * 8])
      { 
        red = static_cast<double>(90 - y)/90.0 * 255;
        blue = static_cast<double>(90 - y)/90.0 * 255;
        green = static_cast<double>(160 - x)/160.0 * 255;
      }
      else
      {
        red = 0.0;
        blue = 0.0;
        green = 0.0;
      }
      for (int j = 0; j < 64; ++j)
      {
        m_image.set_pixel(x * 8 + j % 8, y * 8 + j / 8, red, green, blue);
      }
    }
  }
  m_image.set_pixel(m_player.get_pos_x(), m_player.get_pos_y(), 255.0, 255.0, 255.0);
  m_image.display();
}

Map* Scene::get_map()
{
  return &m_map;
}

Player* Scene::get_player()
{
  return &m_player;
}
