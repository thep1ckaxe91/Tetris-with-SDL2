#include "MainMenu.hpp"
#include "StartButton.hpp"
#include "engine/engine.hpp"
MainMenu::MainMenu(Game &game) : Scene(game){
    this->start_button = StartButton(game);
}
void MainMenu::handle_event(Event &event)
{

}
void MainMenu::update(){
    
}
void MainMenu::draw(){
    this->game->window.blit(this->game->images.mainmenu_background,sdlgame::math::Vector2());
}
MainMenu::~MainMenu()
{
    
}