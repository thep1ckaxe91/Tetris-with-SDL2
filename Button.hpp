#ifndef BUTTON_HPP
#define BUTTON_HPP
using namespace std;

//call handle event for button update, also, you need to add click to call function your self
class Button : public sdlgame::sprite::Sprite
{
public:
    Surface idle, hover, click;
    bool hovering = 0,prev_hovered = 0;
    std::function<void()> onClickFunction;
    Button();
    void set_images(Surface idle, Surface hover, Surface click);
    template <typename... Args>
    void setOnClick(function<void(Args...)> func);
    template <typename... Args>
    void onClick(Args &&...args);

    void handle_event(Event &event);

    virtual void update();
};

#endif