#ifndef OUTSWIPEDOWN_HPP
#define OUTSWIPEDOWN_HPP
#include "SceneTransition.hpp"
class OutSwipeDown : public SceneTransition
{
public:
    double accelerate;
    double vel = 0;
    double cur_height = 0;
    OutSwipeDown(double time = 1);
    void update(double delta_time);
    void draw();
};

#endif