#ifndef IMAGES_HPP
#define IMAGES_HPP
//Load all image for use here
class Surface;
class Images
{
public:
Surface *start_button_idle;
Surface *start_button_hover;
Surface *start_button_click;

Surface *quit_button_idle;
Surface *quit_button_hover;
Surface *quit_button_click;

Surface *credit_button_idle;
Surface *credit_button_hover;
Surface *credit_button_click;

Surface *game_frame;
Surface *mainmenu_background;
public:
    Images();
};
#endif