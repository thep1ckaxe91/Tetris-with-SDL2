#ifndef SCENE_HPP
#define SCENE_HPP
#include "Game.hpp"
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
    void handle_event(std::any &event);
};
#endif