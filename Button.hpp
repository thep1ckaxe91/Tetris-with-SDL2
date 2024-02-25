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

class Button : public sdlgame::sprite::Sprite
{
public:
    Surface idle,hover,click;
    bool valid_click = 0;
    function<void()> onClickFunction;
    Button(Surface idle, Surface hover, Surface click)
    {
        this->idle = this->image = idle;
        this->hover = hover;
        this->click = click;
    }

    template <typename... Args>
    void setOnClick(function<void(Args...)> func) {
        onClickFunction = func;
    }

    template <typename... Args>
    void onClick(Args&&... args) {
        if (onClickFunction) {
        onClickFunction(std::forward<Args>(args)...); // Forward arguments
        } else {
            throw std::invalid_argument("onclickfunciton have not set, call setOnclick to set function\n");
        }
    }

    virtual void handle_event(Event &event) = 0;

    virtual void update() = 0;

    virtual void draw() = 0;
};

#endif