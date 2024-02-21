#include "engine.hpp"

#ifndef desktop_size
sdlgame::math::Vector2 desktop_size = sdlgame::display::get_desktop_size();
#endif