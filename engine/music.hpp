#ifndef SDLGAME_MUSIC_
#define SDLGAME_MUSIC_

namespace sdlgame {
    namespace music
    {
        Mix_Music *music = NULL;
        bool playing = 0;
        void load(std::string path)
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
        void play(int loop = 0)
        {
            if (Mix_PlayMusic(music, loop))
            {
                printf("Cant play music\nErr:%s\n", Mix_GetError());
                exit(0);
            }
        }
        void pause()
        {
            Mix_PauseMusic();
        }
        void resume()
        {
            Mix_ResumeMusic();
        }
        void stop()
        {
            Mix_HaltMusic();
        }
        // Return duration of the music in second
        double duration()
        {
            return Mix_MusicDuration(music);
        }
    }
}

#endif