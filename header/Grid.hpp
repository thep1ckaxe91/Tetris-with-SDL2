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
    int score=0;
public:
    /*
    Array for grid control
    */
    Sand grid[GRID_HEIGHT+2][GRID_WIDTH+2];
    Tetrimino next;
#ifdef OPTIMIZE_CHECK
    int left_parent[GRID_HEIGHT*GRID_WIDTH+2];
    int right_parent[GRID_HEIGHT*GRID_WIDTH+2];
    int left_size[GRID_HEIGHT*GRID_WIDTH+2];
    int right_size[GRID_HEIGHT*GRID_WIDTH+2];
#endif
    Game* game;
    const double fixed_delta_time = 0.07;
    TetriminoController controller;
    Grid(Game &game);
    Grid();
    Grid &operator=(const Grid& other);
    void collision_check();
    bool is_same_area(int i1,int j1, int i2,int j2);
    void normalize_tetrimino();
    void merge();
    int get_score();
    int check_scoring(std::vector<pair<int,int>> updated_sands);
    void game_over();

    void handle_event(Event &event);
    void update();
    void draw();
};


#endif