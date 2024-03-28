#include "SplashScreen.hpp"

SplashScreen::SplashScreen(Game &game, double time=1) : Scene(game)
{
    
}
SplashScreen::SplashScreen()=default;
void SplashScreen::load(Animation &anim)
{

}
void SplashScreen::play(bool loop)
{
    this->splash.loop=loop;
    this->splash.play();
}
void 
void SplashScreen::handle_event(Event &event)
{

}
void SplashScreen::update()
{

}
void SplashScreen::draw()
{
    
}