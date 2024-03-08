#include "GamePlay.hpp"
#include "Game.hpp"
#include "constant.hpp"
GamePlay::GamePlay(Game &game) : Scene(game)
{
    background = this->game->images.mainmenu_background;
}
void GamePlay::handle_event(sdlgame::event::Event &event)
{
    this->grid.handle_event(event);
}
void GamePlay::update()
{
    this->grid.update();
}
void GamePlay::draw()
{
    this->game->window.blit(this->background,Vector2());
    this->game->window.blit(this->game->images.game_frame,Vector2());
    this->grid.draw();
}