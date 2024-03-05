#include "Images.hpp"
#include "engine/engine.hpp"
Images::Images()
{
    
}
void Images::load()
{
    std::string base_path = sdlgame::get_base_path();
    start_button_idle = sdlgame::image::load(base_path+"data/image/ui/start_button/start_button_idle.png");
    start_button_hover = sdlgame::image::load(base_path+"data/image/ui/start_button/start_button_hover.png");
    start_button_click = sdlgame::image::load(base_path+"data/image/ui/start_button/start_button_click.png");
    
    credit_button_idle = sdlgame::image::load(base_path+"data/image/ui/credit_button/credit_button_idle.png");
    credit_button_hover = sdlgame::image::load(base_path+"data/image/ui/credit_button/credit_button_hover.png");
    credit_button_click = sdlgame::image::load(base_path+"data/image/ui/credit_button/credit_button_click.png");
    
    quit_button_idle = sdlgame::image::load(base_path+"data/image/ui/quit_button/quit_button_idle.png");
    quit_button_hover = sdlgame::image::load(base_path+"data/image/ui/quit_button/quit_button_hover.png");
    quit_button_click = sdlgame::image::load(base_path+"data/image/ui/quit_button/quit_button_click.png");
    
    mainmenu_background = sdlgame::image::load(base_path+"data/image/background/mainmenu_sand_background.png");
    game_frame = sdlgame::image::load(base_path+"data/image/background/game_frame.png");
}