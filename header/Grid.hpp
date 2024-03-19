#ifndef GRID_HPP
#define GRID_HPP
#include "Sand.hpp"
#include "constant.hpp"
#include "Tetrimino.hpp"
#include "tetriminoes.hpp"
#include "TetriminoController.hpp"
#include "Game.hpp"
using namespace std;
// #define OPTIMIZE_CHECK 1

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
    void normalize_tetrimino();
    void merge();
    int get_score();
    int check_scoring(int cposi,int cposj);
    void game_over();
    //under is all optimization function to check if it need to score;
#ifdef OPTIMIZE_CHECK
    int gridpos_to_node(int i,int j);
    std::pair<int,int> node_to_gridpos(int node);
    int find_left(int u);
    int find_right(int u);
    void isolate(int u);
    void left_join(int a,int b);
    void right_join(int a,int b);
#endif

    void handle_event(Event &event);
    void update();
    void draw();
};


#endif