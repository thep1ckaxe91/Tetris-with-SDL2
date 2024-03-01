#include "Button.hpp"
#include "engine.hpp"
Button::Button()
{
    this->rect = this->image.getRect();
}
void Button::set_images(sdlgame::surface::Surface idle, sdlgame::surface::Surface hover, sdlgame::surface::Surface click){
    this->idle = this->image = idle;
    this->hover = hover;
    this->click = click;
}
template <typename... Args>
void Button::setOnClick(std::function<void(Args...)> func)
{
    onClickFunction = func;
}

template <typename... Args>
void Button::onClick(Args &&...args)
{
    if (onClickFunction)
    {
        onClickFunction(std::forward<Args>(args)...); // Forward arguments
    }
    else
    {
        throw std::invalid_argument("onclickfunciton have not set, call setOnclick to set function\n");
    }
}

void Button::handle_event(sdlgame::event::Event &event){
    if(event.type == sdlgame::MOUSEBUTTONDOWN and this->hovering)
    {
        this->image = this->click;
    }
}

void Button::update(){
    sdlgame::math::Vector2 mouse_pos = sdlgame::mouse::get_pos();
    if(this->rect.collidepoint(mouse_pos)) this->hovering = 1;
    else this->hovering = 0;
    if(!this->hovering and this->prev_hovered) this->image = this->idle;
    else if(this->hovering and !this->prev_hovered) this->image = this->hover;
    this->prev_hovered = this->hovering;
}