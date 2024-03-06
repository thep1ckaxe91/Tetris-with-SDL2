#include "GamePlay.hpp"
#include "Game.hpp"
#include "constant.hpp"
GamePlay::GamePlay(Game &game) : Scene(game)
{
    background = Surface(RESOLUTION_WIDTH,RESOLUTION_HEIGHT);
}
void GamePlay::handle_event(sdlgame::event::Event &event)
{
    
}
void GamePlay::update()
{
    this->background.fill("orange");
}
void GamePlay::draw()
{
    this->game->window.blit(this->background,Vector2());
    this->game->window.blit(this->game->images.game_frame,Vector2());
}