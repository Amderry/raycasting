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
    int get_m_length();

    void set_vertical_size(int vsize);
    int get_vertical_size();
    void set_horizontal_size(int hsize);
    int get_horizontal_size();
    void set_chunk_size(int csize);
    int get_chunk_size();

    bool is_colliding(int dx, int dy);

  private:
    int *m_map_array;
    int m_length;
    int m_vertical_size;
    int m_horizontal_size;
    int m_chunk_size;
};

#endif
