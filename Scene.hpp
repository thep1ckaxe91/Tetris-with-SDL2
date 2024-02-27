#ifndef SCENE_HPP
#define SCENE_HPP
#include "engine.hpp"
#include "Game.hpp"
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
class Game;
/**
 * class manage a scene, all update, draw, handle_event should be override
*/

class Scene
{
public:
    Game *game;
    Scene(Game &game){this->game=&game;}
    virtual void update()=0;
    virtual void draw()=0;
    virtual void handle_event(sdlgame::event::Event &event) = 0;
};
#endif