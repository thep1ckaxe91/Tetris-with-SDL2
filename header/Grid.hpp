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
    /*
    Array for grid control (cellular automata)
    */
    Sand grid[GRID_HEIGHT + 2][GRID_WIDTH + 2];
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
    int check_scoring(std::vector<pair<int, int>> updated_sands);
    void handle_event(Event &event);
    void update();
    void draw();

    //multithreading potimization
    void update(int top, int left, int width, int height, vector<pair<int,int>> &updated);

    // these function should make the sand fall better somehow

    pair<int,int> step(int i,int j, int times);

};

#endif