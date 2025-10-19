#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL_scancode.h>

class Input
{
  public:
    static bool is_key_pressed(const SDL_Scancode scan_code);
    static void press_key(const SDL_Scancode scan_code);
    static void release_key(const SDL_Scancode scan_code);
  private:
    static bool keys_pressed[SDL_NUM_SCANCODES];
};

#endif
