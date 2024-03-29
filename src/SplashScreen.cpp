#include "SplashScreen.hpp"

SplashScreen::SplashScreen(Game &game, double time, Animation &anim ) : Scene(game)
{
    this->time = time;
    this->splash = anim;
    this->splash.play();
}
SplashScreen::SplashScreen()=default;
void SplashScreen::play()
{
    this->splash.play();
}
void SplashScreen::handle_event(Event &event)
{
    // if(this->time <=1 and event.type == sdlgame::MOUSEBUTTONDOWN)
    // {
    //     this->splash.pause();
    // }
}
void SplashScreen::update()
{
    if(this->splash.playing)
    {
        this->splash.update();
        this->time -= this->game->clock.delta_time();
        if(this->time <= 0){
            this->splash.playing=0;
            this->on_finish();
        }
    }
}
void SplashScreen::draw()
{
    this->game->window.blit(this->splash.image,Vector2());
}
SplashScreen::~SplashScreen() = default;