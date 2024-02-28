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
    Surface game_frame;
    Test2(Game &game) : Scene(game){
        game_frame = sdlgame::image::load(base_path + "data/image/background/game_frame.png");
    }
    void handle_event(Event &event);
    void update()
    {
        cout << "bruh" << endl;
    }
    void draw()
    {
        this->game->window.fill("black");
        this->game->window.blit(this->game_frame,Vector2());
    }
};
class Test : public Scene
{
public:
    Surface game_frame;
    Surface mask;
    double deg=0;
    Test(Game &game) : Scene(game){
        game_frame = sdlgame::image::load(base_path + "data/image/background/game_frame.png");
    }
    void handle_event(Event &event)
    {
        if(event.type == sdlgame::KEYDOWN)
        {
            if(event["key"] == sdlgame::K_p)
            {
                OutSwipeDown *out = new OutSwipeDown();
                Test2 *next = new Test2(*this->game);
                InSwipeDown *in = new InSwipeDown();
                this->game->pop_scene(out,next,in);
            }
        }
    }
    void update()
    {
        deg+=1;
    }
    void draw()
    {
        this->game->window.fill("black");
        this->game->window.blit(sdlgame::transform::rotate(this->game_frame,deg,game_frame.getRect().getCenter()),Vector2(0,0));
    }
};

void Test2::handle_event(Event &event)
{
    if(event.type == sdlgame::KEYDOWN)
    {
        if(event["key"] == sdlgame::K_p)
        {
            OutSwipeDown *out = new OutSwipeDown();
            Test *next = new Test(*this->game);
            InSwipeDown *in = new InSwipeDown();
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