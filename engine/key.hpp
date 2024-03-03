#ifndef SDLGAME_KEY_
#define SDLGAME_KEY_

#include "SDL2/SDL_scancode.h"
#include <vector>



namespace sdlgame{
    typedef enum
    {
        K_a = SDL_SCANCODE_A,
        K_b = SDL_SCANCODE_B,
        K_c = SDL_SCANCODE_C,
        K_d = SDL_SCANCODE_D,
        K_e = SDL_SCANCODE_E,
        K_f = SDL_SCANCODE_F,
        K_g = SDL_SCANCODE_G,
        K_h = SDL_SCANCODE_H,
        K_i = SDL_SCANCODE_I,
        K_j = SDL_SCANCODE_J,
        K_k = SDL_SCANCODE_K,
        K_l = SDL_SCANCODE_L,
        K_m = SDL_SCANCODE_M,
        K_n = SDL_SCANCODE_N,
        K_o = SDL_SCANCODE_O,
        K_p = SDL_SCANCODE_P,
        K_q = SDL_SCANCODE_Q,
        K_r = SDL_SCANCODE_R,
        K_s = SDL_SCANCODE_S,
        K_t = SDL_SCANCODE_T,
        K_u = SDL_SCANCODE_U,
        K_v = SDL_SCANCODE_V,
        K_w = SDL_SCANCODE_W,
        K_x = SDL_SCANCODE_X,
        K_y = SDL_SCANCODE_Y,
        K_z = SDL_SCANCODE_Z,

        K_0 = SDL_SCANCODE_0,
        K_1 = SDL_SCANCODE_1,
        K_2 = SDL_SCANCODE_2,
        K_3 = SDL_SCANCODE_3,
        K_4 = SDL_SCANCODE_4,
        K_5 = SDL_SCANCODE_5,
        K_6 = SDL_SCANCODE_6,
        K_7 = SDL_SCANCODE_7,
        K_8 = SDL_SCANCODE_8,
        K_9 = SDL_SCANCODE_9,

        K_F1 = SDL_SCANCODE_F1,
        K_F2 = SDL_SCANCODE_F2,
        K_F3 = SDL_SCANCODE_F3,
        K_F4 = SDL_SCANCODE_F4,
        K_F5 = SDL_SCANCODE_F5,
        K_F6 = SDL_SCANCODE_F6,
        K_F7 = SDL_SCANCODE_F7,
        K_F8 = SDL_SCANCODE_F8,
        K_F9 = SDL_SCANCODE_F9,
        K_F10 = SDL_SCANCODE_F10,
        K_F11 = SDL_SCANCODE_F11,
        K_F12 = SDL_SCANCODE_F12,

        K_SPACE = SDL_SCANCODE_SPACE,
        K_COMMA = SDL_SCANCODE_COMMA,
        K_PERIOD = SDL_SCANCODE_PERIOD,
        K_SLASH = SDL_SCANCODE_SLASH,
        K_SEMICOLON = SDL_SCANCODE_SEMICOLON,
        K_APOSTROPHE = SDL_SCANCODE_APOSTROPHE,
        K_LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET,
        K_RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET,
        K_BACKSLASH = SDL_SCANCODE_BACKSLASH,
        K_MINUS = SDL_SCANCODE_MINUS,
        K_EQUALS = SDL_SCANCODE_EQUALS,
        K_BACKSPACE = SDL_SCANCODE_BACKSPACE,
        K_RETURN = SDL_SCANCODE_RETURN,

        K_CAPSLOCK = SDL_SCANCODE_CAPSLOCK,
        K_SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK,
        K_NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR,
        K_INSERT = SDL_SCANCODE_INSERT,
        K_HOME = SDL_SCANCODE_HOME,
        K_PAGEUP = SDL_SCANCODE_PAGEUP,
        K_DELETE = SDL_SCANCODE_DELETE,
        K_END = SDL_SCANCODE_END,
        K_PAGEDOWN = SDL_SCANCODE_PAGEDOWN,
        K_RIGHT = SDL_SCANCODE_RIGHT,
        K_LEFT = SDL_SCANCODE_LEFT,
        K_DOWN = SDL_SCANCODE_DOWN,
        K_UP = SDL_SCANCODE_UP,

        K_KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
        K_KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY,
        K_KP_MINUS = SDL_SCANCODE_KP_MINUS,
        K_KP_PLUS = SDL_SCANCODE_KP_PLUS,
        K_KP_ENTER = SDL_SCANCODE_KP_ENTER,
        K_KP_1 = SDL_SCANCODE_KP_1,
        K_KP_2 = SDL_SCANCODE_KP_2,
        K_KP_3 = SDL_SCANCODE_KP_3,
        K_KP_4 = SDL_SCANCODE_KP_4,
        K_KP_5 = SDL_SCANCODE_KP_5,
        K_KP_6 = SDL_SCANCODE_KP_6,
        K_KP_7 = SDL_SCANCODE_KP_7,
        K_KP_8 = SDL_SCANCODE_KP_8,
        K_KP_9 = SDL_SCANCODE_KP_9,
        K_KP_0 = SDL_SCANCODE_KP_0,
        K_KP_PERIOD = SDL_SCANCODE_KP_PERIOD,

        K_APPLICATION = SDL_SCANCODE_APPLICATION,
        K_POWER = SDL_SCANCODE_POWER,
        K_KP_EQUALS = SDL_SCANCODE_KP_EQUALS,
        K_F13 = SDL_SCANCODE_F13,
        K_F14 = SDL_SCANCODE_F14,
        K_F15 = SDL_SCANCODE_F15,
        K_F16 = SDL_SCANCODE_F16,
        K_F17 = SDL_SCANCODE_F17,
        K_F18 = SDL_SCANCODE_F18,
        K_F19 = SDL_SCANCODE_F19,
        K_F20 = SDL_SCANCODE_F20,
        K_F21 = SDL_SCANCODE_F21,
        K_F22 = SDL_SCANCODE_F22,
        K_F23 = SDL_SCANCODE_F23,
        K_F24 = SDL_SCANCODE_F24,
        K_EXECUTE = SDL_SCANCODE_EXECUTE,
        K_HELP = SDL_SCANCODE_HELP,
        K_MENU = SDL_SCANCODE_MENU,
        K_SELECT = SDL_SCANCODE_SELECT,
        K_STOP = SDL_SCANCODE_STOP,
        K_AGAIN = SDL_SCANCODE_AGAIN,
        K_UNDO = SDL_SCANCODE_UNDO,
        K_CUT = SDL_SCANCODE_CUT,
        K_COPY = SDL_SCANCODE_COPY,
        K_PASTE = SDL_SCANCODE_PASTE,
        K_FIND = SDL_SCANCODE_FIND,
        K_MUTE = SDL_SCANCODE_MUTE,
        K_VOLUMEUP = SDL_SCANCODE_VOLUMEUP,
        K_VOLUMEDOWN = SDL_SCANCODE_VOLUMEDOWN,
    } K_Code;
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
        std::vector<bool> &get_pressed()
        {
            int numKeys;
            SDL_PumpEvents();
            keyState = SDL_GetKeyboardState(&numKeys);
            if (keys.size() == 0)
                keys.resize(numKeys);
            for (int i = 0; i < numKeys; ++i)
            {
                keys[i] = keyState[i];
            }
            return keys;
        }
    }
}
#endif