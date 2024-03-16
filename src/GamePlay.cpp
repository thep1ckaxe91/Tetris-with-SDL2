#include "GamePlay.hpp"
#include "Game.hpp"
#include "constant.hpp"
GamePlay::GamePlay(Game &game) : Scene(game)
{
    grid = Grid(game);
    background = this->game->images.mainmenu_background;
    // score_font = Font(base_path+"data/fonts/Minecraft.ttf");
    score_font = Font(base_path+"data/fonts/basis33.ttf",5);
}
void GamePlay::handle_event(sdlgame::event::Event &event)
{
    this->grid.handle_event(event);
}
void GamePlay::update()
{
    this->grid.update();
    this->score_surf = score_font.render(to_string(this->grid.get_score()),0,"white");
    this->score_rect = score_surf.getRect();
    score_rect.setCenter(score_display_center);
}
void GamePlay::draw()
{
    this->game->window.blit(this->background,Vector2());
    this->game->window.blit(this->game->images.game_frame,Vector2());
    this->grid.draw();

}