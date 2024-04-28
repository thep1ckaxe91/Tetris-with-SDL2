#ifndef PAUSE_HPP
#define PAUSE_HPP

#include "Scene.hpp"
#include "MenuButton.hpp"
#include "RetryButton.hpp"
#include "OptionButton.hpp"
#include "BackButton.hpp"
class Pause : public Scene 
{
public:
    MenuButton menu_button;
    OptionButton option_button;
    RetryButton retry_button;
    BackButton back_button;
    Pause(Game &game);
    Pause();
    void update();
    void handle_event(Event &event);
    void draw();
};

#endif