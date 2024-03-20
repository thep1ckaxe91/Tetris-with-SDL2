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
    next_display_color = this->grid.next.color;
    flow1 = next_color_display_rect;
    flow2 = flow1.move(0,next_color_display_rect.getHeight());
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
        next_display_color = this->grid.next.color;
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
    double delta_y = -flow_speed*this->game->clock.delta_time();
    flow1.move_ip(0,delta_y);
    flow2.move_ip(0,delta_y);
    if(flow1.getBottom()<=next_color_display_rect.getTop())
    {
        flow1.setTop(next_color_display_rect.getBottom());
        color_flow1 = SandShiftColor.at(next_display_color);
    }
    if(flow2.getBottom()<=next_color_display_rect.getTop())
    {
        flow2.setTop(next_color_display_rect.getBottom());
        color_flow2 = SandShiftColor.at(next_display_color);
    }
}
void GamePlay::draw()
{
    this->game->window.blit(this->background,Vector2());

    sdlgame::draw::rect(this->game->window,color_flow1,flow1.inflate(0,min(0.0,next_color_display_rect.getBottom()-flow1.getBottom())+1));
    sdlgame::draw::rect(this->game->window,color_flow2,flow2.inflate(0,min(0.0,next_color_display_rect.getBottom()-flow2.getBottom())+1));

    this->game->window.blit(this->game->images.game_frame,Vector2());
    /**
     * TODO: draw next shape
    */
    this->grid.draw();
    this->game->window.blit(this->score_surf,this->score_rect.getTopLeft());
    
 }