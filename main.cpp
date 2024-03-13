#include "engine/engine.hpp"
#include "MainMenu.hpp"
#include "constant.hpp"
// #include "engine/gpu_optimize.hpp"
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
        sdlgame::display::fullscreen_desktop();
        images.load();
        sdlgame::display::set_caption("Sandtris - Made by thep1ckaxe");
        // cout<<this->images.start_button_idle.texture<<" "<<this->images.start_button_hover.texture<<" "<<this->images.start_button_click.texture<<endl;
        // exit(0);
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
        window.fill(Color(0,0,0));
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
            vector<Event> events = sdlgame::event::get();
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
                        sdlgame::display::get_window_size();
                    }
                }
                if(gameactive) scene_list[scene_list.size()-1]->handle_event(event);
            }
            if(gameactive)
            {
                update();
                draw();
                sdlgame::display::flip();
                // sdlgame::display::set_caption((to_string(clock.get_fps())).c_str());
            }
            clock.tick(MAXFPS);
        }
    }
};

int main(int argc, char** argv)
{
    sdlgame::init();
    sdlgame::mixer::init();
    Sandtris game; 
    game.run();
    return 0;
}
/**
 * TODO: the image was change when window resize, related to somehow all image located in images was swap? offset memory? 
 * whatever the case TRY:
 * blit all image at the same time
 * check texture memory, everything around Images.cpp/hpp
*/