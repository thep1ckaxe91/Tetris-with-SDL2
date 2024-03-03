#include "display.hpp"
#include <stdio.h>
#include "SDL2/SDL_hints.h"
#include "SDL2/SDL_image.h"
#include <iostream>
SDL_Window *window=nullptr;
SDL_Renderer *renderer=nullptr;
sdlgame::surface::Surface win_surf;
/**
 * Setup a window surface for use
 * @param width the resolution width of the window
 * @param height the resolution height of the window
 * @param flags flags for the window, look for Window_Flags enum for more
 * @return a surface that represent the window, what action affect this window will affect what display on screen
 */
sdlgame::surface::Surface &sdlgame::display::set_mode(int width = 0, int height = 0, Uint32 flags = 0)
{
    if (width == 0 or height == 0)
    {
        SDL_DisplayMode DM;
        SDL_GetDesktopDisplayMode(0, &DM);
        width = DM.w;
        height = DM.h;
    }
    window = SDL_CreateWindow("sdlgame Custom Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (window == nullptr)
    {
        printf("Failed to create a window object\nErr: %s\n", SDL_GetError());
        exit(0);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        printf("Failed to create a renderer\nErr: %s\n", SDL_GetError());
        exit(0);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    SDL_RenderSetLogicalSize(renderer, width, height);
    // printf("Initialize window and renderer: %p %p\n",window,renderer);
    win_surf.texture = null; // THIS IS INTENDED!
    win_surf.size = sdlgame::math::Vector2(width, height);
    return win_surf;
}
/**
 * Maximize the active window
 */
void maximize()
{
    SDL_MaximizeWindow(window);
}
/**
 * Minimize the active window
 */
void minimize()
{
    SDL_MinimizeWindow(window);
}
void fullscreen()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
}
void fullscreen_desktop()
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}
sdlgame::surface::Surface &get_surf()
{
    return win_surf;
}

double get_width()
{
    if(win_surf.getWidth()==0){
        printf("Display not yet set mode\n");
        exit(0);
    }
    return win_surf.getWidth();
}
double get_height()
{
    if(win_surf.getHeight()==0){
        printf("Display not yet set mode\n");
        exit(0);
    }
    return win_surf.getHeight();
}
/**
 *  if set to true, the mouse will be confine to the window
 * this function get or set the state of mouse being confine or not
 *
 */
bool grab(int enable = -1)
{
    if (enable == -1)
        return SDL_GetWindowGrab(window);
    SDL_SetWindowGrab(window, (enable ? SDL_TRUE : SDL_FALSE));
    return enable;
}

void set_icon(const char *icon_path)
{
    SDL_Surface *icon = IMG_Load(icon_path);
    SDL_SetWindowIcon(window, icon);
}

/**
 *  get and set the borderless state of the active window;
 */
bool borderless(int enable = -1)
{
    if (enable == -1)
        return (SDL_GetWindowFlags(window) & SDL_WINDOW_BORDERLESS);
    SDL_SetWindowBordered(window, (enable ? SDL_FALSE : SDL_TRUE));
    return (SDL_GetWindowFlags(window) & SDL_WINDOW_BORDERLESS) > 0;
}
void set_caption(const char *title)
{
    SDL_SetWindowTitle(window, title);
}
SDL_Window *get_window()
{
    return window;
}
SDL_Renderer *get_renderer()
{
    return renderer;
}
void quit()
{
    if (window)
        SDL_DestroyWindow(window);
    if (renderer)
        SDL_DestroyRenderer(renderer);
}
void flip()
{
    if (SDL_GetRenderTarget(renderer))
        SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderPresent(renderer);
}