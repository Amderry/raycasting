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
    for (int x = 0; x < 1280; ++x)
    {
      for (int y = 0; y < 720; ++y)
      {
        double red = (static_cast<double>(x)/1280.0) * 255;
        double green = (static_cast<double>(y)/720.0) * 255;
        m_image.set_pixel(x, y, red, green, 0.0);
      }
    }
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
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  pWindow = NULL;
  SDL_Quit();
}
