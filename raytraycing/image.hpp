#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Image
{
  public:
    //Constructor
    Image();

    //Destructor
    ~Image();

    //Init
    void init(const int x_size, const int y_size, SDL_Renderer *pRenderer);

    //Set pixel color
    void set_pixel(const int x, const int y, const double red, const double green, const double blue);

    //Return image to display
    void display();

  private:
    Uint32 convert_color(const double red, const double green, const double blue);
    void init_texture();
    std::vector<std::vector<double>> m_rChannel;
    std::vector<std::vector<double>> m_gChannel;
    std::vector<std::vector<double>> m_bChannel;
    int m_xSize, m_ySize;
    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;
};

#endif
