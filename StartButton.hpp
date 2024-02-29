#ifndef STARTBUTTON_HPP
#define STARTBUTTON_HPP
#include "Button.hpp"
class StartButton : public Button
{
public:
    Game* game;
    StartButton(Game &game);
    void handle_event(Event &event);
    void update();
};

#endif