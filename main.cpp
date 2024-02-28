#include "engine.hpp"
#include "Game.hpp"
#include "Scene.hpp"
#include "constant.hpp"
#include "scenes.hpp"
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

class Sandtris : public Game
{
public:
    bool gameactive = 1;
    int buffer_lost = 0;
    Sandtris() : Game(){
        this->window = sdlgame::display::set_mode(RESOLUTION_WIDTH, RESOLUTION_HEIGHT,
            sdlgame::RESIZABLE | sdlgame::MAXIMIZED
        );
    }
    void update()
    {
        mtx.lock();
        if(!scene_list.empty()) if(scene_list.back()){
            scene_list.back()->update();
        }
        if(this->in){
            in->update(clock.delta_time());
            if(in->isDone){
                delete in;
                in = nullptr;
            }
        }
        if(this->out){
            out->update(clock.delta_time());
            if(out->isDone){
                delete out;
                out = nullptr;
                window.fill("black");
                sdlgame::display::flip();
            }
        }
        mtx.unlock();
    }
    void draw()
    {
        mtx.lock();
        if(!scene_list.empty()) if(scene_list.back()){
            scene_list.back()->draw();
        }
        if(this->in){in->draw();}
        if(this->out){out->draw();}
        mtx.unlock();
    }
    void run()
    {
        Test2 *test_scene = new Test2(*this);
        scene_list.push_back((Scene*)test_scene);
        in = new InSwipeDown();
        while(true){
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
                    else if(event["event"]==sdlgame::WINDOWRESIZED){
                        printf("resized\n");
                        gameactive = 0;
                    }
                    else gameactive = 1;
                }
                scene_list[scene_list.size()-1]->handle_event(event);
            }
            if(gameactive)
            {
                update();
                draw();
                sdlgame::display::flip();
            }
            clock.tick(refresh_rate);
        }
    }
};

int main(int argc, char** argv)
{
    sdlgame::init();
    sdlgame::font::init();
    sdlgame::image::init();
    sdlgame::mixer::init();
    Sandtris game;
    game.run();
    return 0;
}
/**
 * TODO: Discover of memory leak with scene_transition, solve it
 * Solve the problem where when resize the window, it appear nothing until it reload
 * APPROACH: check the resize window event and set gameactive as it do
*/