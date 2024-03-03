#ifndef SDLGAME_MOUSE_
#define SDLGAME_MOUSE_
#include <vector>
#include "math.hpp"
namespace sdlgame{
    namespace mouse
    {
        // this weird shiet called anonymous namespace, which can only access within the same namespace unit
        // best for not mess up these var some how
        namespace
        {
            sdlgame::math::Vector2 last_mouse_pos;
            bool isVisible;
        }
        sdlgame::math::Vector2 get_pos();
        std::vector<bool> get_pressed();
        sdlgame::math::Vector2 get_rel();
        void set_visible(int enable);
        bool get_visible();
    }
}

#endif