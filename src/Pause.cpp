#include"Pause.hpp"
Pause::Pause(Game &game) : Scene(game)
{
    menu_button = MenuButton(game);
    menu_button.rect.setCenter(80,64);
    option_button = OptionButton(game);
    option_button.rect.setCenter(80,64+24+1);
    retry_button = RetryButton(game);
    retry_button.rect.setCenter(80,64+32+16+2);
    back_button = BackButton(game);
    back_button.rect.setCenter(80,64+3+64);
}

Pause::Pause() = default;

void Pause::update()
{
    menu_button.update();
    option_button.update();
    retry_button.update();
    back_button.update();        
}

void Pause::handle_event(Event &event)
{
    menu_button.handle_event(event);
    option_button.handle_event(event);
    retry_button.handle_event(event);
    back_button.handle_event(event);    
}
void Pause::draw()
{
    this->game->window.blit(this->game->images.pause_background,Vector2());
    this->game->window.blit(menu_button.image,menu_button.rect.getTopLeft());
    this->game->window.blit(option_button.image,option_button.rect.getTopLeft());
    this->game->window.blit(retry_button.image,retry_button.rect.getTopLeft());
    this->game->window.blit(back_button.image,back_button.rect.getTopLeft());
}