#include "mouse.hpp"
#include "SDL2/SDL_mouse.h"
#include "math.hpp"
#include <vector>
sdlgame::math::Vector2 sdlgame::mouse::last_mouse_pos;
bool sdlgame::mouse::isVisible;
sdlgame::math::Vector2 sdlgame::mouse::get_pos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return sdlgame::math::Vector2(x, y);
}
std::vector<bool> sdlgame::mouse::get_pressed()
{
    int numButtons = 32;
    Uint32 buttonState = SDL_GetMouseState(NULL, NULL);

    std::vector<bool> buttons(numButtons);
    for (int i = 0; i < numButtons; ++i)
    {
        buttons[i] = buttonState & (1 << i);
    }
    return buttons;
}
sdlgame::math::Vector2 sdlgame::mouse::get_rel()
{
    if (last_mouse_pos == sdlgame::math::Vector2(-1, -1))
        return sdlgame::math::Vector2(0, 0);
    int x, y;
    SDL_GetMouseState(&x, &y);
    sdlgame::math::Vector2 res = sdlgame::math::Vector2(x, y) - last_mouse_pos;
    last_mouse_pos = sdlgame::math::Vector2(x, y);
    return res;
}
void sdlgame::mouse::set_visible(int enable)
{
    isVisible = SDL_ShowCursor(enable);
}
bool sdlgame::mouse::get_visible()
{
    return isVisible;
}