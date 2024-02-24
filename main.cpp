#include "engine.hpp"
#include "Game.hpp"
#include "Scene.hpp"
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

//If global declare is bad, i make MY OWN global declare >:)
class Tetris : public Game
{  
public:
    bool gameactive = 1;
    Surface window = sdlgame::display::set_mode(desktop_size.x,desktop_size.y,
        sdlgame::RENDERER_ACCELERATED | sdlgame::MAXIMIZED
    );
    sdlgame::time::Clock clock;
    std::vector<std::shared_ptr<Scene>> scene_list;
    double refresh_cooldown = 1/refresh_rate;
    Tetris(){

    }
    void update()
    {

        this->refresh_cooldown += this->clock.delta_time();
    }
    void draw()
    {

    }
    void run()
    {
        while(true)
        {
            auto events = sdlgame::event::get();
            for(auto& event : events)
            {
                if(event.type == sdlgame::QUIT)
                {
                    sdlgame::quit();
                    exit(0);
                }
                else if(event.type == sdlgame::WINDOWEVENT)
                {
                    if(event["event"]==sdlgame::WINDOWFOCUSGAINED) gameactive = 1;
                    else if(event["event"]==sdlgame::WINDOWFOCUSLOST) gameactive = 0;
                }
            }
            if(gameactive)
            {
                update();
                if(this->refresh_cooldown >= 1/refresh_rate){
                    this->refresh_cooldown -= 1/refresh_rate;
                    draw();
                }
                sdlgame::display::flip();
            }
            clock.tick();
        }
    }
};

int main(int argc, char** argv)
{
    sdlgame::init();
    sdlgame::font::init();
    sdlgame::image::init();
    sdlgame::mixer::init();
    Tetris game;
    game.run();
    return 0;
}