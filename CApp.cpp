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
    m_player.set_pos(32,30);
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
  switch (event->type)
  {
    case(SDL_QUIT):
      is_running = false;
    break;
    case(SDL_KEYDOWN):
      Input::press_key(event->key.keysym.sym); 
    break;
    case(SDL_KEYUP):
      Input::release_key(event->key.keysym.sym);
    break;
  }
}

void CApp::on_loop()
{
  m_map.draw_map(m_image, m_width, m_height);
  if (Input::is_key_pressed(SDLK_w))
  {
    m_player.set_pos(m_player.get_pos_x(), m_player.get_pos_y() - 2);
  }
  if (Input::is_key_pressed(SDLK_s))
  {
    m_player.set_pos(m_player.get_pos_x(), m_player.get_pos_y() + 2);
  }
  if (Input::is_key_pressed(SDLK_a))
  {
    m_player.set_pos(m_player.get_pos_x() - 2, m_player.get_pos_y());
  }
  if (Input::is_key_pressed(SDLK_d))
  {
    m_player.set_pos(m_player.get_pos_x() + 2, m_player.get_pos_y());
  }
  m_player.draw_player(m_image);
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
