#include "HowToPlay.hpp"
#include "constant.hpp"

HowToPlay::HowToPlay(Game &game) : Scene(game)
{
    back_button = BackButton(game);
    back_button.rect.setTopLeft(this->bb_pos);
}

void HowToPlay::handle_event(Event &event)
{
    back_button.handle_event(event);
}
void HowToPlay::update()
{
    back_button.update();
}

void HowToPlay::draw()
{
    this->game->window.blit(this->game->images.instruction_image,Vector2());
    this->game->window.blit(this->back_button.image,bb_pos);
}
