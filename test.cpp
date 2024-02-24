#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;
//If global declare is bad, i make MY OWN global declare :)
class Game
{
public:
    bool gameactive = true;
    Vector2 desktop_size = sdlgame::display::get_desktop_size();
    string base_path = sdlgame::get_base_path();
    Surface window = sdlgame::display::set_mode(
        desktop_size.x,desktop_size.y,
        sdlgame::RENDERER_ACCELERATED | sdlgame::RESIZABLE | sdlgame::MAXIMIZED
    );
    sdlgame::time::Clock clock;

    Game() = default;

    void draw()
    {
         
    }
    void update()
    {

    }
    void run(){
        while(true)
        {
            auto events = sdlgame::event::get();
            for(auto &event : events)
            {
                if(event.type == sdlgame::QUIT)
                {
                    sdlgame::quit();
                    exit(0);
                }
                else if(event.type == sdlgame::WINDOWENTER){
                    if(event["event"] == sdlgame::WINDOWFOCUSLOST) gameactive = false;
                    else if(event["event"] == sdlgame::WINDOWFOCUSGAINED) gameactive = true;
                }
            }
            if(gameactive)
            {
                update();
                draw();
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
    Game game;
    game.run();
    return 0;
}