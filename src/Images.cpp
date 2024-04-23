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

    back_button_idle = sdlgame::image::load(base_path + "data/image/ui/back_button/back_button_idle.png");
    back_button_hover = sdlgame::image::load(base_path + "data/image/ui/back_button/back_button_hover.png");
    back_button_click = sdlgame::image::load(base_path + "data/image/ui/back_button/back_button_click.png");

    menu_button_idle = sdlgame::image::load(base_path + "data/image/ui/menu_button/menu_button_idle.png");
    menu_button_hover = sdlgame::image::load(base_path + "data/image/ui/menu_button/menu_button_hover.png");
    menu_button_click = sdlgame::image::load(base_path + "data/image/ui/menu_button/menu_button_click.png");

    retry_button_idle = sdlgame::image::load(base_path + "data/image/ui/retry_button/retry_button_idle.png");
    retry_button_hover = sdlgame::image::load(base_path + "data/image/ui/retry_button/retry_button_hover.png");
    retry_button_click = sdlgame::image::load(base_path + "data/image/ui/retry_button/retry_button_click.png");


    gameplay_background = sdlgame::image::load(base_path + "data/image/background/gameplay_background.png");
    mainmenu_background = sdlgame::image::load(base_path + "data/image/background/mainmenu_sand_background.png");
    credit_image = sdlgame::image::load(base_path + "data/image/background/credit_image.png");
    game_frame = sdlgame::image::load(base_path + "data/image/background/game_frame.png");
    instruction_image = sdlgame::image::load(base_path + "data/image/background/instruction.png");
    pb_background = sdlgame::image::load(base_path + "data/image/background/view_personal_best.png");

    gameover_screen = sdlgame::image::load(base_path + "data/image/background/gameover_screen.png");

}