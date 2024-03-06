#include "Credit.hpp"
#include "engine/engine.hpp"
#include "Game.hpp"
#include "constant.hpp"
Credit::Credit(Game &game) : Scene(game)
{
    back_button = BackButton(game);
    back_button.rect.setTopRight(0,RESOLUTION_WIDTH);
}
void Credit::handle_event(Event &event)
{
    this->back_button.handle_event(event);
}

void Credit::update()
{
    this->back_button.update();
}
void Credit::draw()
{
    this->game->window.blit(this->game->images.credit_image,Vector2());
    this->game->window.blit(back_button.image,back_button.rect.getTopLeft());
}
