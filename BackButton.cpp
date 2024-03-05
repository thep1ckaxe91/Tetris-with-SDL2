#include "BackButton.hpp"
#include "Game.hpp"

BackButton::BackButton(Game &game)
{
    this->game = &game;
    this->set_images(this->game->images.back_button_idle,this->game->images.back_button_hover,this->game->images.back_button_click);
    this->image = this->idle;
    this->rect = this->image.getRect();
}
BackButton::BackButton(){}
void BackButton::handle_event(Event &event)
{
    Button::handle_event(event);
    if(event.type == sdlgame::MOUSEBUTTONUP and this->hovering)
    {
        this->game->remove_scene();
    }
}
void update();