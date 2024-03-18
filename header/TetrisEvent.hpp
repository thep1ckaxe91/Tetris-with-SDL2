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
} Tetris_Event;

#endif