#include "Option.hpp"

Option::Option(Game &game) : Scene(game)
{
    sfx_slider = SFXVolumeSlider(game,Vector2(80,32),1,48,1);
    music_slider = MusicVolumeSlider(game,Vector2(80,64),1,48,1);
}
Option::Option()=default;
void Option::update()
{
    sfx_slider.update();
    music_slider.update();
}
void Option::handle_event(Event &event)
{
    sfx_slider.handle_event(event);
    music_slider.handle_event(event);
}
void Option::draw()
{
    sfx_slider.draw();
    music_slider.draw();
}