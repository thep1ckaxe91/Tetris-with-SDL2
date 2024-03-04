#include "InSwipeDown.hpp"
#include "engine/engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;
InSwipeDown::InSwipeDown(double time) : SceneTransition(time)
{
    this->accelerate = (sdlgame::display::get_height()*2)/time/time;
}
void InSwipeDown::update(double delta_time)
{
    this->vel += this->accelerate * delta_time;
    this->time -= delta_time;
    if(this->time <= 0) isDone = 1;

    this->cur_height += this->vel*delta_time;
}
void InSwipeDown::draw()
{
    sdlgame::draw::rect(sdlgame::display::get_surf(),"black",Rect(0.0,cur_height,sdlgame::display::get_width(),sdlgame::display::get_height()));
}