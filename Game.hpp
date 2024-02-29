#ifndef GAME_HPP
#define GAME_HPP
#include "Scene.hpp"
#include "engine.hpp"
#include "SceneTransition.hpp"
#include "Images.hpp"
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

 * in and out transition memory management is your responsibility
*/
class Game
{
protected:
    bool gameactive=0;
    std::vector<Scene *> scene_list;
    SceneTransition *in = nullptr;
    SceneTransition *out = nullptr;
    Scene *next = nullptr;
public:
    Images images;
    Surface window;
    sdlgame::time::Clock clock;
    Game() = default;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void run() = 0;
    template <class T1, class T2, class T3>
    void add_scene(T3 *out, T1 *scene, T2 *in);
    // completely goback
    void remove_scene();
    // remove a scene and add another
    template <class T1, class T2, class T3>
    void pop_scene(T1* out, T2* next, T3* in);
};
#endif