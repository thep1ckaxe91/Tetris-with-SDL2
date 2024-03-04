#ifndef INSWIPEDOWN_HPP
#define INSWIPEDOWN_HPP
#include "SceneTransition.hpp"

class InSwipeDown : public SceneTransition
{
public:
    double accelerate;
    double vel;
    double cur_height;
    InSwipeDown(double time = 1);
    void update(double delta_time);
    void draw();
};

#endif