#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL_keycode.h>

class Input
{
  public:
    static bool is_key_pressed(const SDL_Keycode key_code);
    static void press_key(const SDL_Keycode key_code);
    static void release_key(const SDL_Keycode key_code);
  private:
    static bool keys_pressed[348];
};

#endif
