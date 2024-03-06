#ifndef CREDIT_HPP
#define CREDIT_HPP
#include "Scene.hpp"
#include "BackButton.hpp"
class Credit : public Scene
{
public:
    BackButton back_button;
    Game *game;
    Credit(Game &game);
    void handle_event(Event &event);
    void update();
    void draw();
};

#endif