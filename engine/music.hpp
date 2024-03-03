#ifndef SDLGAME_MUSIC_
#define SDLGAME_MUSIC_
#include <string>
namespace sdlgame {
    namespace music
    {
        Mix_Music *music;
        bool playing;
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