#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Game.hpp"
#include "Scene.hpp"
class GamePlay : public Scene
{
public:
    GamePlay(Game &game);
    void update();
    void draw();
    void handle_event(Event &event);
};

#endif