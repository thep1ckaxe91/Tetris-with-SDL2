#include "Images.hpp"
#include "engine/engine.hpp"
Images::Images()
{
}
void Images::load()
{
    std::string base_path = sdlgame::get_base_path();
    start_button_idle = sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_idle.png");
    start_button_hover = sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_hover.png");
    start_button_click = sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_click.png");

    credit_button_idle = sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_idle.png");
    credit_button_hover = sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_hover.png");
    credit_button_click = sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_click.png");

    quit_button_idle = sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_idle.png");
    quit_button_hover = sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_hover.png");
    quit_button_click = sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_click.png");

    option_button_idle = sdlgame::image::load(base_path + "data/image/ui/option_button/option_button_idle.png");
    option_button_hover = sdlgame::image::load(base_path + "data/image/ui/option_button/option_button_hover.png");
    option_button_click = sdlgame::image::load(base_path + "data/image/ui/option_button/option_button_click.png");

    back_button_idle = sdlgame::image::load(base_path + "data/image/ui/back_button/back_button_idle.png");
    back_button_hover = sdlgame::image::load(base_path + "data/image/ui/back_button/back_button_hover.png");
    back_button_click = sdlgame::image::load(base_path + "data/image/ui/back_button/back_button_click.png");

    mainmenu_background = sdlgame::image::load(base_path + "data/image/background/mainmenu_sand_background.png");
    credit_image = sdlgame::image::load(base_path + "data/image/background/credit_image.png");
    game_frame = sdlgame::image::load(base_path + "data/image/background/game_frame.png");
    // Surface tmp = sdlgame::image::load(base_path + "data/image/background/credit_image.png");
}
/*
start_button_idle ,
start_button_hover , 
start_button_click,

credit_button_idle ,
credit_button_hover ,
credit_button_click ,

quit_button_idle,
quit_button_hover ,
quit_button_click ,

option_button_idle ,
option_button_hover ,
option_button_click,

back_button_idle ,
back_button_hover,
back_button_click,

mainmenu_background,
game_frame,
credit_image
*/