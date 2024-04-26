#ifndef PAUSE_HPP
#define PAUSE_HPP

#include "Scene.hpp"

class Pause : public Scene 
{
public:
    Pause(Game &game);
    Pause();
    void update();
    void handle_event(Event &event);
    void draw();
};

#endif