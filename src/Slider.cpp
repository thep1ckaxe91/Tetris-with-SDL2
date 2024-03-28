#include "Slider.hpp"

Slider::Slider(Vector2 topleft, float value, float slide_length, float max_value)
{
    this->value = value;
    this->slide_length = slide_length;
    this->max_value = max_value;
    this->topleft = topleft;
    this->nob = Rect(0,0,3,3);
}
Slider::Slider() = default;
void Slider::update()
{
    if(holding)
    {
        nob.setCenter(
            this->topleft.y,
            sdlgame::math::clamp(
                sdlgame::mouse::get_pos().x,
                this->topleft.x,
                this->topleft.x+this->slide_length
            )
        );
        this->value = (nob.getCenterX()-topleft.x)/this->slide_length*this->max_value;
    }
}
/**
 * @brief set color for each element of the nob
 * 
 * @param nob color of the nob
 * @param valid color for the part that represent the total value
 * @param invalid color for the part that dont represent the value
 */
void Slider::set_color(Color nob, Color valid, Color invalid)
{
    nob_color =nob;
    value_color = valid;
    no_value_color = invalid;
}
void Slider::handle_event(Event &event)
{
    if(event.type == sdlgame::MOUSEBUTTONDOWN and nob.collidepoint(sdlgame::mouse::get_pos()))
    {
        holding=1;
    }
    else if(event.type == sdlgame::MOUSEBUTTONUP)
    {
        if(holding) 
            on_change_value();
        holding=0;
    }
}