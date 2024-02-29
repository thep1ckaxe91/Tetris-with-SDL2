#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Scene.hpp"
#include "engine.hpp"
#include "buttons.hpp"
#include "StartButton.hpp"
class MainMenu : public Scene
{
public:
    StartButton *start_button;
    MainMenu(Game &game);
    void handle_event(Event &event);
    void update();
    void draw();
};

#endif