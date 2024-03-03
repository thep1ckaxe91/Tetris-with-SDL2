#include"music.hpp"
#include <string>
#include "SDL2/SDL_mixer.h"
void sdlgame::music::load(std::string path)
{
    if (music != NULL)
        Mix_FreeMusic(music);
    music = Mix_LoadMUS(path.c_str());
    if (!music)
    {
        printf("Cant load music\nErr:%s\n", Mix_GetError());
        exit(0);
    }
}
void sdlgame::music::play(int loop = 0)
{
    if (Mix_PlayMusic(music, loop))
    {
        printf("Cant play music\nErr:%s\n", Mix_GetError());
        exit(0);
    }
}
void sdlgame::music::pause()
{
    Mix_PauseMusic();
}
void sdlgame::music::resume()
{
    Mix_ResumeMusic();
}
void sdlgame::music::stop()
{
    Mix_HaltMusic();
}
// Return duration of the music in second
double sdlgame::music::duration()
{
    return Mix_MusicDuration(music);
}