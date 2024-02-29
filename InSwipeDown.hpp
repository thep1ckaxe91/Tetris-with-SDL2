#ifndef INSWIPEDOWN_HPP
#define INSWIPEDOWN_HPP
#include "SceneTransition.hpp"

class InSwipeDown : public SceneTransition
{
public:
    double accelerate;
    double vel = 0;
    double cur_height = 0;
    InSwipeDown(double time = 1);
    void update(double delta_time);
    void draw();
};

#endif