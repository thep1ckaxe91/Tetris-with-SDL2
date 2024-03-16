#ifndef TETRIS_CONSTANT_HPP
#define TETRIS_CONSTANT_HPP
#include "engine/engine.hpp"
const std::string base_path = sdlgame::get_base_path();
typedef enum
{
    RESOLUTION_WIDTH = 160,
    RESOLUTION_HEIGHT = 144
} Window_Constant;
const int MAXFPS = 30;
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
const sdlgame::color::Color RED_SAND_COLOR = sdlgame::color::Color("crimson");
const sdlgame::color::Color GREEN_SAND_COLOR = sdlgame::color::Color("forest green");
const sdlgame::color::Color YELLOW_SAND_COLOR = sdlgame::color::Color("gold");
const sdlgame::color::Color BLUE_SAND_COLOR = sdlgame::color::Color("dodger blue");
const sdlgame::math::Vector2 spawn_pos = sdlgame::math::Vector2(40,-32);
const sdlgame::rect::Rect next_shape_display = sdlgame::rect::Rect(119,29,26,25);
const sdlgame::rect::Rect left_barrier = sdlgame::rect::Rect(8,0,8,int(RESOLUTION_HEIGHT));
const sdlgame::rect::Rect right_barrier = sdlgame::rect::Rect(16+GRID_WIDTH,0,8,int(RESOLUTION_HEIGHT));
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
typedef enum
{
    EMPTY_SAND = 0x0,  //0000 0000
    RED_SAND = 0x1,    //0000 0001
    YELLOW_SAND = 0x2, //0000 0010
    BLUE_SAND = 0x4,   //0000 0100
    GREEN_SAND = 0x8,  //0000 1000 
    STATIC_SAND = 0x80,//1000 0000 
} SandShift;
const double fall_speed = 35; //pixel per second
const double fast_fall_speed = 70; //pps
const double sideway_move_speed = 100;//pps
const int FONT_SIZE = 5;
const Vector2 score_display_center = Vector2(132,120);

#endif