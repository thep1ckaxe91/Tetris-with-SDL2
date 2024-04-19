#include "Grid.hpp"
#include "engine/engine.hpp"
#include "tetriminoes.hpp"
#include "TetrisEvent.hpp"
#include "crtdbg.h"
#ifdef MULTITHREADING
Sand **grid_mem_address;
void grid_mem_init()
{
    grid_mem_address = (Sand **) calloc(GRID_HEIGHT+2,sizeof(Sand *));
    for(int i=0;i<GRID_HEIGHT+2;i++)
        grid_mem_address[i] = (Sand *) calloc(GRID_WIDTH+2, sizeof(Sand));
}
#endif
Grid::Grid(Game &game)
{
    this->game = &game;
    controller = TetriminoController(game, Tetriminoes::randomTetrimino());
    this->next = Tetriminoes::randomTetrimino();
    #ifdef MULTITHREADING
    this->grid = grid_mem_address;
    
    for (int i = 0; i < GRID_HEIGHT + 2; i++)
        grid[i][0] = grid[i][GRID_WIDTH + 1] = Sand(STATIC_SAND);
    for (int i = 0; i < GRID_WIDTH + 2; i++)
        grid[0][i] = grid[GRID_HEIGHT + 1][i] = Sand(STATIC_SAND);
    for (int i = 1; i <= GRID_HEIGHT; i++)
        for (int j = 1; j <= GRID_WIDTH; j++)
            grid[i][j] = Sand();
    #else
    for (int i = 0; i < GRID_HEIGHT + 2; i++)
        grid[i][0] = grid[i][GRID_WIDTH + 1] = Sand(STATIC_SAND);
    for (int i = 0; i < GRID_WIDTH + 2; i++)
        grid[0][i] = grid[GRID_HEIGHT + 1][i] = Sand(STATIC_SAND);
    for (int i = 1; i <= GRID_HEIGHT; i++)
        for (int j = 1; j <= GRID_WIDTH; j++)
            grid[i][j] = Sand();
    #endif
}
Grid::Grid() = default;
Grid &Grid::operator=(const Grid &other)
{
    #ifdef MULTITHREADING
    this->grid = other.grid;

    this->game = other.game;
    for (int i = 0; i < GRID_HEIGHT + 2; i++)
        grid[i][0] = grid[i][GRID_WIDTH + 1] = Sand(STATIC_SAND);
    for (int i = 0; i < GRID_WIDTH + 2; i++)
        grid[0][i] = grid[GRID_HEIGHT + 1][i] = Sand(STATIC_SAND);
    for (int i = 1; i <= GRID_HEIGHT; i++)
        for (int j = 1; j <= GRID_WIDTH; j++)
            grid[i][j] = other.grid[i][j];
    controller = other.controller;
    next = other.next;
    #else

    this->game = other.game;
    for (int i = 0; i < GRID_HEIGHT + 2; i++)
        grid[i][0] = grid[i][GRID_WIDTH + 1] = Sand(STATIC_SAND);
    for (int i = 0; i < GRID_WIDTH + 2; i++)
        grid[0][i] = grid[GRID_HEIGHT + 1][i] = Sand(STATIC_SAND);
    for (int i = 1; i <= GRID_HEIGHT; i++)
        for (int j = 1; j <= GRID_WIDTH; j++)
            grid[i][j] = other.grid[i][j];
    controller = other.controller;
    next = other.next;
    #endif
    return *this;
}

void Grid::handle_event(Event &event)
{
    controller.handle_event(event);
}
void Grid::normalize_tetrimino()
{
    // when rotate, it possible to collide with edge, in that case, we should shift the position of the tetrimino
    for (int shift = 0; shift < 16; shift++)
    {
        if (controller.tetrimino.mask >> shift & 1)
        {
            Rect tmp = Rect(controller.topleft + Vector2((3 - shift % 4) * 8, (3 - shift / 4) * 8), 8, 8);
            for (int i = 0; i < 2; i++)
            {
                if (tmp.colliderect(left_barrier))
                {
                    // printf("collide left\n");
                    tmp.setLeft(left_barrier.getRight());
                    controller.topleft.x = tmp.getLeft() - (3 - shift % 4) * 8;
                }
            }
            for (int i = 0; i < 2; i++)
            {
                if (tmp.colliderect(right_barrier))
                {
                    // printf("collide right\n");
                    tmp.setRight(right_barrier.getLeft());
                    controller.topleft.x = tmp.getLeft() - (3 - shift % 4) * 8;
                }
            }
        }
    }
}
int Grid::get_score() { return score1 + score2; }

/**
 * @brief check if is scoring anything
 *
 * @param updated_sands a list of position sand that got updated
 * @return an integer represent amount of point we get
 */
int Grid::check_scoring(std::vector<pair<Uint8, Uint8>> &updated_sands)
{
    queue<pair<Uint8, Uint8>> q;
    vector<pair<Uint8, Uint8>> pos;
    bitset<GRID_WIDTH + 2> visited[GRID_HEIGHT + 2];
    for (auto &[i, j] : updated_sands)
    {
        if (visited[i][j] == 1)
            continue;
        visited[i][j] = 1;
        vector<pair<Uint8, Uint8>> tmp;
        SandShift check_color = grid[i][j].mask;
        bool touchleft = 0, touchright = 0;
        q.push({i, j});
        while (!q.empty())
        {
            auto u = q.front();
            tmp.push_back(u);
            q.pop();
            if (u.second == 1)
                touchleft = 1;
            else if (u.second == GRID_WIDTH)
                touchright = 1;
            for (int k = 0; k < (int)(sizeof(dx) / sizeof(int)); k++)
            {
                int x = dx[k] + u.first;
                int y = dy[k] + u.second;
                if (visited[x][y] == 0 and grid[x][y].mask == check_color)
                {
                    q.push({x, y});
                    visited[x][y] = 1;
                }
            }
        }
        if (touchleft and touchright)
        {
            for (auto &v : tmp)
                pos.push_back(v);
        }
    }
    if (pos.size() > 0)
    {
        for (auto &[i, j] : pos)
        {
            grid[i][j] = Sand();
        }
        sdlgame::event::post(SCORING);
    }
    return pos.size();
}

void Grid::merge()
{
    // if merge at wrong place, game over
    // a bit offset for more comfort ux
    this->game->window_draw_offset.y = 2;
    if (controller.topleft.y + 7 < 0)
    {
        sdlgame::event::post(GAMEOVER);
        this->game->window_draw_offset.y = 0;
        return;
    }
    // merge if collided
    for (int shift = 0; shift < 16; shift++)
    {
        if (controller.tetrimino.mask >> shift & 1)
        {
            Vector2 topleft = (controller.topleft + Vector2(3 - shift % 4, 3 - shift / 4) * 8) - Vector2(GRID_X, GRID_Y);
            topleft.x = int(topleft.x);
            topleft.y = int(topleft.y);
            topleft.x += 1;
            topleft.y += 1;
            for (int i = topleft.y; i < topleft.y + 8; i++)
            {
                for (int j = topleft.x; j < topleft.x + 8; j++)
                {
                    if (i <= GRID_HEIGHT)
                        grid[i][j].mask = controller.tetrimino.color;
                }
            }
        }
    }
}
void Grid::collision_check()
{
    // check collision if the tetrimino is collided with the grid
    /*
     */

    bool called = 0;
    for (int i = 1; i <= GRID_HEIGHT + 1; i++)
    {
        if (!called)
            for (int j = 1; j <= GRID_WIDTH; j++)
            {
                if (!called)
                    if (grid[i][j].mask)
                    {
                        for (int shift = 0; shift < 16; shift++)
                        {
                            if (controller.tetrimino.mask >> shift & 1)
                            {
                                Rect tmp = Rect(controller.topleft + Vector2((3 - shift % 4) * 8, (3 - shift / 4) * 8), 8, 8);
                                if (tmp.collidepoint(j + GRID_X, i + GRID_Y - 1))
                                {
                                    Vector2 check_point(j + GRID_X, i + GRID_Y);
                                    while (tmp.collidepoint(check_point))
                                    {
                                        controller.topleft.y -= 1;
                                        tmp.move_ip(0, -1);
                                        if (grid[int(check_point.y - GRID_Y - 1)][int(check_point.x - GRID_X)].mask)
                                            check_point.y--;
                                    }
                                    called = 1;
                                    merge();
                                    this->controller.reset(this->next);
                                    this->next = Tetriminoes::randomTetrimino();
                                    sdlgame::event::post(MERGING);
                                    break;
                                }
                            }
                        }
                    }
            }
    }
    // exit(0);
}

pair<Uint8, Uint8> Grid::step(int i, int j, int times)
{
    while (times--)
    {
        if (!grid[i + 1][j].mask)
        {
            swap(grid[i][j], grid[i + 1][j]);
            // return step(i+1,j,times-1);
            i++;
        }
        else if (!grid[i + 1][j - 1].mask and !grid[i][j - 1].mask)
        {
            swap(grid[i][j], grid[i][j - 1]);
            // return step(i+1,j-1,times-1);
            j--;
        }
        else if (!grid[i + 1][j + 1].mask and !grid[i][j + 1].mask)
        {
            swap(grid[i][j], grid[i][j + 1]);
            // return step(i+1,j+1,times-1);
            j++;
        }
    }
    return {i, j};
}



void Grid::update()
{
    // cout << _CrtDumpMemoryLeaks() << endl;
    // exit(0);
    this->update_timer += this->game->clock.delta_time();
    if (this->update_timer >= this->fixed_delta_time)
    {
        vector<pair<Uint8, Uint8>> updated_sands;
        this->update_timer -= this->fixed_delta_time;
        #ifndef MULTITHREADING
        for (int i = GRID_HEIGHT; i >= 1; i--)
        {
            for (int j = 1; j <= GRID_WIDTH; j++)
            {
                if (grid[i][j].mask)
                {
                    int step_times = sdlgame::random::randint(2,5);
                    pair<Uint8,Uint8> pos = this->step(i,j,step_times);
                    if(i!=pos.first or j!=pos.second) updated_sands.push_back(pos);
                }
            }
        }
        #else
        thread t[2][2];
        vector<pair<Uint8, Uint8>> res[2][2];
        for (int offset_y = 1; offset_y >= 0; offset_y--)
        {
            for (int offset_x = 0; offset_x < 2; offset_x++)
            {
                for (int i = 1; i >= 0; i--)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int top = i * GRID_HEIGHT / 2 + offset_y * GRID_HEIGHT / 4 + 1;
                        int left = j * GRID_WIDTH / 2 + offset_x * GRID_WIDTH / 4 + 1;
                        int w = GRID_WIDTH / 4;
                        int h = GRID_HEIGHT / 4;
                        t[i][j] =
                            thread(update_part, top, left, w, h, std::ref(res[i][j]));
                    }
                }
                for (int i = 1; i >= 0; i--)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        t[i][j].join();
                        updated_sands.insert(updated_sands.end(), res[i][j].begin(), res[i][j].end());
                    }
                }
            }
        }
        #endif
        if (!updated_sands.empty())
        {
            int added = check_scoring(updated_sands);
            if (added > 0)
            {
                int split = sdlgame::random::randint(2, added - 2);
                score1 += split;
                score2 += added - split;
            }
        }
    }
    if (this->game->window_draw_offset.y != 0)
        this->game->window_draw_offset.y--;
    controller.update();
    normalize_tetrimino();
    collision_check();
}
void Grid::draw()
{
    for (int i = 1; i <= GRID_HEIGHT; i++)
    {
        for (int j = 1; j <= GRID_WIDTH; j++)
        {
            #ifndef MULTITHREADING
            if (grid[i][j].mask)
                sdlgame::draw::point(
                    this->game->window,
                    SandShiftColor.at(grid[i][j].mask).add_value(
                        grid[i][j].color_offset_rgb >>4 & 15,
                        grid[i][j].color_offset_rgb >>2 & 15,
                        grid[i][j].color_offset_rgb     & 15),
                     j + GRID_X - 1, i + GRID_Y
                );
            #else
            if (grid[i][j].mask)
                sdlgame::draw::point(
                    this->game->window,
                    SandShiftColor.at(grid[i][j].mask).add_value(
                        grid[i][j].color_offset_rgb >>4 & 15,
                        grid[i][j].color_offset_rgb >>2 & 15,
                        grid[i][j].color_offset_rgb     & 15),
                     j + GRID_X - 1, i + GRID_Y
                );
            #endif
            // sdlgame::draw::rect(this->game->window,SandShiftColor.at(grid[i][j].mask),Rect(j+GRID_X,i+GRID_Y,1,1));
        }
    }
    controller.draw();
}

#ifdef MULTITHREADING
pair<Uint8, Uint8> Grid::step(int i, int j, int times)
{
    while (times--)
    {
        if (!grid_mem_address[i + 1][j].mask)
        {
            swap(grid_mem_address[i][j], grid_mem_address[i + 1][j]);
            // return step(i+1,j,times-1);
            i++;
        }
        else if (!grid_mem_address[i + 1][j - 1].mask and !grid_mem_address[i][j - 1].mask)
        {
            swap(grid_mem_address[i][j], grid_mem_address[i][j - 1]);
            // return step(i+1,j-1,times-1);
            j--;
        }
        else if (!grid_mem_address[i + 1][j + 1].mask and !grid_mem_address[i][j + 1].mask)
        {
            swap(grid_mem_address[i][j], grid_mem_address[i][j + 1]);
            // return step(i+1,j+1,times-1);
            j++;
        }
    }
    return {i, j};
}

void update_part(const int top, const int left, const int width, const int height, vector<pair<Uint8, Uint8>> &updated)
{
    for (int i = top + height - 1; i >= top; i--)
    {
        for (int j = left; j < left + width; j++)
        {
            if (grid_mem_address[i][j].mask)
            {
                int step_times = sdlgame::random::randint(2, 5);
                pair<Uint8, Uint8> pos = step(i, j, step_times);
                if (i != pos.first or j != pos.second)
                    updated.push_back(pos);
            }
        }
    }
}

#endif