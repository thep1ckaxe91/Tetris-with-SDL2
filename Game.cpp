#include "Game.hpp"

template <class T1, class T2, class T3>
void Game::add_scene(T3 *out, T1 *scene, T2 *in)
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
template <class T1, class T2, class T3>
void Game::pop_scene(T1* out, T2* next, T3* in) {
    if (scene_list.size() > 0) {
        this->out = out;
        this->in = in;
        this->next = next;
    }
}