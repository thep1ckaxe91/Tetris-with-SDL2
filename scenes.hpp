#ifndef SCENES_HPP
#define SCENES_HPP
/**
 * 2 test scene is for test scene transition and some this and that function
 * 
 * all scene this game need is MainMenu, Credit, GamePlay, GameOver
*/
#include "engine.hpp"
#include "Scene.hpp"
#include "Game.hpp"
#include "constant.hpp"
#include "scene_transitions.hpp"
#include "SceneTransition.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;

/**
 * TODO: now the new scene is present play out transition and move to the next scene;
 * SOLUTION: just define class, declare method and later define what need 
*/ 
class Test2 : public Scene {
public:
    Surface font_surf;
    Rect font_rect;
    Font test_font = Font(base_path + "data/fonts/arial.ttf");
    Test2(Game &game) : Scene(game){}
    void handle_event(Event &event);
    void update()
    {
        string test_text = "";
        int cnt = sdlgame::random::randint(20,25);
        for(int i=0;i<cnt;i++) test_text+=char(sdlgame::random::randint('a','z'));

        font_surf = test_font.render(test_text,0,Color("black"));
    }
    void draw()
    {
        this->game->window.fill(Color("white"));
        this->game->window.blit(font_surf,Vector2(RESOLUTION_WIDTH/2,RESOLUTION_HEIGHT/2)-font_surf.get_size()*0.5);
    }
};
class Test : public Scene
{
public:
    Surface mask;
    Test(Game &game) : Scene(game){
    }
    void handle_event(Event &event)
    {
        if(event.type == sdlgame::KEYDOWN)
        {
            if(event["key"] == sdlgame::K_p)
            {
                OutZoomCircle *out = new OutZoomCircle(1,this->game->window.getRect().getCenter());
                Test2 *next = new Test2(*this->game);
                InZoomCircle *in = new InZoomCircle(1,this->game->window.getRect().getCenter());
                this->game->pop_scene(out,next,in);
            }
        }
    }
    void update()
    {
    }
    void draw()
    {
        this->game->window.fill(Color("white"));
        sdlgame::draw::circle(this->game->window,Color("magenta"),
            RESOLUTION_WIDTH/2 + sin(sdlgame::time::get_ticks()/500.0)*7, RESOLUTION_HEIGHT/2, 4
        );
    }
};

void Test2::handle_event(Event &event)
{
    if(event.type == sdlgame::KEYDOWN)
    {
        if(event["key"] == sdlgame::K_p)
        {
            OutZoomCircle *out = new OutZoomCircle(1,this->game->window.getRect().getCenter());
            Test *next = new Test(*this->game);
            InZoomCircle *in = new InZoomCircle(1,this->game->window.getRect().getCenter());
            this->game->pop_scene(out,next,in);
        }
    }
}

class MainMenu : public Scene
{

    MainMenu(Game &game) : Scene(game)
    {

    }
    ~MainMenu(){}
};

#endif