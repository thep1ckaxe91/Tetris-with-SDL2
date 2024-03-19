#include "GamePlay.hpp"
#include "Game.hpp"
#include "constant.hpp"
#include "TetrisEvent.hpp"
GamePlay::GamePlay(Game &game) : Scene(game)
{
    grid = Grid(game);
    background = this->game->images.mainmenu_background;
    this->score_font = Font(base_path+"data\\fonts\\sandtris pixel.ttf",FONT_SIZE);
    this->score_surf = score_font.render("0",0,"white");
    this->score_rect = score_surf.getRect();
    score_rect.setCenter(score_display_center);
}
void GamePlay::handle_event(sdlgame::event::Event &event)
{
    this->grid.handle_event(event);
    if(event.type == SCORING)
    {
        this->score_surf = score_font.render(to_string(this->grid.get_score()),0,"white");
        this->score_rect = score_surf.getRect();
        score_rect.setCenter(score_display_center);
    }
    else if(event.type == MERGING)
    {
        /**
         * TODO: have 2 rect repeately moving upward, its color will be update
         * base on "current color of next shape" the moment when it reset the
         * position is when to change the color
         * 
         */
    }
}
void GamePlay::update()
{
    this->grid.update();
    
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