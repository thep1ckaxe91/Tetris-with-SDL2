#ifndef SCENE_HPP
#define SCENE_HPP
#include "engine.hpp"
#include "Game.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;
class Game;
class SceneTransition
{
public:
    double time; //time in second, the length of the animation
    Vector2 dir;
    Surface window = sdlgame::display::get_surface();
    void set_dir(Vector2 dir){this->dir = dir;}
    virtual void update() = 0;
    virtual void draw() = 0;
};

class InZoomCircle : public SceneTransition
{
public:
    InZoomCircle(Vector2 pos)
    {
        this->dir=pos;
    }
    void update()
    {

    }
    void draw() 
    {

    }
};
class OutZoomCircle : public SceneTransition
{
    OutZoomCircle(Vector2 pos)
    {
        this->dir = pos;
    }
    void update()
    {

    }
    void draw()
    {

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
/**
 * class contain update and draw fucntion for unload and loadin transition animation
*/
class Scene
{
public:
    Scene(std::shared_ptr<Game> game = nullptr);
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void handle_event(sdlgame::event::Event &event) = 0;
    private:
    std::shared_ptr<Game> game;
    SceneTransition *in;
    SceneTransition *out;
};

#endif