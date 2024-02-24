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

/**
 * class contain update and draw fucntion for unload and loadin transition animation
*/
class Scene
{
public:
    shared_ptr<sdlgame::time::Clock> clock;
    shared_ptr<Game> game;
    Scene(shared_ptr<Game> game){
        this->clock = make_shared<sdlgame::time::Clock>(&game->clock);
    }
    virtual ~Scene() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void handle_event(sdlgame::event::Event &event) = 0;
private:
    std::shared_ptr<Game> game;
    SceneTransition *in;
    SceneTransition *out;
};

#endif