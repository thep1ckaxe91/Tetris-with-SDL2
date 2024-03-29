#include "splash_screens.hpp"
#include "scene_transitions.hpp"
#include "MainMenu.hpp"

SDLSC::SDLSC(Game &game,  Animation anim,double time) : SplashScreen(game,time,anim)
{
    this->game=&game;
}
void SDLSC::handle_event(Event &event)
{  
    SplashScreen::handle_event(event);
}
void SDLSC::update()
{
    SplashScreen::update();
}
void SDLSC::on_finish()
{
    OutFade *out = new OutFade();
    InFade *in = new InFade();
    MainMenu *next = new MainMenu(*game);
    this->game->pop_scene(out,next,in);
}

StudioSC::StudioSC(Game &game,  Animation anim,double time) : SplashScreen(game,time,anim)
{
    this->game = &game;
}
void StudioSC::handle_event(Event &event)
{  
    SplashScreen::handle_event(event);
}
void StudioSC::update()
{
    SplashScreen::update();
}
void StudioSC::on_finish()
{
    Animation sdlsc = Animation(*game,30);
    sdlsc.load(base_path + "data/animations/splash/sdl/");
    OutFade *out = new OutFade();
    InFade *in = new InFade();
    SDLSC *next = new SDLSC(*game,sdlsc);
    this->game->pop_scene(out,next,in);
}