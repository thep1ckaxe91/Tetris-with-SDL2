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
    OutFade *out = new OutFade(1);
    InFade *in = new InFade(1);
    MainMenu *next = new MainMenu(*game);
    this->game->pop_scene(out,next,in);
    cout << "called" << endl;
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
    Animation sdlsc(*game,30);
    sdlsc.load(base_path + "data/animations/splash/sdl/");
    sdlsc.set_default(sdlsc.frames.back());
    sdlsc.play();
    OutFade *out = new OutFade(1);
    InFade *in = new InFade(1);
    SDLSC *next = new SDLSC(*game,sdlsc);
    this->game->pop_scene(out,next,in);
}