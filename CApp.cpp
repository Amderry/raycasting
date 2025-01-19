#include "CApp.hpp"

// CApp constructor
CApp::CApp()
{
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

  pWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

  if (pWindow != NULL)
  {
    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

    //Init image
    m_image.init(1280, 720, pRenderer);

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
  for (int x = 0; x < 160; ++x)
  {
    for (int y = 0; y < 90; ++y)
    {
      double green = (static_cast<double>(random() % 1280)/1280.0) * 255;
      double blue = (static_cast<double>(random() % 720)/720.0) * 255;
      for (int j = 0; j < 64; ++j)
      {
        m_image.set_pixel(x * 8 + j % 8, y * 8 + j / 8, 0.0, green, blue);
      }
    }
  }
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
