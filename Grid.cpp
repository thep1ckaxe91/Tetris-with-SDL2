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
            for(int i=topleft.y-GRID_Y;i<=topleft.y-GRID_Y+8;i++)
            {
                for(int j=topleft.x;j<=topleft.x;j++)
                {
                    grid[i][j]=Sand(controller.tetrimino.color);
                }
            }
        }
    }
    /**
     * TODO: collision is good now, the thing that not good is the merge, nothing merged when collide
     * TODO: fix merge
    */
    controller.reset(Tetriminoes::randomTetrimino());
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
                cout << i << j << endl;
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
    normalize_tetrimino();
    collision_check();
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
    auto keys = sdlgame::key::get_pressed();
    if(keys[sdlgame::K_r])controller.reset(Tetriminoes::randomTetrimino());

    this->game->window.blit(debug_surf,Vector2());

    // sdlgame::draw::rect(this->game->window,"red",Rect(controller.topleft,32,32),1);
    
    // sdlgame::draw::rect(this->game->window,"red",left_barrier,1);
    // sdlgame::draw::rect(this->game->window,"red",right_barrier,1);

    // sdlgame::draw::line(this->game->window,"blue",Vector2(GRID_X,0),Vector2(GRID_X,GRID_HEIGHT));
    // sdlgame::draw::line(this->game->window,"blue",Vector2(GRID_X+GRID_WIDTH,0),Vector2(GRID_X+GRID_WIDTH,GRID_HEIGHT));
    // for(int shift=0;shift<16;shift++)
    // {
    //     if(controller.tetrimino.mask>>shift & 1)
    //     {
    //         Rect tmp = Rect(controller.topleft+Vector2((3-shift%4)*8,(3-shift/4)*8),8,8);
    //         sdlgame::draw::rect(this->game->window,"white",tmp,1);
    //     }
    // }
}