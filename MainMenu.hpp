#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Scene.hpp"
#include "engine.hpp"
class MainMenu : public Scene
{
public:
    void handle_event(Event &event);
    void update();
    void draw();
    ~MainMenu()=default;
};

#endif