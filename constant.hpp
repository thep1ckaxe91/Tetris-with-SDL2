#ifndef TETRIS_CONSTANT_HPP
#define TETRIS_CONSTANT_HPP
#include "engine.hpp"
const sdlgame::math::Vector2 desktop_size = sdlgame::display::get_desktop_size();
const string base_path = sdlgame::get_base_path();
typedef enum
{
    RESOLUTION_WIDTH = 160,
    RESOLUTION_HEIGHT = 144
} Window_Constant;
const double refresh_rate = 60;
typedef enum
{
    GRID_WIDTH = 80,
    GRID_HEIGHT = 144 + 16 //the +16 is for the area tetrimino spawn, every update only apply to those in this range
} grid_size;
typedef enum
{
    GRID_X = 16,
    GRID_Y = 0,
} grid_pos;
const Color RED_SAND_COLOR = Color("red");
const Color GREEN_SAND_COLOR = Color("green");
const Color YELLOW_SAND_COLOR = Color("yellow");
const Color BLUE_SAND_COLOR = Color("blue");

const double fall_speed = 40; //pixel per second

#endif