#ifndef STARTBUTTON_HPP
#define STARTBUTTON_HPP
#include "Game.hpp"
#include "Button.hpp"
class StartButton : public Button
{
public:
    Game* game;
    StartButton(Game &game);
    StartButton();
    void handle_event(Event &event);
    void update();
};

#endif
/**
 * TODO: Decide between redesign Button or make a Pimpl for Surface
 * APPROACH: remake the engine by seperate the file into cpp and hpp into a engine folder
*/