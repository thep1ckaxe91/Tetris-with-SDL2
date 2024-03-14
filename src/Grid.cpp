#include "Grid.hpp"
#include "engine/engine.hpp"
#include "tetriminoes.hpp"
Grid::Grid(Game &game)
{
    this->game = &game;
    controller = TetriminoController(game,Tetriminoes::randomTetrimino());
    for(int i=0;i<GRID_HEIGHT+2;i++) grid[i][0] = grid[i][GRID_WIDTH+1] = Sand(STATIC_SAND);
    for(int i=0;i<GRID_WIDTH+2;i++)  grid[0][i] = grid[GRID_HEIGHT+1][i] = Sand(STATIC_SAND);
    for(int i=1;i<=GRID_HEIGHT;i++)
        for(int j=1;j<=GRID_WIDTH;j++)
            grid[i][j] = Sand();
    debug_surf = Surface(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);
}
Grid::Grid() = default;
Grid &Grid::operator=(const Grid &other)
{
    this->game = other.game;
    for(int i=0;i<GRID_HEIGHT+2;i++) grid[i][0] = grid[i][GRID_WIDTH+1] = Sand(STATIC_SAND);
    for(int i=0;i<GRID_WIDTH+2;i++)  grid[0][i] = grid[GRID_HEIGHT+1][i] = Sand(STATIC_SAND);
    for(int i=1;i<=GRID_HEIGHT;i++)
        for(int j=1;j<=GRID_WIDTH;j++)
            grid[i][j] = other.grid[i][j];
    controller = other.controller;
    debug_surf = other.debug_surf;
    return *this;
}
void Grid::handle_event(Event &event)
{
    controller.handle_event(event);
}
void Grid::normalize_tetrimino()
{
    //when rotate, it possible to collide with edge, in that case, we should shift the position of the tetrimino
    for(int shift=0;shift<16;shift++)
    {
        if(controller.tetrimino.mask>>shift & 1)
        {
            Rect tmp = Rect(controller.topleft+Vector2((3-shift%4)*8,(3-shift/4)*8),8,8);
            for(int i=0;i<2;i++) 
            {
                if(tmp.colliderect(left_barrier))
                {
                    // printf("collide left\n");
                    tmp.setLeft(left_barrier.getRight());
                    controller.topleft.x = tmp.getLeft() - (3-shift%4)*8;
                }
            }
            for(int i=0;i<2;i++)
            {
                if(tmp.colliderect(right_barrier))
                {
                    // printf("collide right\n");
                    tmp.setRight(right_barrier.getLeft());
                    controller.topleft.x = tmp.getLeft() - (3-shift%4)*8;
                }
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
            Vector2 topleft = (controller.topleft+Vector2(3-shift%4,3-shift/4)*8) - Vector2(GRID_X,GRID_Y);
            topleft.x = int(topleft.x); topleft.y = int(topleft.y);
            topleft.x+=1; topleft.y+=1;
            for(int i=topleft.y;i<topleft.y+8;i++)
            {
                for(int j=topleft.x;j<topleft.x+8;j++)
                {
                    grid[i][j].mask = controller.tetrimino.color;
                }
            }
        }
    }
    controller.reset(Tetriminoes::randomTetrimino());
    merged = 1;
    /**
     * TODO: collision is good now, the thing that not good is the merge, nothing merged when collide
     * TODO: fix merge
    */
}
void Grid::collision_check()
{
    //check collision if the tetrimino is collided with the grid
    /*
    */
    
    bool called=0;
    for(int i=1;i<=GRID_HEIGHT+1;i++){
        if(!called)
        for(int j=1;j<=GRID_WIDTH;j++){
            if(!called)
            if(grid[i][j].mask)
            {
                for(int shift=0;shift<16;shift++)
                {
                    if(controller.tetrimino.mask>>shift & 1)
                    {
                        Rect tmp = Rect(controller.topleft+Vector2((3-shift%4)*8,(3-shift/4)*8),8,8);
                        if(tmp.collidepoint(j+GRID_X,i+GRID_Y-1))
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
    // exit(0);
}
void Grid::update()
{
    this->update_timer += this->game->clock.delta_time();
    if(this->update_timer>=this->fixed_delta_time){
        this->update_timer -= this->fixed_delta_time;
        for(int i=GRID_HEIGHT;i>=1;i--){
            for(int j=1;j<=GRID_WIDTH;j++){
                if(grid[i][j].mask)
                {
                    if(!grid[i+1][j].mask)
                    {
                        swap(grid[i][j],grid[i+1][j]);
                    }
                    else if(!grid[i+1][j-1].mask and !grid[i][j-1].mask){
                        swap(grid[i][j],grid[i+1][j-1]);
                    }
                    else if(!grid[i+1][j+1].mask and !grid[i][j+1].mask){
                        swap(grid[i+1][j+1],grid[i][j]);
                    }
                }
            }
        }
    }
    controller.update();
    normalize_tetrimino();
    collision_check();
}
void Grid::draw()
{
    for(int i=1;i<=GRID_HEIGHT;i++)
    {
        for(int j=1;j<=GRID_WIDTH;j++)
        {
            if(grid[i][j].mask) sdlgame::draw::point(this->game->window,SandShiftColor.at(grid[i][j].mask),j+GRID_X,i+GRID_Y);
            // sdlgame::draw::rect(this->game->window,SandShiftColor.at(grid[i][j].mask),Rect(j+GRID_X,i+GRID_Y,1,1));
        }
    }
    controller.draw();
}