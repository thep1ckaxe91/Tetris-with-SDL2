#ifndef QUITBUTTON_HPP
#define QUITBUTTON_HPP
#include "Button.hpp"
#include "Game.hpp"
class QuitButton : public Button
{
    Game *game;
    QuitButton(Game &game);
    void handle_event(Event &event);
    void update();
};

#endif