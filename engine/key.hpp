#ifndef SDLGAME_KEY_
#define SDLGAME_KEY_

#include "SDL2/SDL_scancode.h"
#include <vector>



namespace sdlgame{
    enum class K_Code;
    namespace key
    {
        namespace
        {
            const Uint8 *keyState;
            std::vector<bool> keys;
        }
        /**
         *  assume that you called the SDL_PumpEvents function before calling this, this funciton should work fine
         */
        std::vector<bool> &get_pressed();
    }
}
#endif