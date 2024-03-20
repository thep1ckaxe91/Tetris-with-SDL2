#include "Grid.hpp"
#include "engine/engine.hpp"
#include "tetriminoes.hpp"
#include "TetrisEvent.hpp"
Grid::Grid(Game &game)
{
    this->game = &game;
    controller = TetriminoController(game, Tetriminoes::randomTetrimino());
    this->next = Tetriminoes::randomTetrimino();
    for (int i = 0; i < GRID_HEIGHT + 2; i++)
        grid[i][0] = grid[i][GRID_WIDTH + 1] = Sand(STATIC_SAND);
    for (int i = 0; i < GRID_WIDTH + 2; i++)
        grid[0][i] = grid[GRID_HEIGHT + 1][i] = Sand(STATIC_SAND);
    for (int i = 1; i <= GRID_HEIGHT; i++)
        for (int j = 1; j <= GRID_WIDTH; j++)
            grid[i][j] = Sand();
}
Grid::Grid() = default;
Grid &Grid::operator=(const Grid &other)
{
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
int Grid::get_score() { return score; }

/**
 * @brief check if is scoring anything
 *
 * @param updated_sands a list of position sand that got updated
 * @return an integer represent amount of point we get
 */
int Grid::check_scoring(std::vector<pair<int, int>> updated_sands)
{
    /**
     * @brief TODO: the complexity now is just O(n)
     * after update all position of the sand in 1 frame, bfs for all region
     *
     */
    int cnt = 0;
    queue<pair<Uint8, Uint8>> q;
    vector<pair<Uint8, Uint8>> pos;
    bitset<GRID_WIDTH + 2> visited[GRID_HEIGHT + 2];
    for (auto &[i, j] : updated_sands)
    {
        if (visited[i][j]==1)
            continue;
        visited[i][j]=1;
        vector<pair<Uint8, Uint8>> tmp;
        SandShift check_color = grid[i][j].mask;
        bool touchleft = 0, touchright = 0;
        q.push({i,j});
        while (!q.empty())
        {
            auto u = q.front();
            tmp.push_back(u);
            q.pop();
            if (u.second == 1)
                touchleft = 1;
            else if (u.second == GRID_WIDTH)
                touchright = 1;
            for (int k = 0; k < sizeof(dx) / sizeof(int); k++)
            {
                int x = dx[k] + u.first;
                int y = dy[k] + u.second;
                if (visited[x][y]==0 and grid[x][y].mask == check_color)
                {
                    q.push({x,y});
                    visited[x][y]=1;
                }
            }
        }
        if(touchleft and touchright)
        {
            for(auto &v : tmp) pos.push_back(v);
        }
    }
    if(pos.size()>0)
    {
        for(auto &[i,j] : pos)
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
    if (controller.topleft.y < 0)
    {
        sdlgame::event::post(GAMEOVER);
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
void Grid::update()
{
    this->update_timer += this->game->clock.delta_time();
    if (this->update_timer >= this->fixed_delta_time)
    {
        vector<pair<int, int>> updated_sands;
        this->update_timer -= this->fixed_delta_time;
        for (int i = GRID_HEIGHT; i >= 1; i--)
        // for (int i = 1; i <= GRID_HEIGHT; i++)
        {
            for (int j = 1; j <= GRID_WIDTH; j++)
            {
                if (grid[i][j].mask)
                {
                    if (!grid[i + 1][j].mask)
                    {
                        swap(grid[i][j], grid[i + 1][j]);
                        updated_sands.push_back({i + 1, j});
                    }
                    else if (!grid[i + 1][j - 1].mask and !grid[i][j - 1].mask)
                    {
                        swap(grid[i][j], grid[i + 1][j - 1]);
                        updated_sands.push_back({i + 1, j - 1});
                    }
                    else if (!grid[i + 1][j + 1].mask and !grid[i][j + 1].mask)
                    {
                        swap(grid[i + 1][j + 1], grid[i][j]);
                        updated_sands.push_back({i + 1, j + 1});
                    }
                }
            }
        }
        if (!updated_sands.empty())
        {
            // cout << updated_sands.size() << endl;
            score += check_scoring(updated_sands);
        }
    }
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
            if (grid[i][j].mask)
                sdlgame::draw::point(this->game->window, SandShiftColor.at(grid[i][j].mask), j + GRID_X - 1, i + GRID_Y);
            // sdlgame::draw::rect(this->game->window,SandShiftColor.at(grid[i][j].mask),Rect(j+GRID_X,i+GRID_Y,1,1));
        }
    }
    controller.draw();
}