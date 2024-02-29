#ifndef SAND_HPP
#define SAND_HPP

#include "constant.hpp"
using Color = sdlgame::color::Color;
using namespace std;

//Bit shift for color check, not for actual color
typedef enum
{
    EMPTY_SAND = 0x0,  //0000 0000
    RED_SAND = 0x1,    //0000 0001
    YELLOW_SAND = 0x2, //0000 0010
    BLUE_SAND = 0x4,   //0000 0100
    GREEN_SAND = 0x8,  //0000 1000 
    STATIC_SAND = 0x80,//1000 0000 
} SandShift;
static map<SandShift,Color> SandShiftColor = {
    {EMPTY_SAND, Color()},
    {RED_SAND, RED_SAND_COLOR},
    {YELLOW_SAND, YELLOW_SAND_COLOR},
    {BLUE_SAND, BLUE_SAND_COLOR},
    {GREEN_SAND, GREEN_SAND_COLOR}
};
struct Sand
{
    SandShift mask;
    /*
    bitmask for fast color/collision checking
    */
    Sand(SandShift mask = EMPTY_SAND){this->mask = mask;}
};

#endif