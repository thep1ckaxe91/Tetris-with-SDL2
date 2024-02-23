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
class TransitionEvent
{
public:
    int type;
    double time; //time in second, the length of the animation
    bool in;
    Vector2 dir;
    Surface window = sdlgame::display::get_surface();
    void set_dir(Vector2 dir){this->dir = dir;}
    virtual void update() = 0;
    virtual void draw() = 0;
};
class InZoomCircle : public TransitionEvent
{
public:
    InZoomCircle(Vector2 dir)
    {
        this->dir = dir;
    }
    void update()
    {

    }
    void draw() 
    {

    }
};
class OutZoomCircle : public TransitionEvent
{
    const int type = 2;
    void update()
    {

    }
    void draw()
    {

    }
};
class InSwipeUp : public TransitionEvent
{
    const int type = 3;
    void update()
    {

    }
    void draw()
    {

    }
};
class OutSwipeUp : public TransitionEvent
{
    const int type = 4;
    void update()
    {

    }
    void draw()
    {

    }
};
class InSwipeDown : public TransitionEvent
{
    const int type = 5;
    void update()
    {

    }
    void draw()
    {

    }
};
class OutSwipeDown : public TransitionEvent
{
    const int type = 6;
    void update()
    {

    }
    void draw()
    {

    }
};
SDL_Event e;
/**
 * class contain update and draw fucntion for unload and loadin transition animation
*/
class SceneTransition
{
public:
    int type;
    SceneTransition(TransitionEvent args)
    {
        this->type = type;
    }
};

class Scene
{
    public:
    Scene() = default;
    Scene(std::shared_ptr<Game> game);
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void handle_event(sdlgame::event::Event &event) = 0;
    private:
    std::shared_ptr<Game> game;
    SceneTransition in;
    SceneTransition out;
};

#endif