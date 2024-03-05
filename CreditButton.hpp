#ifndef CREDITBUTTON_HPP
#define CREDITBUTTON_HPP
#include "Button.hpp"
#include "Game.hpp"
class CreditButton : public Button
{
public:
    Game *game;
    CreditButton(Game &game);
    CreditButton();
    void handle_event(Event &event);
    void update();
};

#endif