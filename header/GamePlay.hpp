#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Game.hpp"
#include "Scene.hpp"
#include "TetriminoController.hpp"
#include "Grid.hpp"
class GamePlay : public Scene
{
private:
    Surface background;
    Color next_color;
    Grid grid;
    Surface score_surf;
    Font score_font;
    Rect score_rect;
public:
    GamePlay(Game &game);
    void update();
    void draw();
    void handle_event(sdlgame::event::Event &event);
};

#endif