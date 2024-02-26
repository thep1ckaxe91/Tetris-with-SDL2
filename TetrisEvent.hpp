/**
 * All user event must define here
*/
#ifndef TETRIS_EVENT_HPP
#define TETRIS_EVENT_HPP
#include "engine.hpp"

//just custom user event, all event here is offset from sdlgame::USEREVENT
typedef enum
{
    TETRIMINO_MERGE = sdlgame::USEREVENT + 1,
    
} Tetris_Event;

#endif