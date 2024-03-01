#ifndef STARTBUTTON_HPP
#define STARTBUTTON_HPP
#include "Game.hpp"
#include "Button.hpp"
class sdlgame::event::Event;
class sdlgame::surface::Surface;
class StartButton : public Button
{
public:
    Game* game;
    bool hovering = 0;
    StartButton(Game &game);
    void handle_event(std::any &event);
    void update();
    void set_images(std::any &idle, std::any &hover, std::any &click);
};

#endif
/**
 * TODO: Decide between redesign Button or make a Pimpl for Surface
 * APPROACH: try redesign first
*/