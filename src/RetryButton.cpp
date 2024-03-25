#include "RetryButton.hpp"
#include "OutSwipeDown.hpp"
#include "InSwipeDown.hpp"
#include "GamePlay.hpp"
RetryButton::RetryButton(Game &game)
{
    this->game = &game;
    this->set_images(this->game->images.retry_button_idle,this->game->images.retry_button_hover, this->game->images.retry_button_click);
}
RetryButton::RetryButton()=default;
void RetryButton::handle_event(Event &event)
{
    Button::handle_event(event);
}
void RetryButton::on_click()
{
    OutSwipeDown *out = new OutSwipeDown();
    InSwipeDown *in = new InSwipeDown();
    GamePlay *next = new GamePlay(*game);
    this->game->pop_scene(out,next,in);
}
void RetryButton::update()
{
    Button::update();
}
