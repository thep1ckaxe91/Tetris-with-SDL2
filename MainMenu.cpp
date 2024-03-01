#include "MainMenu.hpp"
#include "engine.hpp"
MainMenu::MainMenu(Game &game) : Scene(game){
    this->start_button = new StartButton(game);
}
void MainMenu::handle_event(sdlgame::event::Event &event)
{

}
void MainMenu::update(){
    
}
void MainMenu::draw(){
    this->game->window.blit(this->game->images.mainmenu_background,sdlgame::math::Vector2());
}
MainMenu::~MainMenu()
{
    delete start_button;
}