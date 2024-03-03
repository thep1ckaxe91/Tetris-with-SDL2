#ifndef SDLGAME_COLOR_
#define SDLGAME_COLOR_
#include "SDL2/SDL.h"
namespace sdlgame{
    namespace color
    {
        /**
         *  class for color, all values range from [0,255]
         */
        std::unordered_map<std::string, std::vector<uint8_t>> color_name;
        class Color
        {
        public:
            Uint8 r, g, b, a;
            Color();
            Color(const char *c_name);
            Color(std::string name);
            template <class T>
            Color(T _r, T _g, T _b);
            template <class T>
            Color(T _r, T _g, T _b, T _a);

            SDL_Color to_SDL_Color() const;
            /**return Uint32 kind of color*/
            Uint32 toUint32Color() const;
            std::string toString();
        };
    }
}

#endif