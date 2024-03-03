#ifndef SDLGAME_EVENT_
#define SDLGAME_EVENT_
#include "SDL2/SDL_events.h"
#include <string>
#include <vector>
#include <map>
namespace sdlgame{
    enum class Event_Code;

    enum class Window_Event;
    namespace event
    {
        /**
         *  class represent a event like keyboard input or mouse click (anything happening in the game)
         */
        class Event
        {
        private:
            std::map<std::string, Uint32> dict;

        public:
            Uint32 type;
            Uint32 timestamp;
            SDL_Event tmp_e;
            Event();
            Event(SDL_Event e);
            Uint32 operator[](std::string key);
        };
        std::vector<Event> current_events;
        std::vector<Event> &get();
        Event tmp;
        /**please only use this for user event*/
        void post(Uint32 event_type);
    }
}

#endif