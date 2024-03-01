#include "StartButton.hpp"
#include "Game.hpp"
#include "scene_transitions.hpp"
#include "GamePlay.hpp"
#include "InSwipeDown.hpp"
#include "OutSwipeDown.hpp"
using Surface = sdlgame::surface::Surface;
StartButton::StartButton(Game &game) : Button()
{
    this->game = &game;
    this->set_images(this->game->images.start_button_idle,this->game->images.start_button_hover,this->game->images.start_button_click);
    
}
void StartButton::set_images(Surface &idle, Surface &hover, Surface &click)
{
    this->idle = std::any_cast<Surface>(idle); this->hover = hover; this->click = click;
}
void StartButton::handle_event(sdlgame::event::Event &event)
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
