#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Scene.hpp"
#include "StartButton.hpp"

class MainMenu : public Scene
{
public:
    StartButton *start_button;
    MainMenu(Game &game);
    void handle_event(std::any &event);
    void update();
    void draw();
    ~MainMenu();
};

#endif