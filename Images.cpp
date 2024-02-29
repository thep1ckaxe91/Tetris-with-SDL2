#include "Images.hpp"
#include "engine.hpp"
#include "constant.hpp"
using Surface = sdlgame::surface::Surface;
Images::Images()
{
    this->start_button_idle = new Surface(sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_idle.png"));
    this->start_button_hover = new Surface(sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_hover.png"));
    this->start_button_click = new Surface(sdlgame::image::load(base_path + "data/image/ui/start_button/start_button_click.png"));

    this->quit_button_idle = new Surface(sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_idle.png"));
    this->quit_button_hover = new Surface(sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_hover.png"));
    this->quit_button_click = new Surface(sdlgame::image::load(base_path + "data/image/ui/quit_button/quit_button_click.png"));

    this->credit_button_idle = new Surface(sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_idle.png"));
    this->credit_button_hover = new Surface(sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_hover.png"));
    this->credit_button_click = new Surface(sdlgame::image::load(base_path + "data/image/ui/credit_button/credit_button_click.png"));

    this->game_frame = new Surface(sdlgame::image::load(base_path + "data/image/background/game_frame.png"));
    this->mainmenu_background = new Surface(sdlgame::image::load(base_path + "data/image/background/mainmenu_sand_background.png"));
}