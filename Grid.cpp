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
Grid &Grid::operator=(const Grid &other)
{
    for(int i=0;i<GRID_HEIGHT+2;i++) grid[i][0] = grid[i][GRID_WIDTH+1] = Sand(STATIC_SAND);
    for(int i=0;i<GRID_WIDTH+2;i++)  grid[0][i] = grid[GRID_HEIGHT+1][i] = Sand(STATIC_SAND);
    for(int i=1;i<=GRID_HEIGHT;i++)
        for(int j=1;j<=GRID_WIDTH;j++)
            grid[i][j] = other.grid[i][j];
    controller = other.controller;
}
void Grid::handle_event(Event &event)
{
    controller.handle_event(event);
    if(event.type == sdlgame::KEYDOWN and (event["key"]==sdlgame::K_w or event["key"]==sdlgame::K_UP))
    {
        normalize_tetrimino();
    }
}
void Grid::normalize_tetrimino()
{
    //when rotate, it possible to collide with edge, in that case, we should shift the position of the tetrimino
    for(int shift=0;shift<16;shift++)
    {
        if(controller.tetrimino.mask>>shift & 1)
        {
            while(Rect(controller.topleft+Vector2(3-shift%4,3-shift/4),8,8).colliderect(Rect(8,0,8,RESOLUTION_HEIGHT)))
            {
                controller.topleft.x += 8;
            }
            while(Rect(controller.topleft+Vector2(3-shift%4,3-shift/4),8,8).colliderect(Rect(8+GRID_WIDTH,0,8,RESOLUTION_HEIGHT)))
            {
                controller.topleft.x -= 8;
            }
        }
    }
}
void Grid::merge()
{
    //merge if collided
    for(int shift=0;shift<16;shift++)
    {
        if(controller.tetrimino.mask>>shift & 1)
        {
            Vector2 topleft = (controller.topleft+Vector2(3-shift%4,3-shift/4)) - Vector2(GRID_X,GRID_Y);
            for(int i=topleft.y-GRID_Y;i<=topleft.y-GRID_Y+8;i++)
            {
                for(int j=topleft.x;j<=topleft.x;j++)
                {
                    grid[i][j]=Sand(controller.tetrimino.color);
                }
            }
        }
    }
}
void Grid::collision_check()
{
    //check collision if the tetrimino is collided with the grid
    /*
    */
    bool called=0;
    for(int i=1;i<=GRID_HEIGHT;i++){
        if(!called)
        for(int j=1;j<=GRID_WIDTH;j++){
            if(!called)
            if(grid[i][j].mask)
            {
                for(int shift=0;shift<16;shift++)
                {
                    if(controller.tetrimino.mask>>shift & 1)
                    {
                        if(Rect(controller.topleft+Vector2(3-shift%4,3-shift/4),8,8).collidepoint(j+GRID_Y,i+GRID_X-1))
                        {
                            called=1;
                            merge();
                            break;
                        }
                    }
                }
            }
        }
    }
}
void Grid::update()
{
    this->update_timer += this->game->clock.delta_time();
    if(this->update_timer>=this->fixed_delta_time){
        this->update_timer -= this->fixed_delta_time;
        for(int i=GRID_HEIGHT;i>=1;i--){
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