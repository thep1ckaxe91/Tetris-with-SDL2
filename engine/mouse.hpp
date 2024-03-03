#ifndef SDLGAME_MOUSE_
#define SDLGAME_MOUSE_

namespace sdlgame{
    namespace mouse
    {
        // this weird shiet called anonymous namespace, which can only access within the same namespace unit
        // best for not mess up these var some how
        namespace
        {
            sdlgame::math::Vector2 last_mouse_pos = sdlgame::math::Vector2(-1, -1);
            bool isVisible = true;
        }
        sdlgame::math::Vector2 get_pos()
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            return sdlgame::math::Vector2(x, y);
        }
        std::vector<bool> get_pressed()
        {
            int numButtons = 32;
            Uint32 buttonState = SDL_GetMouseState(NULL, NULL);
`
            std::vector<bool> buttons(numButtons);
            for (int i = 0; i < numButtons; ++i)
            {
                buttons[i] = buttonState & (1 << i);
            }
            return buttons;
        }
        sdlgame::math::Vector2 get_rel()
        {
            if (last_mouse_pos == sdlgame::math::Vector2(-1, -1))
                return sdlgame::math::Vector2(0, 0);
            int x, y;
            SDL_GetMouseState(&x, &y);
            sdlgame::math::Vector2 res = sdlgame::math::Vector2(x, y) - last_mouse_pos;
            last_mouse_pos = sdlgame::math::Vector2(x, y);
            return res;
        }
        void set_visible(int enable)
        {
            isVisible = SDL_ShowCursor(enable);
        }
        bool get_visible()
        {
            return isVisible;
        }
    }
}