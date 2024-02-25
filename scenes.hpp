#ifndef SCENES_HPP
#define SCENES_HPP

#include "Scene.hpp"
#include "engine.hpp"
#include "Game.hpp"
#include "constant.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;


class Test : public Scene
{
public:

    Test(Game &game) : Scene(game){
        printf("%p\n",this->game);
    }
    void handle_event(Event &event)
    {

    }
    void update()
    {

    }
    void draw()
    {
        this->game->window.fill(Color("white"));
        sdlgame::draw::circle(this->game->window,Color("magenta"),desktop_size.x/2 * sin(sdlgame::time::get_ticks()/50),desktop_size.y/2,200);
    }
    ~Test(){}
};

class MainMenu : public Scene
{

};

#endif