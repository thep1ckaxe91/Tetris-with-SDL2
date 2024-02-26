#ifndef SAND_HPP
#define SAND_HPP
#include "engine.hpp"
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
struct Sand
{
    Uint8 mask;
    /*
    bitmask for fast color/collision checking
    */
    Sand(Uint8 mask = 0){this->mask = mask;}
};

#endif