/**
 * All user event must define here
*/
#ifndef TETRIS_EVENT_HPP
#define TETRIS_EVENT_HPP
#include "engine/engine.hpp"
//just custom user event, all event here is offset from sdlgame::USEREVENT
typedef enum
{
    MERGING = sdlgame::USEREVENT + 1,
    SCORING = sdlgame::USEREVENT + 2,
    GAMEOVER = sdlgame::USEREVENT + 3,
    BUTTON_HOVER = sdlgame::USEREVENT + 4,
    BUTTON_CLICK = sdlgame::USEREVENT + 5,
    ROTATE = sdlgame::USEREVENT + 6,
} Tetris_Event;

#endif