#include "MainMenu.hpp"
#include "constant.hpp"
MainMenu::MainMenu(Game &game) : Scene(game){
    this->start_button = StartButton(game);
    this->start_button.rect.setTopLeft(8,RESOLUTION_HEIGHT-8*3-16*3);
    this->credit_button = CreditButton(game);
    this->credit_button.rect.setTopLeft(8,RESOLUTION_HEIGHT-8*2-16*2);
    this->quit_button = QuitButton(game);
    this->quit_button.rect.setTopLeft(8,RESOLUTION_HEIGHT-8-16);
}
void MainMenu::handle_event(Event &event)
{
    this->start_button.handle_event(event);
    this->quit_button.handle_event(event);
    this->credit_button.handle_event(event);
}
void MainMenu::update(){
    this->start_button.update();
    this->quit_button.update();
    this->credit_button.update();
}
void MainMenu::draw(){
    this->game->window.blit(this->game->images.mainmenu_background,sdlgame::math::Vector2());
    this->game->window.blit(this->start_button.image,this->start_button.rect.getTopLeft());
    this->game->window.blit(this->credit_button.image,this->credit_button.rect.getTopLeft());
    this->game->window.blit(this->quit_button.image,this->quit_button.rect.getTopLeft());
}
MainMenu::~MainMenu()
{
    
}