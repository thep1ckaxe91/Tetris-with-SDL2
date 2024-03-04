#include "StartButton.hpp"
#include "Game.hpp"
#include "scene_transitions.hpp"
#include "GamePlay.hpp"
#include "InSwipeDown.hpp"
#include "OutSwipeDown.hpp"
#include "engine/engine.hpp"
StartButton::StartButton(Game &game) : Button()
{
    this->game = &game;
    this->set_images(this->game->images.start_button_idle,this->game->images.start_button_hover,this->game->images.start_button_click);
    
}
void StartButton::handle_event(Event &event)
{
    // if(event.type == sdlgame::MOUSEBUTTONUP and this->hovering){
    //     OutSwipeDown *out = new OutSwipeDown();
    //     InSwipeDown *in = new InSwipeDown();
    //     GamePlay *next = new GamePlay(*this->game);
    //     this->game->pop_scene(out,next,in);
    // }
}
void StartButton::update()
{

}
