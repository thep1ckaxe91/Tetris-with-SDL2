#ifndef SCENE_TRANSITIONS_HPP
#define SCENE_TRANSITIONS_HPP
#include "engine.hpp"
#include "SceneTransition.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;

class InZoomCircle : public SceneTransition
{
public:
    Surface mask;//mask surface to draw on top of window
    double rad;
    double speed;//pixel per second

    InZoomCircle(double time, Vector2 pos) : SceneTransition(time)
    {
        mask = Surface(sdlgame::display::get_width(),sdlgame::display::get_height());
        this->dir=pos;
        double win_w = sdlgame::display::get_width();
        double win_h = sdlgame::display::get_height();
        this->rad = max({
            (pos-Vector2(0,0)).magnitude(),
            (pos-Vector2(win_w,0.0)).magnitude(),
            (pos-Vector2(0.0,win_h)).magnitude(),
            (pos-Vector2(win_w,win_h)).magnitude()
        });
        this->speed = this->rad / time;
    }
    void update(double delta_time)
    {
        mask.fill(Color("black"));
        sdlgame::draw::circle(mask,Color(),this->dir.x,this->dir.y,this->rad);
        this->rad += this->speed * delta_time;
        this->time -= delta_time;
        if(this->time <= 0) this->isDone = 1;
    }
    void draw() 
    {
        window.blit(mask,Vector2(0,0));
    }
};

class OutZoomCircle : public SceneTransition
{
public:
    Surface mask;//mask surface to draw on top of window
    double rad;
    double speed;//pixel per second
    OutZoomCircle(double time, Vector2 pos) : SceneTransition(time)
    {
        mask = Surface(sdlgame::display::get_width(),sdlgame::display::get_height());
        this->dir=pos;
        this->rad = 0;
        double win_w = sdlgame::display::get_width();
        double win_h = sdlgame::display::get_height();
        this->speed = max({
            (pos-Vector2(0,0)).magnitude(),
            (pos-Vector2(win_w,0.0)).magnitude(),
            (pos-Vector2(0.0,win_h)).magnitude(),
            (pos-Vector2(win_w,win_h)).magnitude()
        }) / time;
        
    }
    void update(double delta_time)
    {
        mask.fill(Color("black"));
        sdlgame::draw::circle(mask,Color(),this->dir.x,this->dir.y,this->rad);
        this->rad -= this->speed * delta_time;
        this->time -= delta_time;
        if(this->time <= 0) isDone = 1;
    }
    void draw() 
    {
        window.blit(mask,Vector2(0,0));
    }
};

class InSwipeDown : public SceneTransition
{
public:
    double accelerate;
    double vel = 0;
    double cur_height = 0;
    Surface mask;
    InSwipeDown(double time = 1) : SceneTransition(time)
    {
        this->accelerate = (sdlgame::display::get_height()*2)/time/time;
        mask = Surface(sdlgame::display::get_width(),sdlgame::display::get_height());
        mask.fill("black");
    }
    void update(double delta_time)
    {
        this->vel += this->accelerate * delta_time;
        this->time -= delta_time;
        if(this->time <= 0) isDone = 1;

        this->cur_height += this->vel*delta_time;
    }
    void draw()
    {
        window.blit(this->mask,Vector2(0.0,cur_height));
    }
};

class OutSwipeDown : public SceneTransition
{
public:
    double accelerate;
    double vel = 0;
    double cur_height = 0;
    Surface mask;
    OutSwipeDown(double time = 1) : SceneTransition(time)
    {
        this->accelerate = (sdlgame::display::get_height()*2/(time*time));
        mask = Surface(sdlgame::display::get_width(),sdlgame::display::get_height());
        mask.fill("black");
    }
    void update(double delta_time)
    {
        this->vel += this->accelerate * delta_time;
        this->time -= delta_time;
        if(this->time <= 0) isDone = 1;
        // cout << this->vel << " " << this->accelerate << " " << delta_time << endl;
        this->cur_height += this->vel*delta_time;
    }
    void draw()
    {
        window.blit(this->mask,Vector2(0.0,cur_height-sdlgame::display::get_height()));
    }
};


#endif