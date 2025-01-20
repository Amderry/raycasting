#include "input.hpp"

bool Input::keys_pressed[348] = {};

bool Input::is_key_pressed(const SDL_Keycode key_code)
{
  return keys_pressed[key_code];
}

void Input::press_key(const SDL_Keycode key_code)
{
  keys_pressed[key_code] = true;
}

void Input::release_key(const SDL_Keycode key_code)
{
  keys_pressed[key_code] = false;
}
