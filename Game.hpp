#ifndef GAME_HPP
#define GAME_HPP
#include "engine/engine.hpp"
#include "Images.hpp"
#include "Scene.hpp"
#include "SceneTransition.hpp"
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
    SceneTransition *in;
    SceneTransition *out;
    Scene *next;
public:
    Images images;
    sdlgame::surface::Surface window;
    sdlgame::time::Clock clock;
    Game();
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void run() = 0;
    // template <class T1, class T2, class T3>
    void add_scene(SceneTransition *out, Scene *scene, SceneTransition *in);
    // completely goback
    void remove_scene();
    // remove a scene and add another
    // template <class T1, class T2, class T3>
    void pop_scene(SceneTransition* out, Scene* next, SceneTransition* in);
};
#endif