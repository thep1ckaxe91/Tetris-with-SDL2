#ifndef GRID_HPP
#define GRID_HPP
#include "Sand.hpp"
#include "engine.hpp"
#include "constant.hpp"
#include "Tetrimino.hpp"
using namespace std;

/**
 * Yes, the array start from 1, the rest is the border
*/
class Grid
{
public:
    /*
    Array for grid control
    */
    Sand grid[GRID_HEIGHT+2][GRID_WIDTH+2];

    Grid()
    {
        for(int i=0;i<GRID_HEIGHT+2;i++) grid[i][0] = grid[i][GRID_WIDTH+1] = Sand(STATIC_SAND);
        for(int i=0;i<GRID_WIDTH+2;i++)  grid[0][i] = grid[GRID_HEIGHT+1][i] = Sand(STATIC_SAND);
        for(int i=1;i<=GRID_HEIGHT;i++)
            for(int j=1;j<=GRID_WIDTH;j++)
                grid[i][j] = Sand();
    }
    void update()
    {
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
    void draw()
    {

    }
};


#endif