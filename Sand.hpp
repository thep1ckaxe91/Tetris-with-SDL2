#ifndef SAND_HPP
#define SAND_HPP
#include <map>
#include "constant.hpp"
using Color = sdlgame::color::Color;
using namespace std;

//Bit shift for color check, not for actual color

extern map<SandShift,Color> SandShiftColor;
struct Sand
{
    SandShift mask;
    /*
    bitmask for fast color/collision checking
    */
    Sand(SandShift mask = EMPTY_SAND);
};

#endif