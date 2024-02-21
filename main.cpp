#include "engine.hpp"
#include "constant.hpp"
#ifdef __cplusplus
extern "C"
{
#endif

    __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
    __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
#ifdef __cplusplus
}
#endif
using namespace std;
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
class Game
{
public:
    Surface window;
    sdlgame::time::Clock clock;
    int FPS=60;
    bool running;
    Game(){
        window = sdlgame::display::set_mode(desktop_size.x,desktop_size.y,
            sdlgame::RENDERER_ACCELERATED
        );
        clock = sdlgame::time::Clock();
    }
    void run(){
        running = 1;
        while(running)
        {
            auto events = sdlgame::event::get();
            for(auto &event : events){
                if(event.type == sdlgame::QUIT){
                    sdlgame::quit();
                    exit(0);
                }
            }

            sdlgame::display::flip();
            clock.tick(FPS);
        }
    }
};

int main(int argc, char* argv[]){

    Game game;

    game.run();

    return 0;
}