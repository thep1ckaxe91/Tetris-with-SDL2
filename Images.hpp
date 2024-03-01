#ifndef IMAGES_HPP
#define IMAGES_HPP
#include "engine.hpp"
class sdlgame::surface::Surface;

class Images
{
public:
    sdlgame::surface::Surface start_button_idle;
    sdlgame::surface::Surface start_button_hover;
    sdlgame::surface::Surface start_button_click;
    
    sdlgame::surface::Surface credit_button_idle;
    sdlgame::surface::Surface credit_button_hover;
    sdlgame::surface::Surface credit_button_click;
    
    sdlgame::surface::Surface quit_button_idle;
    sdlgame::surface::Surface quit_button_hover;
    sdlgame::surface::Surface quit_button_click;

    sdlgame::surface::Surface mainmenu_background;
    sdlgame::surface::Surface game_frame;
    Images();
};

#endif