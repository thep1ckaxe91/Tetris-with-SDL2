#ifndef OPTION_ELEMENT_HPP
#define OPTION_ELEMENT_HPP
#include "Slider.hpp"
using namespace std;

class SFXVolumeSlider : public Slider
{
    SFXVolumeSlider(Vector2 topleft, float value, float length, float max_value);
    void update();
    void handle_event();
    void draw();
    void on_change_value();
};

class OptionElement
{
public:
    string label;
    Surface label_surf;
    Font label_font;
    
    OptionElement(Vector2 topleft, string name, float value, float max_value);
    void update();
    void handle_event(Event &event);
    void draw();
};

#endif