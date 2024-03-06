#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Game.hpp"
#include "Scene.hpp"
class GamePlay : public Scene
{
private:
    Surface background;
public:
    GamePlay(Game &game);
    void update();
    void draw();
    void handle_event(sdlgame::event::Event &event);
};

#endif