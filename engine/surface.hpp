#ifndef SDLGAME_SURFACE_
#define SDLGAME_SURFACE_
#include "SDL2/SDL.h"
namespace sdlgame
{
    namespace surface
    {
        /**
         * @brief since the problem mostly related to the heavy draw and surface manage in pygame
         * this module is mostly focus optimiszing the surface class, the texture pointer should be null if the surface is represent window
         * after set_mode is called
         */
        class Surface
        {
        public:
            sdlgame::math::Vector2 size;
            SDL_Texture *texture = NULL;
            Uint32 flags = 0;
            Surface()
            {
                flags = 0;
                texture = NULL;
            }

            Surface(int width, int height, Uint32 _flags = 0)
            {
                flags = _flags;
                if (!(texture = SDL_CreateTexture(sdlgame::display::renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, width, height)))
                {
                    printf("Failed to create texture\nErr: %s\n", SDL_GetError());
                    exit(0);
                }
                size = sdlgame::math::Vector2(width, height);
                if(SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND));
                SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                SDL_RenderClear(sdlgame::display::renderer);
                SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
            }

            Surface(const Surface &oth)
            {
                int w, h;
                SDL_QueryTexture(oth.texture, NULL, NULL, &w, &h);
                texture = SDL_CreateTexture(sdlgame::display::renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
                SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
                SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                SDL_RenderClear(sdlgame::display::renderer);
                SDL_RenderCopy(sdlgame::display::renderer, oth.texture, NULL, NULL);
                SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
                size = sdlgame::math::Vector2(w, h);
            }

            Surface(SDL_Texture *oth)
            {
                int w, h;
                SDL_QueryTexture(oth, NULL, NULL, &w, &h);
                texture = SDL_CreateTexture(sdlgame::display::renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
                SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
                SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                SDL_RenderClear(sdlgame::display::renderer);
                SDL_RenderCopy(sdlgame::display::renderer, oth, NULL, NULL);
                SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
                size = sdlgame::math::Vector2(w, h);
            }

            Surface(SDL_Surface *surf)
            {
                texture = SDL_CreateTextureFromSurface(sdlgame::display::renderer, surf);
                // printf("tex: %p | surf: %p\n",texture,surf);
                if (texture == NULL)
                {
                    printf("Failed to create texture form surface\nErr:%s\n", SDL_GetError());
                    exit(0);
                }
                size = sdlgame::math::Vector2(surf->w, surf->h);
            }
            Surface &operator=(const Surface &other)
            {
                if (this->texture != other.texture and this != &other)
                {
                    if(texture!=NULL) SDL_DestroyTexture(texture);
                    flags = other.flags;
                    int w, h;
                    SDL_QueryTexture(other.texture, NULL, NULL, &w, &h);
                    texture = SDL_CreateTexture(sdlgame::display::renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
                    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
                    SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                    SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                    SDL_RenderClear(sdlgame::display::renderer);
                    SDL_RenderCopy(sdlgame::display::renderer, other.texture, NULL, NULL);
                    SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
                    size = other.size;
                }
                return *this;
            }
            /**
             * Return a copy of the surface rect
             */
            sdlgame::rect::Rect getRect() const
            {
                return sdlgame::rect::Rect(0.0, 0.0, size.x, size.y);
            }
            /**
             * Blit a surface onto this surface with position and size, leave size be -1,-1 will be its original size
             * the surface or image will stretch or shrink acoording to the size
             */
            void blit(const Surface &source, sdlgame::math::Vector2 pos, sdlgame::math::Vector2 size = sdlgame::math::Vector2(-1, -1), sdlgame::rect::Rect area = sdlgame::rect::Rect())
            {
                if (area == sdlgame::rect::Rect())
                {
                    area = sdlgame::rect::Rect(0.0, 0.0, source.getWidth(), source.getHeight());
                }
                sdlgame::rect::Rect destrect = sdlgame::rect::Rect(
                    pos.x, pos.y,
                    (size.x < 0 ? source.getWidth() : size.x), (size.y < 0 ? source.getHeight() : size.y));
                if (SDL_SetRenderTarget(sdlgame::display::renderer, texture))
                {
                    printf("Failed to set target: %s\n", SDL_GetError());
                }

                SDL_Rect srcrect = area.to_SDL_Rect();
                SDL_FRect dstrect = destrect.to_SDL_FRect();
                // printf("src: %p ren: %p \n",source.texture, sdlgame::display::renderer);
                if (SDL_RenderCopyF(sdlgame::display::renderer, source.texture, &srcrect, &dstrect))
                {
                    printf("Error copy texture onto another\n%s\n", SDL_GetError());
                    exit(0);
                }
                if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
                {
                    printf("Failed to set target: %s\n", SDL_GetError());
                }
            }
            void fill(sdlgame::color::Color color)
            {
                if (SDL_SetRenderTarget(sdlgame::display::renderer, texture))
                {
                    printf("Failed to set target: %s\n", SDL_GetError());
                }

                if (SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a))
                {
                    printf("Failed to set draw color\nErr:%s\n", SDL_GetError());
                    exit(0);
                }
                if (SDL_RenderClear(sdlgame::display::renderer))
                {
                    printf("Failed to clear the render target\nErr:%s\n", SDL_GetError());
                    exit(0);
                }
                if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
                {
                    printf("Failed to set target: %s\n", SDL_GetError());
                }
            }
            sdlgame::math::Vector2 get_size() const
            {
                return size;
            }
            double getWidth() const
            {
                return size.x;
            }
            double getHeight() const
            {
                return size.y;
            }
            ~Surface()
            {
                if (texture != NULL){
                    SDL_DestroyTexture(texture);
                    texture = NULL;
                }
            }
        };
    }
}

#endif