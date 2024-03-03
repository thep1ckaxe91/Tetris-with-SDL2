#ifndef SDLGAME_DISPLAY_
#define SDLGAME_DISPLAY_
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"
namespace sdlgame
{
    namespace surface{class Surface;}
    typedef enum
    {
        FULLSCREEN = SDL_WINDOW_FULLSCREEN,
        NO_FRAME = SDL_WINDOW_BORDERLESS,
        RESIZABLE = SDL_WINDOW_RESIZABLE,
        HIDDEN = SDL_WINDOW_HIDDEN,
        SKIP_TASK_BAR = SDL_WINDOW_SKIP_TASKBAR,
        POPUP_MENU = SDL_WINDOW_POPUP_MENU,
        ALWAYS_ON_TOP = SDL_WINDOW_ALWAYS_ON_TOP,
        MAXIMIZED = SDL_WINDOW_MAXIMIZED,
        MINIMIZED = SDL_WINDOW_MINIMIZED,
    } Window_Flag;
    namespace display
    {
        SDL_Window *window;
        SDL_Renderer *renderer;
        sdlgame::surface::Surface win_surf;
        bool isInit = false;

        /**
         * Setup a window surface for use
         * @param width the resolution width of the window
         * @param height the resolution height of the window
         * @param flags flags for the window, look for Window_Flags enum for more
         * @return a surface that represent the window, what action affect this window will affect what display on screen
         */
        sdlgame::surface::Surface &set_mode(int width = 0, int height = 0, Uint32 flags = 0);
        /**
         * Maximize the active window
         */
        void maximize();
        /**
         * Minimize the active window
         */
        void minimize();
        void fullscreen();
        void fullscreen_desktop();
        sdlgame::surface::Surface &get_surf();

        double get_width();
        double get_height();
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
    }
}


#endif