#include "OptionElement.hpp"

SFXVolumeSlider::SFXVolumeSlider(Game &game, Vector2 topleft, float val, float length, float max_val)
{   
    
    this->game = &game;
    this->set_color("white","white","gray");
    this->set_label("SFX Volume: ","white");
}
SFXVolumeSlider::SFXVolumeSlider()=default;
void SFXVolumeSlider::update()
{
    Slider::update();
}
void SFXVolumeSlider::handle_event(Event &event)
{
    Slider::handle_event(event);
}
void SFXVolumeSlider::draw()
{
    this->game->window.blit(this->label_surf,label_rect.getTopLeft());
    sdlgame::draw::line(this->game->window,this->value_color,topleft,topleft+Vector2(this->slide_length,0)*(this->value/this->max_value));
    sdlgame::draw::line(this->game->window,this->no_value_color,topleft+Vector2(slide_length,0),topleft+Vector2(this->slide_length,0)*(this->value/this->max_value));
    sdlgame::draw::rect(this->game->window,this->nob_color,nob);
}
void SFXVolumeSlider::on_change_value()
{
    this->game->audio_manager.set_sfx_volume(this->value/this->max_value);
}


MusicVolumeSlider::MusicVolumeSlider(Game &game, Vector2 topleft, float val, float length, float max_val)
{   
    
    this->game = &game;
    this->set_color("white","white","gray");
    this->set_label("Music Volume: ","white");
}
MusicVolumeSlider::MusicVolumeSlider()=default;
void MusicVolumeSlider::update()
{
    Slider::update();
}
void MusicVolumeSlider::handle_event(Event &event)
{
    Slider::handle_event(event);
}
void MusicVolumeSlider::draw()
{
    this->game->window.blit(this->label_surf,label_rect.getTopLeft());
    sdlgame::draw::line(this->game->window,this->value_color,topleft,topleft+Vector2(this->slide_length,0)*(this->value/this->max_value));
    sdlgame::draw::line(this->game->window,this->no_value_color,topleft+Vector2(slide_length,0),topleft+Vector2(this->slide_length,0)*(this->value/this->max_value));
    sdlgame::draw::rect(this->game->window,this->nob_color,nob);
}
void MusicVolumeSlider::on_change_value()
{
    this->game->audio_manager.set_music_volume(this->value/this->max_value);
}
// OptionElement::OptionElement(Vector2 topleft, string name, float value, float max_value)
// {

// }
// OptionElement::OptionElement()=default;
// void OptionElement::update()
// {
//     this->setter.sfx_slider.update();
// }
// void OptionElement::handle_event(Event &event)
// {
//     this->setter.sfx_slider.handle_event(event);
// }
// void OptionElement::draw()
// {

// }