#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <any>
class Button
{
    std::any idle;
    std::any hover;
    std::any click;
    Button();
};

#endif