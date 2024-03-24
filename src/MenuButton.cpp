#include "MenuButton.hpp"
#include "OutSwipeDown.hpp"
#include "InSwipeDown.hpp"
#include "MainMenu.hpp"
MenuButton::MenuButton(Game &game)
{
    this->game = &game;
    this->set_images(this->game->images.menu_button_idle,this->game->images.menu_button_hover, this->game->images.menu_button_click);
}
MenuButton::MenuButton()=default;
void MenuButton::handle_event(Event &event)
{
    Button::handle_event(event);
    if(hovering and event.type == sdlgame::MOUSEBUTTONUP)
    {
        OutSwipeDown *out = new OutSwipeDown();
        InSwipeDown *in = new InSwipeDown();
        MainMenu *next = new MainMenu(*game);
        this->game->pop_scene(out,next,in);
    }
}
void MenuButton::update()
{
    Button::update();
}