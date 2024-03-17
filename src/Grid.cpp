#include "Grid.hpp"
#include "engine/engine.hpp"
#include "tetriminoes.hpp"
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

#ifdef OPTIMIZE_CHECK
    // init optimization utils
    memset(left_parent, -1, sizeof(left_parent));
    memset(right_parent, -1, sizeof(right_parent));
    memset(left_size, 0x1, sizeof(left_size));
    memset(right_size, 0x1, sizeof(right_size));
#endif
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
#ifdef OPTIMIZE_CHECK
    memcpy(left_parent, other.left_parent, sizeof(left_parent));
    memcpy(right_parent, other.right_parent, sizeof(right_parent));
    memcpy(left_size, other.left_size, sizeof(left_size));
    memcpy(right_size, other.right_size, sizeof(right_size));
#endif
    return *this;
}

// under is all optimization function to check if it need to score;
#ifdef OPTIMIZE_CHECK
int Grid::gridpos_to_node(int i, int j)
{
    return (i - 1) * GRID_WIDTH + j;
}
pair<int, int> Grid::node_to_gridpos(int node)
{
    return pair(node / GRID_WIDTH + 1, node % GRID_WIDTH + (node % GRID_WIDTH == 0));
}
int Grid::find_left(int u)
{
    return (left_parent[u] == -1 ? u : left_parent[u] = find_left(u));
}
int Grid::find_right(int u)
{
    return (right_parent[u] == -1 ? u : right_parent[u] = find_right(u));
}
//seperate a node from any union
void Grid::isolate(int u)
{
    int parl = find_left(u), parr = find_right(u);
    left_parent[u] = right_parent[u] = -1;
    left_size[parl]--; right_size[parr]--;
}
//join a and b node to a left most union
void Grid::left_join(int a, int b)
{
    a = find_left(a);
    b = find_left(b);
    if(a!=b)
    {//check if a or b is most on the left, if b is more to the left, swap a/b
        if(node_to_gridpos(a).second > node_to_gridpos(b).second) swap(a,b);
        left_parent[b]=a;
        left_size[a]+=left_size[b];
    }
}
//join a and b node to a right most union
void Grid::right_join(int a, int b)
{
    a = find_right(a);
    b = find_right(b);
    if(a!=b)
    {

    }
}
#endif
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
int Grid::check_scoring(int cposi, int cposj)
{
    /**
     * TODO: the check scoring only happen when the controller is collided, not when the sand fall and update with it
     * APPROACH: nvm, it fast enough
     *
     */
    SandShift check_color = grid[cposi][cposj].mask;

    if (check_color == EMPTY_SAND or check_color == STATIC_SAND)
    {
        return 0;
    }
    queue<pair<Uint8, Uint8>> q;
    bitset<GRID_WIDTH + 2> visited[GRID_HEIGHT + 2];
    q.push({cposi, cposj});
    vector<pair<Uint8, Uint8>> pos;
    int cnt = 0;
    bool touchleft = 0, touchright = 0;
    visited[cposi][cposj] = 1;
    while (!q.empty())
    {
        auto u = q.front();
        pos.push_back(u);
        if (u.second == 1)
            touchleft = 1;
        else if (u.second == GRID_WIDTH)
            touchright = 1;
        visited[u.first][u.second] = 1;
        cnt++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (visited[x][y] == 0 and grid[x][y].mask == check_color)
            {
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    if (touchleft and touchright)
    {
        for (auto &val : pos)
            grid[val.first][val.second] = Sand();
        return cnt;
    }
    return 0;
}
void Grid::game_over()
{
    /**
     * TODO: do a proper game over
     */
    for (int i = 1; i <= GRID_HEIGHT; i++)
        for (int j = 1; j <= GRID_WIDTH; j++)
            grid[i][j].mask = EMPTY_SAND;
    controller.reset(Tetriminoes::randomTetrimino());
}
void Grid::merge()
{
    // if merge at wrong place, game over
    if (controller.topleft.y < 0)
    {
        game_over();
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
                        score += check_scoring(i + 1, j);
                    }
                    else if (!grid[i + 1][j - 1].mask and !grid[i][j - 1].mask)
                    {
                        swap(grid[i][j], grid[i + 1][j - 1]);
                        score += check_scoring(i + 1, j - 1);
                    }
                    else if (!grid[i + 1][j + 1].mask and !grid[i][j + 1].mask)
                    {
                        swap(grid[i + 1][j + 1], grid[i][j]);
                        score += check_scoring(i + 1, j + 1);
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