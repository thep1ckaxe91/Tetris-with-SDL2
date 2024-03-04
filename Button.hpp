#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "engine/engine.hpp"
class Button : sdlgame::sprite::Sprite
{
public:
    Surface idle;
    Surface hover;
    Surface click;
    bool hovering, prev_hovered;
    Button();
    void set_images(Surface &idle, Surface &hover, Surface &click);
    virtual void handle_event(Event &event);
    virtual void update();

};

#endif