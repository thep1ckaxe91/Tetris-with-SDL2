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
public:
    /*
    Array for grid control
    */
    Sand grid[GRID_HEIGHT+2][GRID_WIDTH+2];
    Game* game;
    const double fixed_delta_time = 0.02;
    TetriminoController controller;
    Grid(Game &game)
    {
        this->game = &game;
        controller = TetriminoController(game,Tetriminoes::randomTetrimino());
        for(int i=0;i<GRID_HEIGHT+2;i++) grid[i][0] = grid[i][GRID_WIDTH+1] = Sand(STATIC_SAND);
        for(int i=0;i<GRID_WIDTH+2;i++)  grid[0][i] = grid[GRID_HEIGHT+1][i] = Sand(STATIC_SAND);
        for(int i=1;i<=GRID_HEIGHT;i++)
            for(int j=1;j<=GRID_WIDTH;j++)
                grid[i][j] = Sand();
    }
    void handle_event(Event &event)
    {
        controller.handle_event(event);
    }
    void update()
    {
        this->update_timer += this->game->clock.delta_time();
        if(this->update_timer>=this->fixed_delta_time){
            this->update_timer -= this->fixed_delta_time;
            for(int i=1;i<=GRID_HEIGHT;i++){
                for(int j=1;j<=GRID_WIDTH;j++){
                    if(!grid[i+1][j].mask)
                    {
                        swap(grid[i][j],grid[i+1][j]);
                    }
                    else if(!grid[i+1][j-1].mask){
                        swap(grid[i][j],grid[i+1][j-1]);
                    }
                    else if(!grid[i+1][j+1].mask){
                        swap(grid[i+1][j+1],grid[i][j]);
                    }
                }
            }
        }
        controller.update();
    }
    void draw()
    {
        for(int i=1;i<=GRID_HEIGHT;i++)
        {
            for(int j=1;j<=GRID_WIDTH;j++)
            {
                sdlgame::draw::point(this->game->window,SandShiftColor[grid[i][j].mask],j+GRID_X,i+GRID_Y);
            }
        }
        controller.draw();
    }
};


#endif