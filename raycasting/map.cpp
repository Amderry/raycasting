#include "map.hpp"

Map::Map()
{
  map_array = NULL;
  map_length = 0;
}

int Map::load(const std::string map_filename)
{
  std::ifstream map_file(map_filename);
  if (!map_file)
  {
    std::cout << "Unable to load map";
    return 1;   
  }

  map_file >> map_length;
  map_array = new int[map_length];

  for(int i = 0; i < map_length; ++i)
  {
    map_file >> map_array[i];
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
  map_length = 0;
  delete[] map_array;
  map_array = NULL;
}

int* Map::get_map()
{
  return map_array;
}

void Map::draw_map(Image& image, const Uint32 width, const Uint32 height)
{
  for (int y = 0; y < 8; ++y)
  {
    for (int x = 0; x < 8; ++x)
    {
      double red, green, blue;
      if (map_array[x + y * 8])
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
        image.set_pixel(x * 8 + j % 8, y * 8 + j / 8, red, green, blue);
      }
    }
  }
}
