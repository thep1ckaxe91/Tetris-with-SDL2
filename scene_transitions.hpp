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
        if(this->time <= 0) isDone = 1;
    }
    void draw() 
    {
        window.blit(mask,Vector2(0,0));
    }
};

class OutSwipeUp : public SceneTransition
{
public:
    double start_acceleration;
    double end_deceleration;
    double vel = 0, t1 = 0;
    double vel_at_t2;
    double length,v_max;
    double cur_height = window.getHeight();
    OutSwipeUp(double time = 1, double accelerate = 10, double decelerate = 10) : SceneTransition(time)
    {
        this->start_acceleration = accelerate;
        this->end_deceleration = decelerate;
        this->length = window.getHeight();
        this->v_max = sqrt(2 * this->length / this->start_acceleration);
    }
    void update(double delta_time)
    {
        if(this->v_max/this->start_acceleration < this->t1){
            this->vel += this->start_acceleration * delta_time;
        }
        else{
            this->vel -= this->end_deceleration*delta_time;
        }
        this->time -= delta_time;
        this->t1 += delta_time;
        if(this->time <= 0) isDone = 1;
        this->cur_height -= this->vel;
    }
    void draw()
    {
        sdlgame::draw::rect(window,Color("black"),Rect(0.0,this->cur_height,window.getWidth(),window.getHeight()-this->cur_height));
    }
};

class InSwipeUp : public SceneTransition
{
public:
    double start_acceleration;
    double end_deceleration;
    double vel = 0, t1 = 0;
    double vel_at_t2;
    double length,v_max;
    double cur_height = window.getHeight();
    InSwipeUp(double time = 1, double accelerate = 10, double decelerate = 10) : SceneTransition(time)
    {
        this->start_acceleration = accelerate;
        this->end_deceleration = decelerate;
        this->length = window.getHeight();
        this->v_max = sqrt(2 * this->length / this->start_acceleration);
    }
    void update(double delta_time)
    {
        if(this->v_max/this->start_acceleration < this->t1){
            this->vel += this->start_acceleration*delta_time;
        }
        else{
            this->vel -= this->end_deceleration*delta_time;
        }
        this->time -= delta_time;
        this->t1 += delta_time;
        if(this->time <= 0) isDone = 1;

        this->cur_height -= this->vel;
    }
    void draw()
    {
        sdlgame::draw::rect(window,Color("black"),Rect(0.0,0.0,window.getWidth(),this->cur_height));
    }
};

class InSwipeDown : public SceneTransition
{
public:
    double start_acceleration;
    double end_deceleration;
    double vel = 0, t1 = 0;
    double vel_at_t2;
    double length,v_max;
    double cur_height = 0;
    InSwipeDown(double time = 1, double accelerate = 10, double decelerate = 50) : SceneTransition(time)
    {
        this->start_acceleration = accelerate;
        this->end_deceleration = decelerate;
        this->length = window.getHeight();
        this->v_max = sqrt(2 * this->length / this->start_acceleration);
    }
    void update(double delta_time)
    {
        if(this->v_max/this->start_acceleration < this->t1){
            this->vel += start_acceleration * delta_time;
        }
        else{
            this->vel -= this->end_deceleration*delta_time;
        }
        this->time -= delta_time;
        this->t1 += delta_time;
        if(this->time <= 0) isDone = 1;

        this->cur_height += this->vel;
    }
    void draw()
    {
        sdlgame::draw::rect(window,Color("black"),Rect(0.0,this->cur_height,window.getWidth(),window.getHeight()-this->cur_height));
    }
};

class OutSwipeDown : public SceneTransition
{
public:
    double start_acceleration;
    double end_deceleration;
    double vel = 0, t1 = 0;
    double vel_at_t2;
    double length,v_max;
    double cur_height = 0;
    OutSwipeDown(double time = 1, double accelerate = 10, double decelerate = 50) : SceneTransition(time)
    {
        this->start_acceleration = accelerate;
        this->end_deceleration = decelerate;
        this->length = window.getHeight();
        this->v_max = sqrt(2 * this->length / this->start_acceleration);
    }
    void update(double delta_time)
    {
        if(this->v_max/this->start_acceleration < this->t1){
            this->vel += start_acceleration * delta_time;
        }
        else{
            this->vel -= this->end_deceleration*delta_time;
        }
        this->time -= delta_time;
        this->t1 += delta_time;
        if(this->time <= 0) isDone = 1;

        this->cur_height += this->vel;
    }
    void draw()
    {
        sdlgame::draw::rect(window,Color("black"),Rect(0.0,0.0,window.getWidth(),this->cur_height));
    }

};

#endif