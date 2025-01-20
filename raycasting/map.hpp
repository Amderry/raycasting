#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "image.hpp"

class Map
{
  public:
    //Constructor
    Map();

    //Destructor
    ~Map();

    int load(const std::string map_filename);
    
    void unload();

    int* get_map();

    void draw_map(Image& image, const Uint32 width, const Uint32 height);

  private:
    int *map_array;
    int map_length;
};

#endif
