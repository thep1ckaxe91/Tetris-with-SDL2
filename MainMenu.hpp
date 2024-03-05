#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Scene.hpp"
#include "StartButton.hpp"
#include "engine/engine.hpp"
class MainMenu : public Scene
{
public:
    StartButton start_button;
    
    Vector2 start_button_pos;
    Vector2 quit_button_pos;
    Vector2 credit_button_pos;
    MainMenu(Game &game);
    void handle_event(Event &event);
    void update();
    void draw();
    ~MainMenu();
};

#endif