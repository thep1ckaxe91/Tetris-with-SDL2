#ifndef GRID_HPP
#define GRID_HPP
#include "Sand.hpp"

#include "constant.hpp"
#include "Tetrimino.hpp"
#include "tetriminoes.hpp"
#include "TetriminoController.hpp"
#include "Game.hpp"
using namespace std;

/**
 * Yes, the array start from 1, the rest is the border
*/
class Grid
{
private:
    double update_timer = 0;
    Surface debug_surf;
public:
    /*
    Array for grid control
    */
    Sand grid[GRID_HEIGHT+2][GRID_WIDTH+2];
    Game* game;
    const double fixed_delta_time = 0.1;
    TetriminoController controller;
    Grid(Game &game);
    Grid();
    Grid &operator=(const Grid& other);
    void collision_check();
    void normalize_tetrimino();
    void merge();
    void handle_event(Event &event);
    void update();
    void draw();
};


#endif