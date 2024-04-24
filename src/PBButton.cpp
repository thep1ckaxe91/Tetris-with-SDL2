#include "PBButton.hpp"

PBButton::PBButton(Game &game)
{
    this->game = &game;
    this->set_images(this->game->images.pb_button_idle,this->game->images.pb_button_hover,this->game->images.pb_button_click);
    this->image = this->idle;
    this->rect = this->image.getRect();
}
PBButton::PBButton() = default;
void PBButton::on_click()
{
    
}

void PBButton::update()
{
    Button::update();
}

void PBButton::handle_event(Event &event)
{
    Button::handle_event(event);
}