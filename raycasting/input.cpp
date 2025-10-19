#include "input.hpp"

bool Input::keys_pressed[SDL_NUM_SCANCODES] = {};

bool Input::is_key_pressed(const SDL_Scancode scan_code)
{
  return keys_pressed[scan_code];
}

void Input::press_key(const SDL_Scancode scan_code)
{
  keys_pressed[scan_code] = true;
}

void Input::release_key(const SDL_Scancode scan_code)
{
  keys_pressed[scan_code] = false;
}
