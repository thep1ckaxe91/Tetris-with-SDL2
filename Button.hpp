#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;

//call handle event for button update, also, you need to add click to call function your self
class Button : public sdlgame::sprite::Sprite
{
public:
    Surface idle, hover, click;
    bool hovering = 0,prev_hovered = 0;
    function<void()> onClickFunction;
    Button();
    void set_images(Surface idle, Surface hover, Surface click);
    template <typename... Args>
    void setOnClick(function<void(Args...)> func);
    template <typename... Args>
    void onClick(Args &&...args);

    virtual void handle_event(Event &event);

    virtual void update();
};

#endif