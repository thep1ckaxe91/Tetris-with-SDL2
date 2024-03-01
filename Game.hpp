#ifndef GAME_HPP
#define GAME_HPP
#include "Images.hpp"
#include "Scene.hpp"
#include "SceneTransition.hpp"
using namespace std;
class Scene;
class sdlgame::surface::Surface;
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
    sdlgame::surface::Surface window;
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