#ifndef IMAGES_HPP
#define IMAGES_HPP
#include "engine.hpp"
#include "constant.hpp"
//Load all image for use here
class Images
{
public:
    Surface start_button_idle = sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_idle.png");
    Surface start_button_hover = sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_hover.png");
    Surface start_button_click = sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_click.png");

    Surface quit_button_idle = sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_idle.png");
    Surface quit_button_hover = sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_hover.png");
    Surface quit_button_click = sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_click.png");

    Surface credit_button_idle = sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_idle.png");
    Surface credit_button_hover = sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_hover.png");
    Surface credit_button_click = sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_click.png");

    Surface game_frame = sdlgame::image::load(base_path + "data/image/background/game_frame.png");
    Surface mainmenu_background = sdlgame::image::load(base_path + "data/image/background/mainmenu_sand_background.png");
    Images() = default;
};
#endif