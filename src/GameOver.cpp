#include "GameOver.hpp"


GameOver::GameOver(Game &game) : Scene(game)
{
    
}

void GameOver::handle_event(Event &event)
{

}

void GameOver::update()
{

}

void GameOver::draw()
{
    this->game->window.fill("white");
}