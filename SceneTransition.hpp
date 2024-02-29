#ifndef SCENE_TRANSITION_HPP
#define SCENE_TRANSITION_HPP

using namespace std;
/**
 * the window surface is just a represent, not actually is the window
 * use carefully
*/
class SceneTransition
{
public:
    double time; //time in second, the length of the animation
    bool isDone = 1;
    SceneTransition(double time=1){this->time = time; this->isDone = 0;}
    void play(){this->isDone = 0;}
    virtual void update(double delta_time) = 0;
    virtual void draw() = 0;
};

#endif