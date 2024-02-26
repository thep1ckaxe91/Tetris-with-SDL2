#ifndef SCENE_TRANSITION_HPP
#define SCENE_TRANSITION_HPP
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
class SceneTransition
{
public:
    double time; //time in second, the length of the animation
    Vector2 dir;
    Surface window = sdlgame::display::get_surface();
    bool isDone = 1;
    SceneTransition(double time=1){this->time = time; this->isDone = 0;}
    void play(){this->isDone = 0;}
    void set_dir(Vector2 dir){this->dir = dir;}
    virtual void update(double delta_time) = 0;
    virtual void draw() = 0;
    virtual void reset() = 0;
};

#endif