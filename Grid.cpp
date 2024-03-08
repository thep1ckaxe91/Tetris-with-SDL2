#include "Grid.hpp"

Grid::Grid(Game &game)
{
    this->game = &game;
    controller = TetriminoController(game,Tetriminoes::randomTetrimino());
    for(int i=0;i<GRID_HEIGHT+2;i++) grid[i][0] = grid[i][GRID_WIDTH+1] = Sand(STATIC_SAND);
    for(int i=0;i<GRID_WIDTH+2;i++)  grid[0][i] = grid[GRID_HEIGHT+1][i] = Sand(STATIC_SAND);
    for(int i=1;i<=GRID_HEIGHT;i++)
        for(int j=1;j<=GRID_WIDTH;j++)
            grid[i][j] = Sand();
}
Grid::Grid() = default;
void Grid::handle_event(Event &event)
{
    controller.handle_event(event);
}
void Grid::merge()
{
    //merge if collided
}
void Grid::collision_check()
{
    //check collision if the tetrimino is collided with the grid
    /*
    
    */
}
void Grid::update()
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
        controller.update();
        collision_check();
    }
}
void Grid::draw()
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