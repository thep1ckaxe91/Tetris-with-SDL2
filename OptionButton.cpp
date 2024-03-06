#include "OptionButton.hpp"

OptionButton::OptionButton(Game &game) : Button()
{
    this->game = &game;
    this->set_images(this->game->images.option_button_idle,this->game->images.option_button_hover,this->game->images.option_button_click);
    this->image = this->idle;
    this->rect = this->image.getRect();
}
OptionButton::OptionButton(){}
void OptionButton::handle_event(Event &event){
    Button::handle_event(event);
    if(event.type == sdlgame::MOUSEBUTTONUP and this->hovering)
    {
        
    }
}
void OptionButton::update()
{
    Button::update();
}