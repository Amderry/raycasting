#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <fstream>
#include <string>

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

  private:
    int *map_array;
    int map_length;
};

#endif
