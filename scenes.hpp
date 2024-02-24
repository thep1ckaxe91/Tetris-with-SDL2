#ifndef SCENES_HPP
#define SCENES_HPP

#include "Scene.hpp"
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


class Test : public Scene
{
    Test(shared_ptr<Game> game) : Scene(game){
        
    }
};

class MainMenu : public Scene
{

};

#endif