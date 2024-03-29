#include "splash_screens.hpp"

StudioSC::StudioSC(Game &game, double time, Animation &anim) : SplashScreen(game,time,anim)
{

}
void StudioSC::handle_event(Event &event)
{  
    SplashScreen::handle_event(event);
}
void StudioSC::update()
{
    SplashScreen::update();
}

SDLSC::SDLSC(Game &game, double time, Animation &anim) : SplashScreen(game,time,anim)
{

}
void SDLSC::handle_event(Event &event)
{  
    SplashScreen::handle_event(event);
}
void SDLSC::update()
{
    SplashScreen::update();
}