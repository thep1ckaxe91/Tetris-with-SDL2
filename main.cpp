#include "engine.hpp"
#include "Scene.hpp"
#include "Game.hpp"
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
private:
    double refresh_cooldown = 1/refresh_rate;
    std::vector<Scene *> scene_list;
public:
    bool gameactive = 1;
    Surface window = sdlgame::display::set_mode(RESOLUTION_WIDTH, RESOLUTION_HEIGHT,
        sdlgame::RESIZABLE | sdlgame::MAXIMIZED 
    );
    sdlgame::time::Clock clock;
    int buffer_lost = 0;
    Sandtris() : Game(){}
    void update()
    {
        scene_list[scene_list.size()-1]->update();
        if(this->in!=nullptr) in->update(clock.delta_time());
        if(this->out!=nullptr) out->update(clock.delta_time());
        this->refresh_cooldown += this->clock.delta_time();
    }
    void draw() const
    {
        scene_list[scene_list.size()-1]->draw();
        if(this->in!=nullptr) in->draw();
        if(this->out!=nullptr) out->draw();
    }
    void run()
    {
        Test *test_scene = new Test(*this);
        scene_list.push_back((Scene*)test_scene);


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
                scene_list[scene_list.size()-1]->handle_event(event);
            }
            if(gameactive)
            {
                update();
                if(this->refresh_cooldown >= 1/refresh_rate){
                    this->refresh_cooldown -= 1/refresh_rate;
                    this->buffer_lost = this->refresh_cooldown*refresh_rate;
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
    Sandtris game;
    game.run();
    return 0;
}