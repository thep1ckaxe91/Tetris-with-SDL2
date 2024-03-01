#include "MainMenu.hpp"
#include "constant.hpp"
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
//If global declare is bad, i make MY OWN global declare >:)

class Sandtris : public Game
{
public:
    bool gameactive = 1;
    int buffer_lost = 0;
    Sandtris() : Game(){
        this->window = sdlgame::display::set_mode(RESOLUTION_WIDTH, RESOLUTION_HEIGHT,
            sdlgame::RESIZABLE
        );
    }
    void update()
    {
        if(!scene_list.empty()) if(scene_list.back()){
            scene_list.back()->update();
        }
        if(this->out){
            out->update(clock.delta_time());
            if(out->isDone){
                delete out;
                out = nullptr;
            }
        }
        else if(this->in){
            if(this->next){
                delete scene_list.back();
                scene_list.pop_back();
                scene_list.push_back(this->next);
                this->next = nullptr;
            }
            in->update(clock.delta_time());
            if(in->isDone){
                delete in;
                in = nullptr;
            }
        }
    }
    void draw()
    {
        if(!scene_list.empty()) if(scene_list.back()){
            scene_list.back()->draw();
        }
        if(this->out){out->draw();}
        else if(this->in){in->draw();}
    }
    void run()
    {
        MainMenu *mainmenu = new MainMenu(*this);
        this->scene_list.push_back(mainmenu);
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
                }
                scene_list[scene_list.size()-1]->handle_event(event);
            }
            if(gameactive)
            {
                update();
                draw();
                sdlgame::display::flip();
                sdlgame::display::set_caption((to_string(clock.get_fps())).c_str());
            }
            clock.tick(MAXFPS);
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
 * TODO: Discover of memory leak with scene_transition, solve it (unresolved)
 * TODO: Make all file seperated declaration and definition
*/