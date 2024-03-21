#include "Button.hpp"
#include "Game.hpp"
class MenuButton : public Button
{
    Game *game;
public:
    MenuButton(Game *game);
    void handle_event(Event &event);
    void update();
    void draw();
}