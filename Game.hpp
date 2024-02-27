#ifndef GAME_HPP
#define GAME_HPP
#include "Scene.hpp"
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
class Scene;
/**
 * This class have to be inherit and override

 * This class represent the entire game itself

 * in and out transition memory management is your responsibility
*/
class Game
{
protected:
    bool gameactive;
    std::vector<Scene *> scene_list;
    SceneTransition *in = nullptr;
    SceneTransition *out = nullptr;

public:
    Surface window;
    sdlgame::time::Clock clock;

    Game() = default;
    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual void run() = 0;
    template <class T1, class T2>
    void add_scene(T1 *scene, T2 *in)
    {
        T1 *next = new T1(*this);
        this->scene_list.push_back(scene);
        this->in = in;
    }
    // completely goback
    void remove_scene()
    {
        if (scene_list.size() > 0)
        {
            delete scene_list[scene_list.size()-1];
            scene_list.pop_back();
        }
    }
    // remove a scene and add another
    template <class T1, class T2, class T3>
    void pop_scene(T1 *out, T2 *next, T3 *in)
    {
        if (scene_list.size() > 0)
        {
            delete scene_list[scene_list.size() - 1];
            scene_list.pop_back();
            this->out = out;
            this->add_scene(next, in);
        }
    }
};
#endif