#ifndef PERSONAL_BEST_HPP
#define PERSONAL_BEST_HPP

#include "Scene.hpp"
#include "Game.hpp"
#include "BackButton.hpp"
class PersonalBest : public Scene
{
public:
    BackButton back_button;
    PersonalBest(Game &game);
    void update();
    void draw();
    void handle_event(Event &event);
};

#endif