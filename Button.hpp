#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <any>
class Button
{
public:
    std::any idle;
    std::any hover;
    std::any click;
    bool hovering=0;
    Button();
    template<class T>
    void set_images(T idle, T hover, T click){
        this->idle = idle;
        this->hover = hover;
        this->click = click;
    }
    virtual void handle_event(std::any &event);
    virtual void update();
    ~Button()
    {
        idle.~Surface();
        hover.~Surface();
        click.~Surface();
    }

};

#endif