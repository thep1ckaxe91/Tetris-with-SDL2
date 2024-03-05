#pragma once

#ifndef SDLGAME_CONSTANTS_
#define SDLGAME_CONSTANTS_
#include "SDL2/SDL.h"
namespace sdlgame {
    
    const Uint32 FULLSCREEN = SDL_WINDOW_FULLSCREEN;
    const Uint32 NO_FRAME = SDL_WINDOW_BORDERLESS;
    const Uint32 RESIZABLE = SDL_WINDOW_RESIZABLE;
    const Uint32 HIDDEN = SDL_WINDOW_HIDDEN;
    const Uint32 SKIP_TASK_BAR = SDL_WINDOW_SKIP_TASKBAR;
    const Uint32 POPUP_MENU = SDL_WINDOW_POPUP_MENU;
    const Uint32 ALWAYS_ON_TOP = SDL_WINDOW_ALWAYS_ON_TOP;
    const Uint32 MAXIMIZED = SDL_WINDOW_MAXIMIZED;
    const Uint32 MINIMIZED = SDL_WINDOW_MINIMIZED;
    
    const Uint32 QUIT = SDL_QUIT;
    const Uint32 KEYUP = SDL_KEYUP;
    const Uint32 KEYDOWN = SDL_KEYDOWN;
    const Uint32 MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN;
    const Uint32 MOUSEBUTTONUP = SDL_MOUSEBUTTONUP;
    const Uint32 MOUSEMOTION = SDL_MOUSEMOTION;
    const Uint32 MOUSEWHEEL = SDL_MOUSEWHEEL;
    const Uint32 WINDOWEVENT = SDL_WINDOWEVENT;
    const Uint32 USEREVENT = SDL_USEREVENT;

    const Uint32 WINDOWSHOWN = SDL_WINDOWEVENT_SHOWN;     // Window became shown
    const Uint32 WINDOWHIDDEN = SDL_WINDOWEVENT_HIDDEN;   // Window became hidden
    const Uint32 WINDOWEXPOSED = SDL_WINDOWEVENT_EXPOSED;    // Window got updated by some external event
    const Uint32 WINDOWMOVED = SDL_WINDOWEVENT_MOVED;       // Window got moved
    const Uint32 WINDOWRESIZED = SDL_WINDOWEVENT_RESIZED;      // Window got resized
    const Uint32 WINDOWSIZECHANGED = SDL_WINDOWEVENT_SIZE_CHANGED; // Window changed its size
    const Uint32 WINDOWMINIMIZED = SDL_WINDOWEVENT_MINIMIZED;    // Window was minimized
    const Uint32 WINDOWMAXIMIZED = SDL_WINDOWEVENT_MAXIMIZED;   // Window was maximized
    const Uint32 WINDOWRESTORED = SDL_WINDOWEVENT_RESTORED;     // Window was restored
    const Uint32 WINDOWENTER = SDL_WINDOWEVENT_ENTER;    // Mouse entered the window
    const Uint32 WINDOWLEAVE = SDL_WINDOWEVENT_LEAVE;    // Mouse left the window
    const Uint32 WINDOWFOCUSGAINED = SDL_WINDOWEVENT_FOCUS_GAINED; // Window gained focus
    const Uint32 WINDOWFOCUSLOST = SDL_WINDOWEVENT_FOCUS_LOST;     // Window lost focus
    const Uint32 WINDOWCLOSE = SDL_WINDOWEVENT_CLOSE;     // Window was closed
    const Uint32 WINDOWTAKEFOCUS = SDL_WINDOWEVENT_TAKE_FOCUS;  // Window was offered focus (SDL backend >= 2.0.5)
    const Uint32 WINDOWHITTEST = SDL_WINDOWEVENT_HIT_TEST;      // Window has a special hit test (SDL backend >= 2.0.5)

}

#endif