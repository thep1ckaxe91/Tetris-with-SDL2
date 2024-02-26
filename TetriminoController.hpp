#ifndef TETRIMINO_CONTROLLER_HPP
#define TETRIMINO_CONTROLLER_HPP
#include "engine.hpp"
#include "Tetrimino.hpp"
#include "Sand.hpp"
using namespace std;


/**
 * 
 * The controller is reponsible to check if the tetrimino is collide with any Sand yet
 * this also responsible for drawing and controlling the tetrimino movement, rotation
 * if the tetrimino is collided, the controller will send a event
 * and the scene controll the game will say to the grid to merge the Tetrimino with it
 * The grid should receive a tetrimino type object and start merging and checking
*/
class TetriminoController
{
public:
    Tetrimino tetrimino;
    TetriminoController()
    {

    }
};

#endif