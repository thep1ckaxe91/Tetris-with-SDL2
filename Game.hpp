#ifndef GAME_HPP
#define GAME_HPP
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
/**
 * This class have to be inherit and override 

 * This class represent the entire game itself
*/
class Game
{
public:
    bool gameactive;
    Surface window;
    sdlgame::time::Clock clock;
    std::vector<Scene *> scene_list;
    
    Game() = default;
    virtual void draw() const  =0;
    virtual void update() =0;
    virtual void run()    =0;
    void add_scene(Scene *scene){
        this->scene_list.push_back(scene);
    }
    void pop_scene()
    {
        delete this->get_current_scene();
        scene_list.pop_back();
    }
    Scene *get_current_scene() const{
        return scene_list.back();
    }
};
#endif