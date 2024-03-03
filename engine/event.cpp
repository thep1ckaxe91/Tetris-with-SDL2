#include "event.hpp"
#include <vector>
#include <string>
#include <stdexcept>
using Event = sdlgame::event::Event;
namespace sdlgame::event{
    enum class Event_Code{
        QUIT = SDL_QUIT,
        KEYUP = SDL_KEYUP,
        KEYDOWN = SDL_KEYDOWN,
        MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,
        MOUSEBUTTONUP = SDL_MOUSEBUTTONUP,
        MOUSEMOTION = SDL_MOUSEMOTION,
        MOUSEWHEEL = SDL_MOUSEWHEEL,
        WINDOWEVENT = SDL_WINDOWEVENT,
        USEREVENT = SDL_USEREVENT
    };
    enum class Window_Event{
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
    };
}

sdlgame::event::Event::Event() = default;
sdlgame::event::Event::Event(SDL_Event e)
{
    tmp_e = e;
    type = e.type;
    /**
     * @todo: leave these here in case need, now type only is good enough
     */
    if (e.type == SDL_WINDOWEVENT)
    {
        timestamp = e.window.timestamp;
        dict["windowID"] = e.window.windowID; /**< The associated window */
        dict["event"] = e.window.event;
    }
    else if (e.type == SDL_KEYDOWN or e.type == SDL_KEYUP)
    {
        timestamp = e.key.timestamp;
        dict["key"] = e.key.keysym.scancode;
    }
    else if (e.type == SDL_QUIT)
    {
        // lol, just here to write const event
    }
    else if (e.type == SDL_MOUSEWHEEL)
    {
        timestamp = e.wheel.timestamp;
        dict["x"] = e.wheel.x;
        dict["y"] = e.wheel.y;
    }
    else if (e.type == SDL_MOUSEBUTTONUP or e.type == SDL_MOUSEBUTTONDOWN)
    {
        timestamp = e.button.timestamp;
        dict["button"] = e.button.button;
        dict["x"] = e.button.x;
        dict["y"] = e.button.y;
    }
    else if (e.type == SDL_MOUSEMOTION)
    {
        timestamp = e.motion.timestamp;
        dict["x"] = e.motion.x;
        dict["y"] = e.motion.y;
        dict["xrel"] = e.motion.xrel;
        dict["yrel"] = e.motion.yrel;
    }
}
Uint32 sdlgame::event::Event::operator[](std::string key)
{
    if (dict.find(key) != dict.end())
    {
        return dict[key];
    }
    else
    {
        throw std::invalid_argument("There's no such key: " + key);
    }
}
std::vector<Event> &sdlgame::event::get()
{
    SDL_PumpEvents();
    current_events.clear();
    SDL_Event e;
    while (SDL_PollEvent(&e))
        current_events.push_back(Event(e));
    return current_events;
    }
    Event tmp;
    /**please only use this for user event*/
    void post(Uint32 event_type)
    {
    tmp.tmp_e.type = event_type;
    SDL_PushEvent(&tmp.tmp_e);
}
void sdlgame::event::post(Uint32 event_type)
{
    tmp.tmp_e.type = event_type;
    SDL_PushEvent(&tmp.tmp_e);
}