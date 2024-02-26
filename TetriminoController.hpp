#ifndef TETRIMINO_CONTROLLER_HPP
#define TETRIMINO_CONTROLLER_HPP
#include "engine.hpp"
#include "Tetrimino.hpp"
#include "Sand.hpp"
#include "Game.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;


/**
 * 
 * The controller IS NOT RESPONSIBLE to check if the tetrimino is collide with any Sand yet,
 * that's the grid responsible for that
 * this also responsible for drawing and controlling the tetrimino movement, rotation
 * if the tetrimino is collided, the controller will send a event
 * and the scene controll the game will say to the grid to merge the Tetrimino with it
 * The grid should receive a tetrimino type object and start merging and checking
*/
class TetriminoController
{
public:
    Surface draw_surf;
    Tetrimino tetrimino;
    Vector2 topleft;
    Game* game;
    TetriminoController(Game &game, Tetrimino tetrimino)
    {
        this->game = &game;
        this->tetrimino = tetrimino;
        draw_surf = Surface(EDGE_SIZE,EDGE_SIZE);
        topleft = spawn_pos;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                sdlgame::draw::rect(
                    draw_surf,
                    (this->tetrimino.mask>>(15-i*4+j)&1 ? SandShiftColor[this->tetrimino.color] : Color()),
                    Rect(8*j,8*i,8,8)
                );
    }
    void reset(Tetrimino tetrimino)
    {
        this->tetrimino = tetrimino;
        topleft = spawn_pos;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                sdlgame::draw::rect(
                    draw_surf,
                    (this->tetrimino.mask>>(15-i*4+j)&1 ? SandShiftColor[this->tetrimino.color] : Color()),
                    Rect(8*j,8*i,8,8)
                );
    }
    void draw() const
    {
        this->game->window.blit(this->draw_surf,this->topleft);
    }
    void update()
    {
        //movement
        auto keys = sdlgame::key::get_pressed();
        this->topleft.x +=
            (
                (keys[sdlgame::K_d] or keys[sdlgame::K_RIGHT])
                -(keys[sdlgame::K_a] or keys[sdlgame::K_LEFT])
            ) * sideway_move_speed * this->game->clock.delta_time();
        this->topleft.y += this->game->clock.delta_time() * (keys[sdlgame::K_s] or keys[sdlgame::K_DOWN] ? fast_fall_speed : fall_speed);
    }
    void rotate()
    {
        this->tetrimino.rotate();
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                sdlgame::draw::rect(
                    draw_surf,
                    (this->tetrimino.mask>>(15-i*4+j)&1 ? SandShiftColor[this->tetrimino.color] : Color()),
                    Rect(8*j,8*i,8,8)
                );
    }
    void handle_event(Event &event)
    {
        if(event.type == sdlgame::KEYDOWN)
        {
            if(event["key"] == sdlgame::K_UP or event["key"] == sdlgame::K_w) this->rotate();
        }
    }
};

#endif