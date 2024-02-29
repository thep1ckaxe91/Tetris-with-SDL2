#ifndef TETRIS_CONSTANT_HPP
#define TETRIS_CONSTANT_HPP
#include "engine.hpp"
using Color = sdlgame::color::Color;
using Vector2 = sdlgame::math::Vector2;
const std::string base_path = sdlgame::get_base_path();
typedef enum
{
    RESOLUTION_WIDTH = 160,
    RESOLUTION_HEIGHT = 144
} Window_Constant;
const int MAXFPS = 60;
typedef enum
{
    GRID_WIDTH = 80,
    GRID_HEIGHT = 144 + 32 //the +32 is for the area tetrimino spawn, every update only apply to those in this range
} grid_size;
typedef enum
{
    GRID_X = 16,
    GRID_Y = -32,
} grid_pos;
typedef enum
{
    EDGE_SIZE = 32,
} tetrimino_size;
const Color RED_SAND_COLOR = Color("red");
const Color GREEN_SAND_COLOR = Color("green");
const Color YELLOW_SAND_COLOR = Color("yellow");
const Color BLUE_SAND_COLOR = Color("blue");
const Vector2 spawn_pos = Vector2(24,-32);
const double fall_speed = 40; //pixel per second
const double fast_fall_speed = 140; //pps
const double sideway_move_speed = 120;//pps
const int FONT_SIZE = 5;

#endif