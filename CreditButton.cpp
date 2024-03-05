#include "CreditButton.hpp"
#include "engine/engine.hpp"
#include "InSwipeDown.hpp"
#include "OutSwipeDown.hpp"

CreditButton::CreditButton(Game &game) : Button()
{
    this->game = &game;
    this->set_images(this->game->images.credit_button_idle,this->game->images.credit_button_hover,this->game->images.credit_button_click);
    this->image = this->idle;
    this->rect = this->image.getRect();
}
CreditButton::CreditButton(){}
void CreditButton::handle_event(Event &event)
{
    Button::handle_event(event);
    if(event.type == sdlgame::MOUSEBUTTONUP and this->hovering)
    {
        OutSwipeDown *out = new OutSwipeDown();
        InSwipeDown *in = new InSwipeDown();
        GamePlay *next = new GamePlay(*this->game);
        this->game->pop_scene(out,next,in);
    }
}
void CreditButton::update()
{
    Button::update();
}