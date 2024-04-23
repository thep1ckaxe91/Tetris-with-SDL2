#ifndef IMAGES_HPP
#define IMAGES_HPP
#include "engine/engine.hpp"

class Images
{
public:
    Surface start_button_idle; // maximized shift from here , 5th shift
    Surface start_button_hover;
    Surface start_button_click;
    
    Surface credit_button_idle;
    Surface credit_button_hover;// to here -> 4 size shifted
    Surface credit_button_click;
    // 2nd from maximized to minimized
    Surface quit_button_idle;
    Surface quit_button_hover;// 2nd shift to here, 8th shift
    Surface quit_button_click;

    Surface option_button_idle;//6th shift
    Surface option_button_hover;//3rd shift to here
    Surface option_button_click;//7th shift

    Surface back_button_idle;
    Surface back_button_hover;//4th shift to here
    Surface back_button_click;

    Surface menu_button_idle;
    Surface menu_button_hover;
    Surface menu_button_click;

    Surface retry_button_idle;
    Surface retry_button_hover;
    Surface retry_button_click;

    Surface gameplay_background;
    Surface mainmenu_background;
    Surface credit_image;
    Surface game_frame;
    Surface instruction_image;
    Surface pb_background;

    Surface gameover_screen;

    Images();
    void load();
};

#endif