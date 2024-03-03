#ifndef SDLGAME_RECT_
#define SDLGAME_RECT_

namespace sdlgame
{
    /// @brief namespace for rect usage
    namespace rect
    {
        /**
         *  this is a class represent a Rectangle in SDL2, the coordination
         * in sdl2 is x axis points to the right and y axis points downward
         * it's a little unintuitive, but you'll sure have the hang of it and why it should be like that
         *
         * Also for pygame user, there's no = and the rect do it for you, you have to use get and set method,
         * otherwise, ready for immense amount of bug.
         *
         * Though width and height can be negative, it's mostly illegal Rect for most opration, so just dont
         *
         * Most function that have here also have in pygame.Rect, but just some that are most used
         *
         * 
         */
        class Rect
        {

        private:
            double x, y, left, top, bottom, right;
            double w, h, width, height;
            double centerx, centery;
            // sdlgame::math::Vector2 center, topleft, bottomleft, topright, bottomright, midtop, midleft, midbottom, midright;
            // sdlgame::math::Vector2 size;
            double epsilon = 1e-6;

        public:
            Rect()
            {
                x = y = left = top = bottom = right = w = h = width = height = centerx = centery = 0;
            }
            template <class T>
            Rect(T _left, T _top, T _w, T _h)
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
            Rect(T _left, T _top, sdlgame::math::Vector2 _size)
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
            Rect(sdlgame::math::Vector2 pos, T _w, T _h)
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
            Rect(sdlgame::math::Vector2 pos, sdlgame::math::Vector2 size)
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
            Rect &operator=(Rect oth)
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
            bool operator==(const Rect &oth) const
            {
                if (this == &oth)
                    return true;
                return abs(x - oth.getLeft()) <= epsilon and abs(y - oth.getTop()) <= epsilon and abs(w - oth.getWidth()) <= epsilon and abs(h - oth.getHeight()) <= epsilon;
            }
            SDL_FRect to_SDL_FRect() const
            {
                SDL_FRect res = {(float)x, (float)y, (float)w, (float)h};
                return res;
            }
            /**
             * TEST: Approved
             */
            template <class T>
            Rect move(T offset_x, T offset_y) const
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
            void move_ip(T offset_x, T offset_y)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                *this = this->move(offset_x, offset_y);
            }
            /**
             * @return a new rectangle that have been moved by given OFFSET x and y
             */
            Rect move(sdlgame::math::Vector2 offset) const
            {
                return this->move(offset.x, offset.y);
            }
            /**
             *  instead of a new one, this just move the rect that called this function
             */
            void move_ip(sdlgame::math::Vector2 offset)
            {
                *this = this->move(offset.x, offset.y);
            }

            /**
             * @return a new rectangle that changed the size to given OFFSET, the topleft of the rectangle is remain still
             */
            template <class T>
            Rect inflate(T offset_w, T offset_h) const
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
                // res.center = sdlgame::math::Vector2(res.centerx, res.centery);
                // res.topleft = sdlgame::math::Vector2(res.left, res.top);
                // res.bottomleft = sdlgame::math::Vector2(res.left, res.bottom);
                // res.bottomright = sdlgame::math::Vector2(res.right, res.bottom);
                // res.topright = sdlgame::math::Vector2(res.right, res.top);
                // res.midtop = sdlgame::math::Vector2(res.centerx, res.top);
                // res.midleft = sdlgame::math::Vector2(res.left, res.centery);
                // res.midbottom = sdlgame::math::Vector2(res.centerx, res.bottom);
                // res.midright = sdlgame::math::Vector2(res.right, res.centery);
                return res;
            }
            Rect inflate(sdlgame::math::Vector2 offset) const
            {
                return this->inflate(offset.x, offset.y);
            }
            /**
             *  resize current rectangle with given offset, the topleft of the rectangle is remain still
             */
            template <class T>
            void inflate_ip(T offset_w, T offset_h)
            {
                *this = this->inflate(offset_w, offset_h);
            }
            void inflate_ip(const sdlgame::math::Vector2 &offset)
            {
                *this = this->inflate(offset.x, offset.y);
            }

            /**
             *  to update the current rectangle that call the function
             */
            template <class T>
            void update(T _left, T _top, T _w, T _h)
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
            void update(T _left, T _top, sdlgame::math::Vector2 _size)
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
            void update(sdlgame::math::Vector2 pos, T _w, T _h)
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
            void update(sdlgame::math::Vector2 pos, sdlgame::math::Vector2 _size)
            {
                x = left = pos.x;
                y = top = pos.y;
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
            /**
             *  return a new rectangle that fit another rect but keep the aspect ratio of the caller
             * the position of the rect that return is the position of the caller
             */
            Rect fit(const Rect oth) const
            {
                Rect res = *this;
                res.setSize(sdlgame::math::Vector2(w, h) * (oth.getWidth() / res.getWidth()));
                return res;
            }
            /**
             * @return return true if the other rect is completely inside the caller
             */
            bool contains(const Rect oth) const
            {
                return left <= oth.getLeft() && right >= oth.getRight() && top <= oth.getTop() && bottom >= oth.getBottom();
            }

            /**
             * TEST: approved
             */
            template <class T>
            bool collidepoint(T _x, T _y) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                return left < _x and _x < right and top < _y and _y < bottom;
            }
            /**
             * @return return whether the point in param is inside the caller or not
             */
            bool collidepoint(const sdlgame::math::Vector2 point)
            {
                return left <= point.x and point.x <= right and top <= point.y and point.y <= bottom;
            }
            /**
             * @return return whether the caller collide with the other rect or not
             * TEST: Approved
             */
            bool colliderect(const Rect oth) const
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
            bool collidelist(std::vector<Rect> &rect_list) const
            {
                for (Rect &rect : rect_list)
                    if (this->colliderect(rect))
                        return true;
                return false;
            }

            // Under is mostly get and set func
            template <class T>
            void setWidth(T _w)
            {
                this->inflate_ip(_w - w, 0);
            }
            template <class T>
            void setHeight(T _h)
            {
                this->inflate_ip(0, _h - h);
            }
            template <class T>
            void setSize(T _w, T _h)
            {
                this->inflate_ip(_w - w, _h - h);
            }
            void setSize(const sdlgame::math::Vector2 &_size)
            {
                this->inflate_ip(_size - sdlgame::math::Vector2(w, h));
            }
            template <class T>
            void setTop(T _y)
            {
                // std::cout << "Moved the rect by " << T(_y - y) << " in y axis\n";
                this->move_ip(T(0), T(_y - y));
            }
            template <class T>
            void setLeft(T _x)
            {
                // std::cout << "Moved the rect by " << T(_x - x) << " in x axis\n";
                this->move_ip(T(_x - x), T(0));
            }
            template <class T>
            void setRight(T _x)
            {
                // std::cout << "Moved the rect by " << T(_x - x) << " in x axis\n";
                this->move_ip(T(_x - right), T(0));
            }
            template <class T>
            void setBottom(T _y)
            {
                // std::cout << "Moved the rect by " << T(_y - y) << " in y axis\n";
                this->move_ip(T(0), T(_y - bottom));
            }
            template <class T>
            void setCenter(T _x, T _y)
            {
                this->move_ip(_x - centerx, _y - centery);
            }
            void setCenter(sdlgame::math::Vector2 pos)
            {
                this->move_ip(pos.x - centerx, pos.y - centery);
            }
            template <class T>
            void setMidTop(T _x, T _y)
            {
                this->move_ip(_x - centerx, _y - y);
            }
            void setMidTop(const sdlgame::math::Vector2 &pos)
            {
                this->move_ip(pos.x - centerx, pos.y - y);
            }
            template <class T>
            void setMidBottom(T _x, T _y)
            {
                this->move_ip(_x - centerx, _y - bottom);
            }
            void setMidBottom(const sdlgame::math::Vector2 &pos)
            {
                this->move_ip(pos.x - centerx, pos.y - bottom);
            }
            template <class T>
            void setMidLeft(T _x, T _y)
            {
                this->move_ip(_x - x, _y - centery);
            }
            void setMidLeft(const sdlgame::math::Vector2 &pos)
            {
                this->move_ip(pos.x - x, pos.y - centery);
            }
            template <class T>
            void setMidRight(T _x, T _y)
            {
                this->move_ip(_x - right, _y - centery);
            }
            void setMidRight(const sdlgame::math::Vector2 &pos)
            {
                this->move_ip(pos.x - right, pos.y - centery);
            }
            double getWidth() const { return w; }
            double getHeight() const { return h; }
            double getTop() const { return y; }
            double getLeft() const { return x; }
            double getRight() const { return right; }
            double getBottom() const { return bottom; }
            double getCenterX() const { return centerx; }
            double getCenterY() const { return centery; }
            sdlgame::math::Vector2 getSize() const { return sdlgame::math::Vector2(w, h); }
            sdlgame::math::Vector2 getCenter() const { return sdlgame::math::Vector2(centerx, centery); }
            sdlgame::math::Vector2 getTopLeft() const { return sdlgame::math::Vector2(x, y); }
            sdlgame::math::Vector2 getTopRight() const { return sdlgame::math::Vector2(top, right); }
            sdlgame::math::Vector2 getBottomLeft() const { return sdlgame::math::Vector2(bottom, left); }
            sdlgame::math::Vector2 getBottomRight() const { return sdlgame::math::Vector2(bottom, right); }
            sdlgame::math::Vector2 getMidTop() const { return sdlgame::math::Vector2(centerx, top); }
            sdlgame::math::Vector2 getMidLeft() const { return sdlgame::math::Vector2(left, centery); }
            sdlgame::math::Vector2 getMidBottom() const { return sdlgame::math::Vector2(centerx, bottom); }
            sdlgame::math::Vector2 getMidRight() const { return sdlgame::math::Vector2(right, centery); }

            /**
             *  return a SDL_Rect object from this rect
             */
            SDL_Rect to_SDL_Rect() const
            {
                SDL_Rect res = {(int)x, (int)y, (int)w, (int)h};
                return res;
            }
            std::string toString() const
            {
                return "Rect<" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(w) + "," + std::to_string(h) + ">";
            }
        };
    }
}


#endif