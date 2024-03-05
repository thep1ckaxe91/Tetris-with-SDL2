#include "GamePlay.hpp"
#include "Game.hpp"
GamePlay::GamePlay(Game &game) : Scene(game)
{

}
void GamePlay::handle_event(sdlgame::event::Event &event)
{
    
}
void GamePlay::update()
{

}
void GamePlay::draw()
{
    this->game->window.fill("orange");
    this->game->window.blit(this->game->images.game_frame,Vector2());
}