#ifndef SDLGAME_IMAGE_
#define SDLGAME_IMAGE_
#include "SDL2/SDL_image.h"
namespace std{class string;}
namespace sdlgame{
    namespace surface{class Surface;}
    namespace image
    {
        /**
         * Currently only support JPG and PNG type
         */
        void init();
        /**
         * load an image from file path, require you to create the window object first
        */
        sdlgame::surface::Surface load(std::string path);
    }
}
#endif