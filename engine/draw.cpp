#include "draw.hpp"
#include "surface.hpp"
#include "color.hpp"
#include "stdio.h"
#include "rect.hpp"



void rect(sdlgame::surface::Surface &surface, sdlgame::color::Color color, sdlgame::rect::Rect rect, int width = 0)
{
    // std::cout << surface.texture << " color: "<<color.toString() << " rect: "<<rect.toString()<<std::endl;
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (width == 0)
    {
        SDL_FRect tmp = rect.to_SDL_FRect();
        if (SDL_RenderFillRectF(sdlgame::display::renderer, &tmp))
        {
            printf("Error filling a rectangle: %s\n", SDL_GetError());
            exit(0);
        }
    }
    else if (width > 0)
    {
        SDL_FRect top = rect.inflate(0.0, width - rect.getHeight()).to_SDL_FRect();
        SDL_FRect left = rect.inflate(width - rect.getWidth(), 0.0).to_SDL_FRect();
        SDL_FRect bottom = rect.inflate(0.0, width - rect.getHeight()).move(0.0, rect.getHeight() - width).to_SDL_FRect();
        SDL_FRect right = rect.inflate(width - rect.getWidth(), 0.0).move(rect.getWidth() - width, 0.0).to_SDL_FRect();
        if (SDL_RenderFillRectF(sdlgame::display::renderer, &top) or
            SDL_RenderFillRectF(sdlgame::display::renderer, &left) or
            SDL_RenderFillRectF(sdlgame::display::renderer, &bottom) or
            SDL_RenderFillRectF(sdlgame::display::renderer, &right))
        {
            printf("Error drawing a rectangle: %s\n", SDL_GetError());
            exit(0);
        }
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}

template <class T>
void line(sdlgame::surface::Surface &surface, sdlgame::color::Color color, T x1, T y1, T x2, T y2)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (SDL_RenderDrawLineF(sdlgame::display::renderer, x1, y1, x2, y2))
    {
        printf("Failed to draw a line: %s\n", SDL_GetError());
        exit(0);
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
void line(sdlgame::surface::Surface &surface, sdlgame::color::Color color, sdlgame::math::Vector2 start, sdlgame::math::Vector2 end)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (SDL_RenderDrawLineF(sdlgame::display::renderer, start.x, start.y, end.x, end.y))
    {
        printf("Failed to draw a line: %s\n", SDL_GetError());
        exit(0);
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
void circle(sdlgame::surface::Surface &surface, sdlgame::color::Color color, int centerX, int centerY, int radius, int width = 0)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (width != 0)
    {
        int quality = 90;
        sdlgame::math::Vector2 rad(radius, 0);
        for (int i = 0; i <= quality; i++)
        {
            sdlgame::math::Vector2 next = rad.rotate(360 / quality);
            SDL_RenderDrawLineF(sdlgame::display::renderer, centerX + rad.x, centerY + rad.y, centerX + next.x, centerY + next.y);
            rad = next;
        }
    }
    else
    {
        double x;
        for (int i = -radius; i <= radius; i++)
        {
            x = radius * std::cos(std::asin(i * 1.0 / radius));
            SDL_RenderDrawLineF(
                sdlgame::display::renderer,
                x + centerX, i + centerY,
                centerX - x, i + centerY);
        }
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
void polygon(sdlgame::surface::Surface &surface, sdlgame::color::Color color, std::vector<std::pair<int, int>> points)
{
    if (points.size() < 3)
        throw std::invalid_argument("can't draw polygon with only 2 vertices or less");
    for (int i = 0; i < int(points.size()) - 1; i++)
    {
        sdlgame::draw::line(surface, color, points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }
    sdlgame::draw::line(surface, color, points[0].first, points[0].second, points[points.size() - 1].first, points[points.size() - 1].second);
}

template <class T>
void point(sdlgame::surface::Surface &surface, sdlgame::color::Color color, T x, T y)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (SDL_RenderDrawPointF(sdlgame::display::renderer, x, y))
    {
        printf("Failed to draw a point: %s\n", SDL_GetError());
        exit(0);
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
}namespace draw
{
/**
 * width determine how far the border will expand to the INSIDE
 */
void rect(sdlgame::surface::Surface &surface, sdlgame::color::Color color, sdlgame::rect::Rect rect, int width = 0)
{
    // std::cout << surface.texture << " color: "<<color.toString() << " rect: "<<rect.toString()<<std::endl;
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (width == 0)
    {
        SDL_FRect tmp = rect.to_SDL_FRect();
        if (SDL_RenderFillRectF(sdlgame::display::renderer, &tmp))
        {
            printf("Error filling a rectangle: %s\n", SDL_GetError());
            exit(0);
        }
    }
    else if (width > 0)
    {
        SDL_FRect top = rect.inflate(0.0, width - rect.getHeight()).to_SDL_FRect();
        SDL_FRect left = rect.inflate(width - rect.getWidth(), 0.0).to_SDL_FRect();
        SDL_FRect bottom = rect.inflate(0.0, width - rect.getHeight()).move(0.0, rect.getHeight() - width).to_SDL_FRect();
        SDL_FRect right = rect.inflate(width - rect.getWidth(), 0.0).move(rect.getWidth() - width, 0.0).to_SDL_FRect();
        if (SDL_RenderFillRectF(sdlgame::display::renderer, &top) or
            SDL_RenderFillRectF(sdlgame::display::renderer, &left) or
            SDL_RenderFillRectF(sdlgame::display::renderer, &bottom) or
            SDL_RenderFillRectF(sdlgame::display::renderer, &right))
        {
            printf("Error drawing a rectangle: %s\n", SDL_GetError());
            exit(0);
        }
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}

template <class T>
void line(sdlgame::surface::Surface &surface, sdlgame::color::Color color, T x1, T y1, T x2, T y2)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (SDL_RenderDrawLineF(sdlgame::display::renderer, x1, y1, x2, y2))
    {
        printf("Failed to draw a line: %s\n", SDL_GetError());
        exit(0);
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
void line(sdlgame::surface::Surface &surface, sdlgame::color::Color color, sdlgame::math::Vector2 start, sdlgame::math::Vector2 end)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (SDL_RenderDrawLineF(sdlgame::display::renderer, start.x, start.y, end.x, end.y))
    {
        printf("Failed to draw a line: %s\n", SDL_GetError());
        exit(0);
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
void circle(sdlgame::surface::Surface &surface, sdlgame::color::Color color, int centerX, int centerY, int radius, int width = 0)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (width != 0)
    {
        int quality = 90;
        sdlgame::math::Vector2 rad(radius, 0);
        for (int i = 0; i <= quality; i++)
        {
            sdlgame::math::Vector2 next = rad.rotate(360 / quality);
            SDL_RenderDrawLineF(sdlgame::display::renderer, centerX + rad.x, centerY + rad.y, centerX + next.x, centerY + next.y);
            rad = next;
        }
    }
    else
    {
        double x;
        for (int i = -radius; i <= radius; i++)
        {
            x = radius * std::cos(std::asin(i * 1.0 / radius));
            SDL_RenderDrawLineF(
                sdlgame::display::renderer,
                x + centerX, i + centerY,
                centerX - x, i + centerY);
        }
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}
void polygon(sdlgame::surface::Surface &surface, sdlgame::color::Color color, std::vector<std::pair<int, int>> points)
{
    if (points.size() < 3)
        throw std::invalid_argument("can't draw polygon with only 2 vertices or less");
    for (int i = 0; i < int(points.size()) - 1; i++)
    {
        sdlgame::draw::line(surface, color, points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
    }
    sdlgame::draw::line(surface, color, points[0].first, points[0].second, points[points.size() - 1].first, points[points.size() - 1].second);
}

template <class T>
void point(sdlgame::surface::Surface &surface, sdlgame::color::Color color, T x, T y)
{
    if (SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
    SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a);

    if (SDL_RenderDrawPointF(sdlgame::display::renderer, x, y))
    {
        printf("Failed to draw a point: %s\n", SDL_GetError());
        exit(0);
    }
    if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
    {
        printf("Failed to set target: %s\n", SDL_GetError());
    }
}