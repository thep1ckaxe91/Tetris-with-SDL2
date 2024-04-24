#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "Scene.hpp"
#include "StartButton.hpp"
#include "QuitButton.hpp"
#include "CreditButton.hpp"
#include "engine/engine.hpp"
#include "PBButton.hpp"
class MainMenu : public Scene
{
public:
    StartButton start_button;
    QuitButton quit_button;
    CreditButton credit_button;
    PBButton pb_button;

    MainMenu(Game &game);
    void handle_event(Event &event);
    void update();
    void draw();
    ~MainMenu();
};

#endif