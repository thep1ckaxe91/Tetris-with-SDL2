#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Scene.hpp"
#include "StartButton.hpp"
#include "engine/engine.hpp"
class MainMenu : public Scene
{
public:
    StartButton start_button;
    MainMenu(Game &game);
    void handle_event(Event &event);
    void update();
    void draw();
    ~MainMenu();
};

#endif