#include "AudioManager.hpp"
#include "TetrisEvent.hpp"
AudioManager::AudioManager()
{
    sfx.load();
}
void AudioManager::handle_event(Event &event)
{
    switch (event.type)
    {
    case BUTTON_CLICK:
        sfx.button_click.play();
        break;
    case BUTTON_HOVER:
        sfx.button_hover.play();
        break;
    case COUNT_DOWN:
        sfx.count_down.play();
        break;
    case COUNT_DOWN_START:
        sfx.count_down_start.play();
        break;
    case GAMEOVER:
        sfx.game_over.play();
        break;
    case MERGING:
        sfx.merge.play();
        break;
    case ROTATE:
        sfx.rotate.play();
        break;
    case SCORING:
        sfx.scoring.play();
        break;
    case SCENETRANS_IN:
        sfx.transition_in.play();
        break;
    case SCENETRANS_OUT:
        sfx.transition_out.play();
        break;
    default:
        break;
    }
}
void AudioManager::update()
{
     
}