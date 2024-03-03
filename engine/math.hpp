#ifndef SDLGAME_MATH_
#define SDLGAME_MATH_
#include <cmath>
namespace sdlgame {
    /**
     * namespace for most use math functionality in game dev
     */
    namespace math
    {
        double degree_to_radian(double deg)
        {
            return deg * M_PI / 180.0;
        }
        double radian_to_degree(double rad)
        {
            return rad * 180.0 / M_PI;
        }

        /**
         *  a class for 2D vector, also can represent a point on a 2d surface
         * since the simplicity of 2d vector, we dont need get and set function
         *
         * also for some dumb reason, you can do Vector2 * number, but not number * Vector2
         *
         */
        class Vector2
        {
        public:
            double x, y;
            double epsilon = 1e-6;
            Vector2()
            {
                x = 0;
                y = 0;
            }
            Vector2(const SDL_Point &p)
            {
                x = (double)p.x;
                y = (double)p.y;
            }
            Vector2(const Vector2 &oth)
            {
                x = oth.x;
                y = oth.y;
            }
            template <class T>
            Vector2(T _x, T _y)
            {
                x = _x;
                y = _y;
            }
            Vector2 &operator=(const Vector2 &oth)
            {
                if (this != &oth)
                {
                    x = oth.x;
                    y = oth.y;
                }
                return *this;
            }
            sdlgame::math::Vector2 &operator+=(const sdlgame::math::Vector2 &oth)
            {
                if (this != &oth)
                {
                    x += oth.x;
                    y += oth.y;
                }
                return *this;
            }
            sdlgame::math::Vector2 &operator-=(const sdlgame::math::Vector2 &oth)
            {
                if (this != &oth)
                {
                    x -= oth.x;
                    y -= oth.y;
                }
                return *this;
            }
            template <class T>
            sdlgame::math::Vector2 &operator*=(const T &scalar)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                x *= scalar;
                y *= scalar;
                return *this;
            }
            sdlgame::math::Vector2 operator+(const sdlgame::math::Vector2 &oth) const
            {
                return sdlgame::math::Vector2(x + oth.x, y + oth.y);
            }
            sdlgame::math::Vector2 operator-() const
            {
                return sdlgame::math::Vector2(-x, -y);
            }
            sdlgame::math::Vector2 operator-(const sdlgame::math::Vector2 &oth) const
            {
                return sdlgame::math::Vector2(x - oth.x, y - oth.y);
            }
            template <class T>
            sdlgame::math::Vector2 operator*(const T &scalar) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                return sdlgame::math::Vector2(scalar * x, scalar * y);
            }

            bool operator==(const sdlgame::math::Vector2 &oth) const
            {
                return abs(x - oth.x) <= epsilon and abs(y - oth.y) <= epsilon;
            }
            /**
             * @return length of the vector
             */
            double magnitude() const
            {
                return sqrt(x * x + y * y);
            }
            /**
             * @return the squared value of the length of the vector
             */
            double sqr_magnitude() const
            {
                return x * x + y * y;
            }
            /**
             * @return a normalized vector (a vector with length 1 unit) that have the same direction with the original
             */
            sdlgame::math::Vector2 normalize() const
            {
                return sdlgame::math::Vector2(x / this->magnitude(), y / this->magnitude());
            }
            /**
             *  normalize the vector
             */
            void normalize_ip()
            {
                x /= this->magnitude();
                y /= this->magnitude();
            }
            /**
             * @return dot product between 2 vector
             */
            double dot(const sdlgame::math::Vector2 &oth) const
            {
                return x * oth.x + y * oth.y;
            }
            /**
             * @return angle in degree to another vector in range [0,180] degrees, which is the smallest of 2 angle
             * */
            double angle_to(const sdlgame::math::Vector2 &oth) const
            {
                return acos(this->dot(oth) / (this->magnitude() * oth.magnitude())) * 180.0 / M_PI;
            }

            /**
             * @return a vector that rotated deg degrees counter clockwise
             * */
            sdlgame::math::Vector2 rotate(double deg) const
            {
                double angleInRadians = degree_to_radian(deg);
                return sdlgame::math::Vector2(x * cos(angleInRadians) - y * sin(angleInRadians), x * sin(angleInRadians) + y * cos(angleInRadians));
            }
            /**
             *  make the vector rotate deg degrees counter-clockwise
             */
            void rotate_ip(double deg)
            {
                double _x = x, _y = y, angleInRadians = degree_to_radian(deg);
                x = _x * cos(angleInRadians) - _y * sin(angleInRadians);
                y = x * sin(angleInRadians) + y * cos(angleInRadians);
            }
            /**
             * @return distance between 2 point
             */
            double distance_to(const sdlgame::math::Vector2 &oth) const
            {
                return sqrt((x - oth.x) * (x - oth.x) + (y - oth.y) * (y - oth.y));
            }
            /**
             * @return the vector that is the reflection of the current vector to a normal vector
             */
            sdlgame::math::Vector2 reflect(const sdlgame::math::Vector2 &normal) const
            {
                double dotProduct = this->dot(normal);
                return (*this) - normal * 2 * (this->dot(normal));
            }
            /**
             * reflect the vector through a normal vector
             */
            void reflect_ip(const sdlgame::math::Vector2 &normal)
            {
                *this = this->reflect(normal);
            }
            /**
             * @return a projected vector from this vector to a normal vector
             */
            sdlgame::math::Vector2 project(const sdlgame::math::Vector2 &normal) const
            {
                return normal * (this->dot(normal) / (normal.sqr_magnitude()));
            }
            /**
             * project the vector onto a normal vector
             */
            void project_ip(const sdlgame::math::Vector2 &normal)
            {
                *this = this->project(normal);
            }
            std::string toString() const
            {
                return "Vector2<" + std::to_string(x) + " , " + std::to_string(y) + ">";
            }
        };

        template <class T>
        sdlgame::math::Vector2 operator*(const T &scalar, const sdlgame::math::Vector2 &v)
        {
            static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
            return sdlgame::math::Vector2(scalar * v.x, scalar * v.y);
        }
    }
}

#endif