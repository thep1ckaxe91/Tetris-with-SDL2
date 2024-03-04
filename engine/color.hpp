#pragma once
#ifndef SDLGAME_COLOR_
#define SDLGAME_COLOR_
#include "SDL2/SDL.h"
#include <string>
#include <vector>
#include <iostream>
namespace sdlgame{
    namespace color
    {
        /**
         *  class for color, all values range from [0,255]
         */
        class Color
        {
        public:
            Uint8 r, g, b, a;
            Color();
            Color(const char *c_name);
            Color(std::string name);
            Color(int _r, int _g, int _b);
            Color(int _r, int _g, int _b, int _a);

            SDL_Color to_SDL_Color() const;
            /**return Uint32 kind of color*/
            Uint32 toUint32Color() const;
            std::string toString();
        };
    }
}

#endif