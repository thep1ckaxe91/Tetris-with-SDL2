#include "../MainMenu.hpp"
MainMenu::MainMenu(Game &game) : Scene(game){
    this->start_button = new StartButton(game);
}
void handle_event(Event &event)
{

}
void update(){
    
}
void draw(){
    this->game->window.blit(this->game->images.mainmenu_background,Vector2());
}
MainMenu::~MainMenu()
{
    delete start_button;
}