#ifndef SCENES_HPP
#define SCENES_HPP
/**
 * 2 test scene is for test scene transition and some this and that function
 * 
 * all scene this game need is MainMenu, Credit, GamePlay, GameOver
*/
#include "Scene.hpp"
#include "engine.hpp"
#include "Game.hpp"
#include "constant.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;


class Test : public Scene
{
public:
    Surface mask;
    Test(Game &game) : Scene(game){
        printf("got here\n%p\n",this->game->window.texture);
    }
    void handle_event(Event &event)
    {

    }
    void update()
    {
        
    }
    void draw()
    {
        this->game->window.fill(Color("white"));
        sdlgame::draw::circle(this->game->window,Color("magenta"),
            RESOLUTION_WIDTH/2, RESOLUTION_HEIGHT/2, 4
        );
    }
    ~Test(){}
};
class Test2 : public Scene
{
public:
    Surface font_surf;
    Rect font_rect;
    Font test_font = Font(base_path + "data/fonts/arial.ttf");
    Test2(Game &game) : Scene(game)
    {}
    void handle_event(Event &event)
    {

    }
    void update()
    {
        string test_text = "";
        int cnt = sdlgame::random::randint(0,25);
        for(int i=0;i<cnt;i++) test_text+=char(sdlgame::random::randint('a','z'));
        font_surf = test_font.render(test_text,0,Color("black"));
    }
    void draw()
    {

    }
};



class MainMenu : public Scene
{

    MainMenu(Game &game) : Scene(game)
    {

    }
    ~MainMenu(){}
};

#endif