#ifndef GAME_HPP
#define GAME_HPP
#include "Scene.hpp"
#include "engine.hpp"
#include "SceneTransition.hpp"
#include <thread>
#include <future>
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
    std::atomic_int_fast8_t gameactive=0;
    std::vector<Scene *> scene_list;
    SceneTransition *in = nullptr;
    SceneTransition *out = nullptr;
    std::mutex mtx;
public:
    Surface window;
    sdlgame::time::Clock clock;

    Game() = default;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void run() = 0;
    template <class T1, class T2>
    void add_scene(T1 *scene, T2 *in)
    {
        T1 *next = new T1(*this);
        this->scene_list.push_back(scene);
        this->in = in;
    }
    // template <class T1,class T2>
    // void wait_for_scenetransition(double second,T1 *next, T2 *in){
    //     std::this_thread::sleep_for(chrono::milliseconds(int(second*1000+200)));
    //     delete scene_list[scene_list.size() - 1];
    //     scene_list.pop_back();
    //     this->add_scene(next, in);
    // }
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
    void pop_scene(T1* out, T2* next, T3* in) {
        if (scene_list.size() > 0) {
            this->out = out;
            std::thread([this, next, in, out]() {
                std::this_thread::sleep_for(chrono::milliseconds(int(out->time * 1000)));
                this->gameactive = false;
                mtx.lock();
                Scene *tmp = this->scene_list.back();
                scene_list[scene_list.size()-1] = nullptr;
                delete tmp; 
                scene_list.pop_back();
                mtx.unlock();
                this->add_scene(next, in);
                this->gameactive = true;
            }).detach();
        }
    }

};
#endif