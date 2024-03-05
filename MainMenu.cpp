#include "MainMenu.hpp"
#include "StartButton.hpp"
#include "engine/engine.hpp"
#include "constant.hpp"
MainMenu::MainMenu(Game &game) : Scene(game){
    this->start_button = StartButton(game);
    this->start_button.rect.setTop(RESOLUTION_HEIGHT-8*3-16*3);
    this->start_button.rect.setLeft(8);
}
void MainMenu::handle_event(Event &event)
{
    this->start_button.handle_event(event);
}
void MainMenu::update(){
    this->start_button.update();
}
void MainMenu::draw(){
    this->game->window.blit(this->game->images.mainmenu_background,sdlgame::math::Vector2());
    this->game->window.blit(this->start_button.image,this->start_button_pos);
}
MainMenu::~MainMenu()
{
    
}