#pragma once
#ifndef SDLGAME_MUSIC_
#define SDLGAME_MUSIC_
#include <string>
#include "SDL2/SDL_mixer.h"
namespace sdlgame {
    namespace music
    {
        extern Mix_Music *music;
        void load(std::string path);
        void play(int loop = 0);
        void pause();
        void resume();
        void stop();
        // Return duration of the music in second
        double duration();
    }
}

#endif