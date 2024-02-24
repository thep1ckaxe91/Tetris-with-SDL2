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

    InZoomCircle(Vector2 pos, double time) : SceneTransition(time)
    {
        mask = Surface(window.getWidth(),window.getHeight());
        this->dir=pos;
        this->rad = max({
            (pos-window.getRect().getTopLeft()).magnitude(),
            (pos-window.getRect().getTopRight()).magnitude(),
            (pos-window.getRect().getBottomLeft()).magnitude(),
            (pos-window.getRect().getBottomRight()).magnitude()
        });
        this->speed = this->rad / time;
    }
    void update(double delta_time)
    {
        mask.fill(Color("black"));
        sdlgame::draw::circle(mask,Color(),this->dir.x,this->dir.y,this->rad);
        this->rad -= this->speed;
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
    Surface mask;//mask surface to draw on top of window
    double rad;
    double speed;//pixel per second
    OutZoomCircle(Vector2 pos, double time) : SceneTransition(time)
    {
        mask = Surface(window.getWidth(),window.getHeight());
        this->dir=pos;
        this->rad = 0;
        this->speed = max({
            (pos-window.getRect().getTopLeft()).magnitude(),
            (pos-window.getRect().getTopRight()).magnitude(),
            (pos-window.getRect().getBottomLeft()).magnitude(),
            (pos-window.getRect().getBottomRight()).magnitude()
        }) / time;
    }
    void update(double delta_time)
    {
        mask.fill(Color("black"));
        sdlgame::draw::circle(mask,Color(),this->dir.x,this->dir.y,this->rad);
        this->rad += this->speed;
        this->time -= delta_time;
        if(this->rad >= (window.getRect().getTopLeft() - window.getRect().getBottomRight()).magnitude()) isDone = 1;
    }
    void draw() 
    {
        window.blit(mask,Vector2(0,0));
    }
};
class SwipeUp : public SceneTransition
{
public:
    double start_accelerate;
    double end_decelerate;
    double pull_vel = 0;
    SwipeUp(double second = 1, double accelerate = 1, double decelerate = 1)
    {
        start_accelerate = accelerate;
        end_decelerate = decelerate;

    }
    void update()
    {
        
    }
    void draw()
    {

    }
};
class SwipeDown : public SceneTransition
{
public:
    double y_pos=0;
    SwipeDown()
    {
    }
    void update()
    {

    }
    void draw()
    {

    }
};
#endif