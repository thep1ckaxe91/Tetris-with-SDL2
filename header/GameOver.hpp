#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "Scene.hpp"
#include "engine/engine.hpp"
#include "MenuButton.hpp"
#include "RetryButton.hpp"

class GameOver : public Scene
{
    MenuButton menu;
    RetryButton retry;
    Font score_font;
    Surface new_score_surf;
    Surface pb_surf;
    int new_score;
public:
    GameOver(Game &game, int new_score);
    void handle_event(Event &event);
    void update();
    void draw();
};
#endif