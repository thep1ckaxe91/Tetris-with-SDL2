#include "Game.hpp"
#include "engine/engine.hpp"
Game::Game()
{
    gameactive = 1;
    in = out = nullptr;
    next = nullptr;
}
void Game::add_scene(SceneTransition *out, Scene *scene, SceneTransition *in)
{
    this->out = out;
    this->next = scene;
    this->in = in;
}
// completely goback
void Game::remove_scene()
{
    if (this->scene_list.size() > 0)
    {
        delete scene_list[scene_list.size()-1];
        scene_list.pop_back();
    }
}
// remove a scene and add another
void Game::pop_scene(SceneTransition* out, Scene* next, SceneTransition* in)
{
    if (scene_list.size() > 0) {
        this->out = out;
        this->in = in;
        this->next = next;
    }
}