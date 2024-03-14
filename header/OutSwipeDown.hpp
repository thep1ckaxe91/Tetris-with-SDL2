#ifndef OUTSWIPEDOWN_HPP
#define OUTSWIPEDOWN_HPP
#include "SceneTransition.hpp"
class OutSwipeDown : public SceneTransition
{
public:
    double accelerate;
    double vel;
    double cur_height;
    OutSwipeDown(double time = 2);
    void update(double delta_time);
    void draw();
};

#endif