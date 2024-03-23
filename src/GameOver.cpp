#include "GameOver.hpp"
#include "constant.hpp"
#include "SaveData.hpp"
GameOver::GameOver(Game &game, int new_score) : Scene(game)
{
    menu = MenuButton(game);
    menu.rect = menu.image.getRect();
    menu.rect.setTopLeft(menu_button_pos);

    retry = RetryButton(game);
    retry.rect = retry.image.getRect();
    retry.rect.setTopLeft(retry_button_pos);

    this->new_score = new_score;
    this->pb = get_personal_best();
}

void GameOver::handle_event(Event &event)
{
    menu.handle_event(event); 
    retry.handle_event(event);
}

void GameOver::update()
{
    menu.update();
    retry.update();
}

void GameOver::draw()
{
    this->game->window.blit(this->game->images.gameover_screen,Vector2());
    this->game->window.blit(this->menu.image,menu.rect.getTopLeft());
    this->game->window.blit(this->retry.image,retry.rect.getTopLeft());
}