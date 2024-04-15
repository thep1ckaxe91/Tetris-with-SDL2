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
    int score1 = 0, score2 = 0;

public:
    // Sand grid[GRID_HEIGHT + 2][GRID_WIDTH + 2];
    vector<vector<Sand>> grid;
    Tetrimino next;
    vector<pair<Uint8, Uint8>> pos;
    Surface vfx_mask;
    bool vfx_show;
    Game *game;
    const double fixed_delta_time = 0.07;
    TetriminoController controller;
    Grid(Game &game);
    Grid();
    Grid &operator=(const Grid &other);
    void collision_check();
    void normalize_tetrimino();
    void merge();
    int get_score();
    int check_scoring(std::vector<pair<Uint8, Uint8>> &updated_sands);
    void handle_event(Event &event);
    void update();
    void draw();

    //multithreading optimization
    void update_part(int top, int left, int width, int height, vector<pair<Uint8,Uint8>> &updated,const vector<vector<Sand>> *grid);

    // these function should make the sand fall better somehow

    pair<Uint8,Uint8> step(int i,int j, int times);

};

#endif