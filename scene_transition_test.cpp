#include "engine.hpp"
#include "scene_transitions.hpp"
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
        800,600,
        sdlgame::RESIZABLE
    );
    sdlgame::time::Clock clock;
    SceneTransition *test=NULL;
    Game() = default;

    void draw()
    {
    }
    void update()
    {
        
        // cout << clock.delta_time() << endl;
    }
    void run(){
        test = new OutSwipeDown(1);
        clock.set_bullettime_multiplier(10);
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
                else if(event.type == sdlgame::KEYDOWN and event["key"] == sdlgame::K_DOWN){
                    if(test){
                        test->update(clock.delta_time());
                        if(test->isDone){
                            delete test;
                            test = new InZoomCircle(1,Vector2(400,300)); 
                        }
                    }
                    window.fill("white");
                    if(test) test->draw();
                }
            }
            if(gameactive)
            {
                update();
                draw();
                sdlgame::display::flip();
            }
            clock.tick(60);
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