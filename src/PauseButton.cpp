#include "PauseButton.hpp"
PauseButton::PauseButton(Game &game)
{
    this->game = &game;
    this->set_images(this->game->images.pause_button_idle,this->game->images.pause_button_hover,this->game->images.pause_button_click);
    this->image = this->idle;
    this->rect = this->image.getRect();
}
PauseButton::PauseButton()=default;
void PauseButton::update()
{
    Button::update();
}
void PauseButton::handle_event(Event &event)
{
    Button::handle_event(event);
}
void on_click()
{
    
}