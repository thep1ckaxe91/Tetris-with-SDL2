#include "Button.hpp"
#include "engine/engine.hpp"
Button::Button()
{
    hovering = prev_hovered = 0;
}
void Button::set_images(Surface &idle, Surface &hover,Surface &click){
    this->idle = idle;
    this->hover = hover;
    this->click = click;
    this->image = idle;
}

void Button::handle_event(Event &event){
    if(event.type == sdlgame::MOUSEBUTTONDOWN and this->hovering)
    {
        this->image = this->click;
    }
}

void Button::update(){
    sdlgame::math::Vector2 mouse_pos = sdlgame::mouse::get_pos();
    if(this->rect.collidepoint(mouse_pos)) this->hovering = 1;
    else this->hovering = 0;
    if(!this->hovering and this->prev_hovered){
        this->image = this->idle;
    }
    else if(this->hovering and !this->prev_hovered){
        this->image = this->hover;
    }
    this->prev_hovered = this->hovering;
}