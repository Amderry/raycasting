#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
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

    //Get x size
    int get_x();

    //Get y size
    int get_y();

  private:
    Uint32 convert_color(const double red, const double green, const double blue);
    void init_texture();
    double *m_rChannel;
    double *m_gChannel;
    double *m_bChannel;
    int m_xSize, m_ySize;
    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;
};

#endif
