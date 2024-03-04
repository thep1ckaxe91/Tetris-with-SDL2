#include "engine/engine.hpp"
#include "OutSwipeDown.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;
OutSwipeDown::OutSwipeDown(double time) : SceneTransition(time)
{
    vel=cur_height=0;
    this->accelerate = (sdlgame::display::get_height()*2/(time*time));
}
void OutSwipeDown::update(double delta_time)
{
    this->vel += this->accelerate * delta_time;
    this->time -= delta_time;
    if(this->time <= 0) isDone = 1;
    // cout << this->vel << " " << this->accelerate << " " << delta_time << endl;
    this->cur_height += this->vel*delta_time;
}
void OutSwipeDown::draw()
{
    sdlgame::draw::rect(sdlgame::display::get_surf(),"black",Rect(0.0,0.0,sdlgame::display::get_width(),cur_height));
}