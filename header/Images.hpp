#ifndef IMAGES_HPP
#define IMAGES_HPP
#include "engine/engine.hpp"

class Images
{
public:
    sdlgame::surface::Surface start_button_idle; // maximized shift from here , 5th shift
    sdlgame::surface::Surface start_button_hover;
    sdlgame::surface::Surface start_button_click;
    
    sdlgame::surface::Surface credit_button_idle;
    sdlgame::surface::Surface credit_button_hover;// to here -> 4 size shifted
    sdlgame::surface::Surface credit_button_click;
    // 2nd from maximized to minimized
    sdlgame::surface::Surface quit_button_idle;
    sdlgame::surface::Surface quit_button_hover;// 2nd shift to here, 8th shift
    sdlgame::surface::Surface quit_button_click;

    sdlgame::surface::Surface option_button_idle;//6th shift
    sdlgame::surface::Surface option_button_hover;//3rd shift to here
    sdlgame::surface::Surface option_button_click;//7th shift

    sdlgame::surface::Surface back_button_idle;
    sdlgame::surface::Surface back_button_hover;//4th shift to here
    sdlgame::surface::Surface back_button_click;

    Surface menu_button_idle;
    Surface menu_button_hover;
    Surface menu_button_click;

    Surface retry_button_idle;
    Surface retry_button_hover;
    Surface retry_button_click;

    Surface gameplay_background;
    sdlgame::surface::Surface mainmenu_background;
    // sdlgame::surface::Surface credit_image;
    sdlgame::surface::Surface game_frame;
    
    Surface gameover_screen;

    Images();
    void load();
};

#endif