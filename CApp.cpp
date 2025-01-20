#include "CApp.hpp"

// CApp constructor
CApp::CApp(Uint32 w, Uint32 h)
{
  m_width = w;
  m_height = h;
  is_running = true;
  pWindow = NULL;
  pRenderer = NULL;
}

bool CApp::on_init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    return false;
  }

  pWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);

  if (pWindow != NULL)
  {
    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

    //Init image
    m_image.init(m_width, m_height, pRenderer);

    //Create colors
    
    m_map.load("maps/first.txt");
  }
  else
  {
    return false;
  }

  return true;
}

int CApp::on_execute()
{
  SDL_Event event;

  if(on_init() == false)
  {
    return -1;
  }

  while (is_running)
  { 
    while (SDL_PollEvent(&event))
    {
      on_event(&event);
    }

    on_loop();
    on_render();
  }
  on_exit();
  return 0;
}

void CApp::on_event(SDL_Event *event)
{
  if (event->type == SDL_QUIT)
  {
    is_running = false;
  }
}

void CApp::on_loop()
{
  const int * const map_array = m_map.get_map();
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
        m_image.set_pixel(x * 8 + j % 8, y * 8 + j / 8, red, green, blue);
      }
    }
  }
  m_image.set_pixel(32, 30, 255.0, 255.0, 255.0);
}

void CApp::on_render()
{
  SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
  SDL_RenderClear(pRenderer);

  //Display image
  m_image.display();

  //update buffers
  SDL_RenderPresent(pRenderer);
}

void CApp::on_exit()
{
  m_map.unload();
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  pWindow = NULL;
  SDL_Quit();
}
