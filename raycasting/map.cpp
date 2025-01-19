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
  char ch_length;
  map_file.get(ch_length);
  map_length = static_cast<int>(ch_length) - 48;

  map_array = new int[map_length];

  for(int i = 0; i < map_length; ++i)
  {
    char ch_map;
    map_file.get(ch_map);
    map_array[i] = static_cast<int>(ch_map);
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
