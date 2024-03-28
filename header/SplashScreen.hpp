#ifndef SPLASH_SCREEN_HPP
#define SPLASH_SCREEN_HPP
#include "Animation.hpp"
#include "Scene.hpp"
#include "scene_transitions.hpp"
class SplashScreen : public Scene
{
private:
public:
    Animation splash;
    double time;
    /**
     * @brief Construct a new Splash Screen object
     * 
     * @param game 
     * @param time total time for splash screen from in transition start and out transition end;
     */
    SplashScreen(Game &game, double time=2);
    SplashScreen();
    void load(Animation &anim);
    void play(bool loop=0);
    void handle_event(Event &event);
    void update();
    void draw();
};

#endif