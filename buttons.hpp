#ifndef BUTTONS_HPP
#define BUTTONS_HPP
#include "Button.hpp"
#include "engine.hpp"
#include "Images.hpp"
#include "constant.hpp"
#include "Game.hpp"
#include "scenes.hpp"
using namespace std;
class GamePlay;
class MainMenu;
class Credit;
class GameOver;

class StartButton : public Button
{
    Game* game;
    StartButton(Game &game)
    {
        this->game = &game;
        this->set_images(this->game->images.start_button_idle,this->game->images.start_button_hover,this->game->images.start_button_click);
    }
    void handle_event(Event &event)
    {
        Button::handle_event(event);
        if(event.type == sdlgame::MOUSEBUTTONUP and this->hovering){
            OutSwipeDown *out = new OutSwipeDown();
            InSwipeDown *in = new InSwipeDown();
            GamePlay *next = new GamePlay(*this->game);
            this->game->pop_scene(out,next,in);
        }
    }
};

#endif