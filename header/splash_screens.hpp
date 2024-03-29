#ifndef SPLASH_SCREENS_HPP
#define SPLASH_SCREENS_HPP

#include "SplashScreen.hpp"

class StudioSC : public SplashScreen
{
public:
    StudioSC(Game &game, double time=3, Animation &anim);
    void handle_event(Event &event);
    void update();
};

class SDLSC : public SplashScreen
{
public:
    SDLSC(Game &game, double time=2, Animation &anim);
    void handle_event(Event &event);
    void update();
};

#endif