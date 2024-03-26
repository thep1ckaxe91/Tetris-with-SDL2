#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include "Game.hpp"
#include "Scene.hpp"
#include "TetriminoController.hpp"
#include "Grid.hpp"
#include "engine/engine.hpp"
#include "Animation.hpp"
class GamePlay : public Scene
{
private:
    Vector2 bg_offset;
    Surface background;
    Color next_color;
    Grid grid;
    Surface score_surf;
    Surface next_shape_surf;
    Font score_font;
    Rect score_rect;
    SandShift next_display_color;
    Color color_flow1;
    Color color_flow2;
    Rect flow1,flow2;
    Animation change_shape;
    Animation count_down;
    bool gameover;
    int blipcount;
    const int flow_speed=48; //pps
public:
    Game *game;
    GamePlay(Game &game);
    void redraw_next_shape();
    void update();
    void draw();
    void handle_event(sdlgame::event::Event &event);
};

#endif