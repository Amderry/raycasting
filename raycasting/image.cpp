#include "image.hpp"

Image::Image()
{
  m_xSize = 0;
  m_ySize = 0;
  m_pTexture = NULL;
  m_rChannel = NULL;
  m_gChannel = NULL;
  m_bChannel = NULL;
}

Image::~Image()
{
  if (m_pTexture != NULL)
  {
    SDL_DestroyTexture(m_pTexture);
  }
  delete[] m_rChannel;
  delete[] m_gChannel;
  delete[] m_bChannel;
  m_rChannel = NULL;
  m_gChannel = NULL;
  m_bChannel = NULL;
}

void Image::init(const int x_size, const int y_size, SDL_Renderer *pRenderer)
{
  m_rChannel = new double[x_size * y_size];
  m_gChannel = new double[x_size * y_size];
  m_bChannel = new double[x_size * y_size];

  m_xSize = x_size;
  m_ySize = y_size;

  m_pRenderer = pRenderer;

  init_texture();
}

void Image::set_pixel(const int x, const int y, const double red, const double green, const double blue)
{
  m_rChannel[y * m_xSize + x] = red;
  m_gChannel[y * m_xSize + x] = green;
  m_bChannel[y * m_xSize + x] = blue;
}

void Image::display()
{
  Uint32 *temp_pixels = new Uint32[m_xSize * m_ySize];

  memset(temp_pixels, 0, m_xSize * m_ySize * sizeof(Uint32));

  for(int x = 0; x < m_xSize; ++x)
  {
    for(int y = 0; y < m_ySize; ++y)
    {
      temp_pixels[y * m_xSize + x] = convert_color(m_rChannel[y * m_xSize + x], m_gChannel[y * m_xSize + x], m_bChannel[y * m_xSize + x]);
    }
  }

  SDL_UpdateTexture(m_pTexture, NULL, temp_pixels, m_xSize * sizeof(Uint32));
  delete[] temp_pixels;

  SDL_Rect src_rect, bound;
  src_rect.x = 0;
  src_rect.y = 0;
  src_rect.w = m_xSize;
  src_rect.h = m_ySize;

  bound = src_rect;
  SDL_RenderCopy(m_pRenderer, m_pTexture, &src_rect, &bound);
}

void Image::init_texture()
{
  Uint32 rmask, gmask, bmask, amask;

  #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
  #else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
  #endif

  if (m_pTexture != NULL)
    SDL_DestroyTexture(m_pTexture);

  SDL_Surface *temp_surface = SDL_CreateRGBSurface(0, m_xSize, m_ySize, 32, rmask, gmask, bmask, amask);
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, temp_surface);
  SDL_FreeSurface(temp_surface);
}

Uint32 Image::convert_color(const double red, const double green, const double blue)
{
  unsigned char r = static_cast<unsigned char>(red);
  unsigned char g = static_cast<unsigned char>(green);
  unsigned char b = static_cast<unsigned char>(blue);

  #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 pixel_color = (b << 24) + (g << 16) + (r << 8) + 255;
  #else
    Uint32 pixel_color = (255 << 24) + (b << 16) + (g << 8) + r;
  #endif

  return pixel_color;
}

int Image::get_x()
{
  return m_xSize;
}

int Image::get_y()
{
  return m_ySize;
}
