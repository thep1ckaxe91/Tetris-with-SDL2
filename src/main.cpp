#include "engine/engine.hpp"
#include "MainMenu.hpp"
#include "constant.hpp"
#include "engine/gpu_optimize.hpp"
#include "TetrisEvent.hpp"
using namespace std;
// If global declare is bad, i make MY OWN global declare >:)

class Sandtris : public Game
{
public:
    bool gameactive = 1;
    int buffer_lost = 0;
    Sandtris() : Game()
    {
        this->window_object = sdlgame::display::set_mode(
            RESOLUTION_WIDTH, RESOLUTION_HEIGHT,
            0
            |sdlgame::MAXIMIZED
            // |sdlgame::RESIZABLE
        );
        this->window = Surface(RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
        // sdlgame::display::fullscreen_desktop();
        images.load();
        audio_manager.sfx.load();
        sdlgame::display::set_caption("Sandtris - Made by thep1ckaxe");
        sdlgame::display::set_icon((base_path + "data/image/icon/icon.png").c_str());
        // cout<<this->images.start_button_idle.texture<<" "<<this->images.start_button_hover.texture<<" "<<this->images.start_button_click.texture<<endl;
        // exit(0);
    }
    void update()
    {
        if (!scene_list.empty())
            if (scene_list.back())
            {
                scene_list.back()->update();
            }
        if (this->out)
        {
            sdlgame::event::post(SCENETRANS_OUT);
            out->update(clock.delta_time());
            if (out->isDone)
            {
                delete out;
                out = nullptr;
            }
        }
        else if (this->in)
        {
            sdlgame::event::post(SCENETRANS_IN);
            if (this->next)
            {
                delete scene_list.back();
                scene_list.pop_back();
                scene_list.push_back(this->next);
                this->next = nullptr;
            }
            in->update(clock.delta_time());
            if (in->isDone)
            {
                delete in;
                in = nullptr;
            }
        }
        audio_manager.update();
    }
    void draw()
    {
        window.fill(Color(0, 0, 0));
        if (!scene_list.empty())
            if (scene_list.back())
            {
                scene_list.back()->draw();
            }
        window_object.blit(this->window, this->window_draw_offset);
        if (this->out)
        {
            out->draw();
        }
        else if (this->in)
        {
            in->draw();
        }
    }
    void run()
    {
        MainMenu *mainmenu = new MainMenu(*this);
        this->scene_list.push_back(mainmenu);
        while (true)
        {
            for (auto &event : sdlgame::event::get())
            {
                if (event.type == sdlgame::QUIT)
                {
                    sdlgame::quit();
                    exit(0);
                }
                else if (event.type == sdlgame::WINDOWEVENT)
                {
                    if (event["event"] == sdlgame::WINDOWFOCUSGAINED)
                        gameactive = 1;
                    else if (event["event"] == sdlgame::WINDOWFOCUSLOST)
                        gameactive = 0;
                    else if (event["event"] == sdlgame::WINDOWRESIZED)
                    {
                        sdlgame::display::get_window_size();
                    }
                }
                if (gameactive)
                {
                    scene_list[scene_list.size() - 1]->handle_event(event);
                    audio_manager.handle_event(event);
                }
            }
            if (gameactive)
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

int main(int argc, char **argv)
{
    sdlgame::init();
    sdlgame::mixer::init();
    sdlgame::mixer::set_num_channels(16);
    Sandtris game;
    game.run();
    return 0;
}
/**
 *
 */