#ifndef SDLGAME_EVENT_
#define SDLGAME_EVENT_
#include "SDL2/SDL_events.h"
#include <string>
#include <map>
namespace sdlgame{
    typedef enum
    {
        QUIT = SDL_QUIT,
        KEYUP = SDL_KEYUP,
        KEYDOWN = SDL_KEYDOWN,
        MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,
        MOUSEBUTTONUP = SDL_MOUSEBUTTONUP,
        MOUSEMOTION = SDL_MOUSEMOTION,
        MOUSEWHEEL = SDL_MOUSEWHEEL,
        WINDOWEVENT = SDL_WINDOWEVENT,
        USEREVENT = SDL_USEREVENT
    } Event_Code;

    typedef enum
    {
        WINDOWSHOWN = SDL_WINDOWEVENT_SHOWN,              // Window became shown
        WINDOWHIDDEN = SDL_WINDOWEVENT_HIDDEN,            // Window became hidden
        WINDOWEXPOSED = SDL_WINDOWEVENT_EXPOSED,          // Window got updated by some external event
        WINDOWMOVED = SDL_WINDOWEVENT_MOVED,              // Window got moved
        WINDOWRESIZED = SDL_WINDOWEVENT_RESIZED,          // Window got resized
        WINDOWSIZECHANGED = SDL_WINDOWEVENT_SIZE_CHANGED, // Window changed its size
        WINDOWMINIMIZED = SDL_WINDOWEVENT_MINIMIZED,      // Window was minimized
        WINDOWMAXIMIZED = SDL_WINDOWEVENT_MAXIMIZED,      // Window was maximized
        WINDOWRESTORED = SDL_WINDOWEVENT_RESTORED,        // Window was restored
        WINDOWENTER = SDL_WINDOWEVENT_ENTER,              // Mouse entered the window
        WINDOWLEAVE = SDL_WINDOWEVENT_LEAVE,              // Mouse left the window
        WINDOWFOCUSGAINED = SDL_WINDOWEVENT_FOCUS_GAINED, // Window gained focus
        WINDOWFOCUSLOST = SDL_WINDOWEVENT_FOCUS_LOST,     // Window lost focus
        WINDOWCLOSE = SDL_WINDOWEVENT_CLOSE,              // Window was closed
        WINDOWTAKEFOCUS = SDL_WINDOWEVENT_TAKE_FOCUS,     // Window was offered focus (SDL backend >= 2.0.5)
        WINDOWHITTEST = SDL_WINDOWEVENT_HIT_TEST,         // Window has a special hit test (SDL backend >= 2.0.5)
    } Window_Event;
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