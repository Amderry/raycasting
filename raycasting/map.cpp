#include "map.hpp"

Map::Map()
{
  m_map_array = NULL;
  m_length = 0;
}

int Map::load(const std::string map_filename)
{
  std::ifstream map_file(map_filename);
  if (!map_file)
  {
    std::cout << "Unable to load map";
    return 1;   
  }

  map_file >> m_length;
  m_map_array = new int[m_length];

  for(int i = 0; i < m_length; ++i)
  {
    map_file >> m_map_array[i];
  }
  map_file.close();

  return 0;
}

Map::~Map()
{
  unload();
}

void Map::unload()
{
  m_length = 0;
  delete[] m_map_array;
  m_map_array = NULL;
}

int* Map::get_map()
{
  return m_map_array;
}

int Map::get_m_length()
{ 
  return m_length;
}

void Map::set_vertical_size(int vsize)
{
  m_vertical_size = vsize;
}

int Map::get_vertical_size()
{
  return m_vertical_size;
}

void Map::set_horizontal_size(int hsize)
{
  m_horizontal_size = hsize;
}

int Map::get_horizontal_size()
{
  return m_horizontal_size; 
}

void Map::set_chunk_size(int csize)
{
  m_chunk_size = csize;
}

int Map::get_chunk_size()
{
  return m_chunk_size;
}

void Map::draw_map(Image& image, const Uint32 width, const Uint32 height)
{
  for (int y = 0; y < m_vertical_size; ++y)
  {
    for (int x = 0; x < m_horizontal_size; ++x)
    {
      double red, green, blue;
      if (m_map_array[x + y * m_chunk_size])
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
      for (int j = 0; j < m_vertical_size * m_horizontal_size; ++j)
      {
        image.set_pixel(x * m_chunk_size + j % m_chunk_size, y * m_chunk_size + j / m_chunk_size, red, green, blue);
      }
    }
  }
}

bool Map::is_colliding(int dx, int dy)
{
  if ((dx / m_chunk_size >= 0 && dx / m_chunk_size <= (m_horizontal_size - 1)) && (dy / m_chunk_size >= 0 && dy / m_chunk_size <= (m_vertical_size - 1)))
  {
    return m_map_array[dy / m_chunk_size * m_vertical_size + dx / m_chunk_size];
  }
  else
  {
    return true;
  }
}
