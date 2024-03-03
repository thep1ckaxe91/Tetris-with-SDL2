#ifndef SDLGAME_FONT_
#define SDLGAME_FONT_
#include "SDL2/SDL_ttf.h"

namespace sdlgame {
    namespace font
    {
        // std::string window_font_path = "C:/Windows/Fonts/";
        /**
         * @brief initialize font, after call this function, you should be able to use other function and class
         */
        
        void init();
        class Font
        {
        private:
            int height;
        public:
            TTF_Font *font;

            Font(std::string path, int size = 12);

            /**
             * @return a surface that only contain the text
             * @param antialias = 0 no antialiasing fastest
             *                  = 1 low antialiaing faster
             *                  = 2 high antialiasing slowest
             * the higher, the slower the render will be
             * @param wrap_length in pixel, once the text get over the wrap_length
             * it automatically endline, if it is default = 0,
             * then will only endline when use endline character
             *
             */
            sdlgame::surface::Surface render(
                const std::string text, int antialias, 
                sdlgame::color::Color color, uint32_t wrap_length = 0,
                sdlgame::color::Color background = sdlgame::color::Color(0, 0, 0, 0)
            );
        };
    }
}
#endif