#ifndef OPTIONBUTTON_HPP
#define OPTIONBUTTON_HPP
#include "Button.hpp"
#include "Game.hpp"
class OptionButton : public Button 
{
public:
    Game *game;
    OptionButton(Game &game);
    OptionButton();
    void handle_event(Event &event);
    void update();
};

#endif