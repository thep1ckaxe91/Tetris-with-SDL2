#include "GamePlay.hpp"
#include "Game.hpp"
#include "constant.hpp"
GamePlay::GamePlay(Game &game) : Scene(game)
{
    grid = Grid(game);
    background = this->game->images.mainmenu_background;
    this->score_font = Font(base_path+"data/fonts/santris-pixel.ttf",FONT_SIZE);
    this->score_surf = score_font.render("0",0,"white");
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
    sdlgame::draw::rect(this->game->window,SandShiftColor[this->grid.next.color],next_color_display_rect);
    this->game->window.blit(this->game->images.game_frame,Vector2());
    /**
     * TODO: draw next shape
    */
    this->grid.draw();
    this->game->window.blit(this->score_surf,this->score_rect.getTopLeft());
    
 }