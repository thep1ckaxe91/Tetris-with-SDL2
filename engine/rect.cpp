#include "rect.hpp"
#include "SDL2/SDL_rect.h"
sdlgame::rect::Rect::Rect()
{
    x = y = left = top = bottom = right = w = h = width = height = centerx = centery = 0;
}
template <class T>
sdlgame::rect::Rect::Rect(T _left, T _top, T _w, T _h)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    x = left = _left;
    y = top = _top;
    w = width = _w;
    h = height = _h;
    bottom = top + h;
    right = left + w;
    // size = sdlgame::math::Vector2(w, h);
    centerx = x + width / 2;
    centery = y + height / 2;
    // center = sdlgame::math::Vector2(centerx, centery);
    // topleft = sdlgame::math::Vector2(left, top);
    // bottomleft = sdlgame::math::Vector2(left, bottom);
    // bottomright = sdlgame::math::Vector2(right, bottom);
    // topright = sdlgame::math::Vector2(right, top);
    // midtop = sdlgame::math::Vector2(centerx, top);
    // midleft = sdlgame::math::Vector2(left, centery);
    // midbottom = sdlgame::math::Vector2(centerx, bottom);
    // midright = sdlgame::math::Vector2(right, centery);
}
template <class T>
sdlgame::rect::Rect::Rect(T _left, T _top, sdlgame::math::Vector2 _size)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    x = left = _left;
    y = top = _top;
    w = width = _size.x;
    h = height = _size.y;
    bottom = top + h;
    right = left + w;
    // size = _size;
    centerx = x + width / 2;
    centery = y + height / 2;
    // center = sdlgame::math::Vector2(centerx, centery);
    // topleft = sdlgame::math::Vector2(left, top);
    // bottomleft = sdlgame::math::Vector2(left, bottom);
    // bottomright = sdlgame::math::Vector2(right, bottom);
    // topright = sdlgame::math::Vector2(right, top);
    // midtop = sdlgame::math::Vector2(centerx, top);
    // midleft = sdlgame::math::Vector2(left, centery);
    // midbottom = sdlgame::math::Vector2(centerx, bottom);
    // midright = sdlgame::math::Vector2(right, centery);
}
template <class T>
sdlgame::rect::Rect::Rect(sdlgame::math::Vector2 pos, T _w, T _h)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    x = left = pos.x;
    y = top = pos.y;
    w = width = _w;
    h = height = _h;
    bottom = top + h;
    right = left + w;
    // size = sdlgame::math::Vector2(w, h);
    centerx = x + width / 2;
    centery = y + height / 2;
    // center = sdlgame::math::Vector2(centerx, centery);
    // topleft = sdlgame::math::Vector2(left, top);
    // bottomleft = sdlgame::math::Vector2(left, bottom);
    // bottomright = sdlgame::math::Vector2(right, bottom);
    // topright = sdlgame::math::Vector2(right, top);
    // midtop = sdlgame::math::Vector2(centerx, top);
    // midleft = sdlgame::math::Vector2(left, centery);
    // midbottom = sdlgame::math::Vector2(centerx, bottom);
    // midright = sdlgame::math::Vector2(right, centery);
}
sdlgame::rect::Rect::Rect(sdlgame::math::Vector2 pos, sdlgame::math::Vector2 size)
{
    x = left = pos.x;
    y = top = pos.y;
    w = width = size.x;
    h = height = size.y;
    bottom = top + h;
    right = left + w;
    // size = _size;
    centerx = x + width / 2;
    centery = y + height / 2;
    // center = sdlgame::math::Vector2(centerx, centery);
    // topleft = sdlgame::math::Vector2(left, top);
    // bottomleft = sdlgame::math::Vector2(left, bottom);
    // bottomright = sdlgame::math::Vector2(right, bottom);
    // topright = sdlgame::math::Vector2(right, top);
    // midtop = sdlgame::math::Vector2(centerx, top);
    // midleft = sdlgame::math::Vector2(left, centery);
    // midbottom = sdlgame::math::Vector2(centerx, bottom);
    // midright = sdlgame::math::Vector2(right, centery);
}
/**
 * @return a new rectangle that have been moved by given OFFSET x and y
 */
sdlgame::rect::Rect &sdlgame::rect::Rect::operator=(Rect oth)
{
    x = left = oth.getLeft();
    y = top = oth.getTop();
    w = width = oth.getWidth();
    h = height = oth.getHeight();
    bottom = top + h;
    right = left + w;
    // size = sdlgame::math::Vector2(w, h);
    centerx = x + width / 2;
    centery = y + height / 2;
    // center = sdlgame::math::Vector2(centerx, centery);
    // topleft = sdlgame::math::Vector2(left, top);
    // bottomleft = sdlgame::math::Vector2(left, bottom);
    // bottomright = sdlgame::math::Vector2(right, bottom);
    // topright = sdlgame::math::Vector2(right, top);
    // midtop = sdlgame::math::Vector2(centerx, top);
    // midleft = sdlgame::math::Vector2(left, centery);
    // midbottom = sdlgame::math::Vector2(centerx, bottom);
    // midright = sdlgame::math::Vector2(right, centery);
    return *this;
}
bool sdlgame::rect::Rect::operator==(const Rect &oth) const
{
    if (this == &oth)
        return true;
    return x == oth.getLeft() and y == oth.getTop() and w == oth.getWidth() and h == oth.getHeight();
}
SDL_FRect sdlgame::rect::Rect::to_SDL_FRect() const
{
    SDL_FRect res = {(float)x, (float)y, (float)w, (float)h};
    return res;
}
/**
 * TEST: Approved
 */
template <class T>
sdlgame::rect::Rect sdlgame::rect::Rect::move(T offset_x, T offset_y) const
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    Rect res(x, y, w, h);
    res.x = res.left += offset_x;
    res.y = res.top += offset_y;
    res.bottom = res.top + res.h;
    res.right = res.left + res.w;
    res.centerx = res.x + res.width / 2;
    res.centery = res.y + res.height / 2;
    return res;
}

/**
 *  instead of a new one, this just move the rect that called this function
 * TEST: Approved
 */
template <class T>
void sdlgame::rect::Rect::move_ip(T offset_x, T offset_y)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    *this = this->move(offset_x, offset_y);
}
/**
 * @return a new rectangle that have been moved by given OFFSET x and y
 */
sdlgame::rect::Rect sdlgame::rect::Rect::move(sdlgame::math::Vector2 offset) const
{
    return this->move(offset.x, offset.y);
}
/**
 *  instead of a new one, this just move the rect that called this function
 */
void sdlgame::rect::Rect::move_ip(sdlgame::math::Vector2 offset)
{
    *this = this->move(offset.x, offset.y);
}

/**
 * @return a new rectangle that changed the size to given OFFSET, the topleft of the rectangle is remain still
 */
template <class T>
sdlgame::rect::Rect sdlgame::rect::Rect::inflate(T offset_w, T offset_h) const
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    Rect res(x, y, w, h);
    // res.size += sdlgame::math::Vector2(offset_w, offset_h);
    res.w = res.width += offset_w;
    res.h = res.height += offset_h;
    res.bottom = res.top + res.h;
    res.right = res.left + res.w;
    res.centerx = res.x + res.width / 2;
    res.centery = res.y + res.height / 2;
    return res;
}
sdlgame::rect::Rect sdlgame::rect::Rect::inflate(sdlgame::math::Vector2 offset) const
{
    return this->inflate(offset.x, offset.y);
}
/**
 *  resize current rectangle with given offset, the topleft of the rectangle is remain still
 */
template <class T>
void sdlgame::rect::Rect::inflate_ip(T offset_w, T offset_h)
{
    *this = this->inflate(offset_w, offset_h);
}
void sdlgame::rect::Rect::inflate_ip(const sdlgame::math::Vector2 &offset)
{
    *this = this->inflate(offset.x, offset.y);
}

/**
 *  to update the current rectangle that call the function
 */
template <class T>
void sdlgame::rect::Rect::update(T _left, T _top, T _w, T _h)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    x = left = _left;
    y = top = _top;
    w = width = _w;
    h = height = _h;
    bottom = top + h;
    right = left + w;
    centerx = x + width / 2;
    centery = y + height / 2;
}
template <class T>
void sdlgame::rect::Rect::update(T _left, T _top, sdlgame::math::Vector2 _size)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    x = left = _left;
    y = top = _top;
    w = width = _size.x;
    h = height = _size.y;
    bottom = top + h;
    right = left + w;
    // size = _size;
    centerx = x + width / 2;
    centery = y + height / 2;
    // center = sdlgame::math::Vector2(centerx, centery);
    // topleft = sdlgame::math::Vector2(left, top);
    // bottomleft = sdlgame::math::Vector2(left, bottom);
    // bottomright = sdlgame::math::Vector2(right, bottom);
    // topright = sdlgame::math::Vector2(right, top);
    // midtop = sdlgame::math::Vector2(centerx, top);
    // midleft = sdlgame::math::Vector2(left, centery);
    // midbottom = sdlgame::math::Vector2(centerx, bottom);
    // midright = sdlgame::math::Vector2(right, centery);
}
template <class T>
void sdlgame::rect::Rect::update(sdlgame::math::Vector2 pos, T _w, T _h)
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    x = left = pos.x;
    y = top = pos.y;
    w = width = _w;
    h = height = _h;
    bottom = top + h;
    right = left + w;
    centerx = x + width / 2;
    centery = y + height / 2;
}
void sdlgame::rect::Rect::update(sdlgame::math::Vector2 pos, sdlgame::math::Vector2 _size)
{
    x = left = pos.x;
    y = top = pos.y;
    w = width = _size.x;
    h = height = _size.y;
    bottom = top + h;
    right = left + w;
    centerx = x + width / 2;
    centery = y + height / 2;
}
/**
 *  return a new rectangle that fit another rect but keep the aspect ratio of the caller
 * the position of the rect that return is the position of the caller
 */
sdlgame::rect::Rect sdlgame::rect::Rect::fit(const Rect oth) const
{
    Rect res = *this;
    res.setSize(sdlgame::math::Vector2(w, h) * (oth.getWidth() / res.getWidth()));
    return res;
}
/**
 * @return return true if the other rect is completely inside the caller
 */
bool sdlgame::rect::Rect::contains(const Rect oth) const
{
    return left <= oth.getLeft() && right >= oth.getRight() && top <= oth.getTop() && bottom >= oth.getBottom();
}

/**
 * TEST: approved
 */
template <class T>
bool sdlgame::rect::Rect::collidepoint(T _x, T _y) const
{
    static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
    return left < _x and _x < right and top < _y and _y < bottom;
}
/**
 * @return return whether the point in param is inside the caller or not
 */
bool sdlgame::rect::Rect::collidepoint(const sdlgame::math::Vector2 point)
{
    return left <= point.x and point.x <= right and top <= point.y and point.y <= bottom;
}
/**
 * @return return whether the caller collide with the other rect or not
 * TEST: Approved
 */
bool sdlgame::rect::Rect::colliderect(const Rect oth) const
{
    return !(left >= oth.getRight() || right <= oth.getLeft() || top >= oth.getBottom() || bottom <= oth.getTop());
}

// bool collideline(const Vector2 start, const Vector2 end)
// {
//     double t = ((end.x - start.x) * (y - start.y) - (end.y - start.y) * (x - start.x)) / ((end.x - start.x) * (y + h - start.y) - (end.y - start.y) * (x + w - start.x));
//     double u = ((x - start.x) * (end.y - start.y) - (y - start.y) * (end.x - start.x)) / ((end.x - start.x) * (y + h - start.y) - (end.y - start.y) * (x + w - start.x));
    

// }
/**
 * @return return whether the caller collide with any of the rect in the list
 */
bool sdlgame::rect::Rect::collidelist(std::vector<Rect> &rect_list) const
{
    for (Rect &rect : rect_list)
        if (this->colliderect(rect))
            return true;
    return false;
}

// Under is mostly get and set func
template <class T>
void sdlgame::rect::Rect::setWidth(T _w)
{
    this->inflate_ip(_w - w, 0);
}
template <class T>
void sdlgame::rect::Rect::setHeight(T _h)
{
    this->inflate_ip(0, _h - h);
}
template <class T>
void sdlgame::rect::Rect::setSize(T _w, T _h)
{
    this->inflate_ip(_w - w, _h - h);
}
void sdlgame::rect::Rect::setSize(const sdlgame::math::Vector2 &_size)
{
    this->inflate_ip(_size - sdlgame::math::Vector2(w, h));
}
template <class T>
void sdlgame::rect::Rect::setTop(T _y)
{
    // std::cout << "Moved the rect by " << T(_y - y) << " in y axis\n";
    this->move_ip(T(0), T(_y - y));
}
template <class T>
void sdlgame::rect::Rect::setLeft(T _x)
{
    // std::cout << "Moved the rect by " << T(_x - x) << " in x axis\n";
    this->move_ip(T(_x - x), T(0));
}
template <class T>
void sdlgame::rect::Rect::setRight(T _x)
{
    // std::cout << "Moved the rect by " << T(_x - x) << " in x axis\n";
    this->move_ip(T(_x - right), T(0));
}
template <class T>
void sdlgame::rect::Rect::setBottom(T _y)
{
    // std::cout << "Moved the rect by " << T(_y - y) << " in y axis\n";
    this->move_ip(T(0), T(_y - bottom));
}
template <class T>
void sdlgame::rect::Rect::setCenter(T _x, T _y)
{
    this->move_ip(_x - centerx, _y - centery);
}
void sdlgame::rect::Rect::setCenter(sdlgame::math::Vector2 pos)
{
    this->move_ip(pos.x - centerx, pos.y - centery);
}
template <class T>
void sdlgame::rect::Rect::setMidTop(T _x, T _y)
{
    this->move_ip(_x - centerx, _y - y);
}
void sdlgame::rect::Rect::setMidTop(const sdlgame::math::Vector2 &pos)
{
    this->move_ip(pos.x - centerx, pos.y - y);
}
template <class T>
void sdlgame::rect::Rect::setMidBottom(T _x, T _y)
{
    this->move_ip(_x - centerx, _y - bottom);
}
void sdlgame::rect::Rect::setMidBottom(const sdlgame::math::Vector2 &pos)
{
    this->move_ip(pos.x - centerx, pos.y - bottom);
}
template <class T>
void setMidLeft(T _x, T _y)
{
    this->move_ip(_x - x, _y - centery);
}
void sdlgame::rect::Rect::setMidLeft(const sdlgame::math::Vector2 &pos)
{
    this->move_ip(pos.x - x, pos.y - centery);
}
template <class T>
void sdlgame::rect::Rect::setMidRight(T _x, T _y)
{
    this->move_ip(_x - right, _y - centery);
}
void sdlgame::rect::Rect::setMidRight(const sdlgame::math::Vector2 &pos)
{
    this->move_ip(pos.x - right, pos.y - centery);
}
double sdlgame::rect::Rect::getWidth() const { return w; }
double sdlgame::rect::Rect::getHeight() const { return h; }
double sdlgame::rect::Rect::getTop() const { return y; }
double sdlgame::rect::Rect::getLeft() const { return x; }
double sdlgame::rect::Rect::getRight() const { return right; }
double sdlgame::rect::Rect::getBottom() const { return bottom; }
double sdlgame::rect::Rect::getCenterX() const { return centerx; }
double sdlgame::rect::Rect::getCenterY() const { return centery; }
sdlgame::math::Vector2 sdlgame::rect::Rect::getSize() const { return sdlgame::math::Vector2(w, h); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getCenter() const { return sdlgame::math::Vector2(centerx, centery); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getTopLeft() const { return sdlgame::math::Vector2(x, y); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getTopRight() const { return sdlgame::math::Vector2(top, right); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getBottomLeft() const { return sdlgame::math::Vector2(bottom, left); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getBottomRight() const { return sdlgame::math::Vector2(bottom, right); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getMidTop() const { return sdlgame::math::Vector2(centerx, top); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getMidLeft() const { return sdlgame::math::Vector2(left, centery); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getMidBottom() const { return sdlgame::math::Vector2(centerx, bottom); }
sdlgame::math::Vector2 sdlgame::rect::Rect::getMidRight() const { return sdlgame::math::Vector2(right, centery); }

/**
 *  return a SDL_Rect object from this rect
 */
SDL_Rect sdlgame::rect::Rect::to_SDL_Rect() const
{
    SDL_Rect res = {(int)x, (int)y, (int)w, (int)h};
    return res;
}
std::string sdlgame::rect::Rect::toString() const
{
    return "Rect<" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(w) + "," + std::to_string(h) + ">";
}