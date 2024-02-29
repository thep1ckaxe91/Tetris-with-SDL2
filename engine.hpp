/**
 * @authors thep1ckaxe
 * @contributor: Ngô Hoan Tài and many more from SDL2's developers
 * email: ThePickaxe91@gmail.com
 *
 * @brief this is also a replicate for pygame in c++, but due to some exploitation, redoing and still testing
 *
 * REQUIREMENT: SDL2 installed to your mingw/include directory, SDL_image/mixer/ttf in a folder named SDL3 also in your mingw/include
 *
 * all pixel format is RGBA32, fixed
 *
 * @warning this is not thread-safe, recommend only sigle threading, currently only support window OS
 *
 * @copyright if you want to use this file, please contact for permission, after that, feel free to use and modify this file
 */
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <bits/stdc++.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_assert.h"
#include "SDL2/SDL_atomic.h"
#include "SDL2/SDL_vulkan.h"
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_version.h"
#include "SDL2/SDL_touch.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL_system.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_stdinc.h"
#include "SDL2/SDL_sensor.h"
#include "SDL2/SDL_scancode.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_quit.h"
#include "SDL2/SDL_power.h"
#include "SDL2/SDL_platform.h"
#include "SDL2/SDL_pixels.h"
#include "SDL2/SDL_mouse.h"
#include "SDL2/SDL_main.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_keyboard.h"
#include "SDL2/SDL_filesystem.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_clipboard.h"
#include "SDL2/SDL_blendmode.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_bits.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include <windows.h>
#define null NULL
// request high performance gpu
extern "C"
{
    __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
    __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
/**
 * TODO: further find optimization, write all instruction for function and classes
 */
namespace sdlgame
{
    typedef enum
    {
        K_a = SDL_SCANCODE_A,
        K_b = SDL_SCANCODE_B,
        K_c = SDL_SCANCODE_C,
        K_d = SDL_SCANCODE_D,
        K_e = SDL_SCANCODE_E,
        K_f = SDL_SCANCODE_F,
        K_g = SDL_SCANCODE_G,
        K_h = SDL_SCANCODE_H,
        K_i = SDL_SCANCODE_I,
        K_j = SDL_SCANCODE_J,
        K_k = SDL_SCANCODE_K,
        K_l = SDL_SCANCODE_L,
        K_m = SDL_SCANCODE_M,
        K_n = SDL_SCANCODE_N,
        K_o = SDL_SCANCODE_O,
        K_p = SDL_SCANCODE_P,
        K_q = SDL_SCANCODE_Q,
        K_r = SDL_SCANCODE_R,
        K_s = SDL_SCANCODE_S,
        K_t = SDL_SCANCODE_T,
        K_u = SDL_SCANCODE_U,
        K_v = SDL_SCANCODE_V,
        K_w = SDL_SCANCODE_W,
        K_x = SDL_SCANCODE_X,
        K_y = SDL_SCANCODE_Y,
        K_z = SDL_SCANCODE_Z,

        K_0 = SDL_SCANCODE_0,
        K_1 = SDL_SCANCODE_1,
        K_2 = SDL_SCANCODE_2,
        K_3 = SDL_SCANCODE_3,
        K_4 = SDL_SCANCODE_4,
        K_5 = SDL_SCANCODE_5,
        K_6 = SDL_SCANCODE_6,
        K_7 = SDL_SCANCODE_7,
        K_8 = SDL_SCANCODE_8,
        K_9 = SDL_SCANCODE_9,

        K_F1 = SDL_SCANCODE_F1,
        K_F2 = SDL_SCANCODE_F2,
        K_F3 = SDL_SCANCODE_F3,
        K_F4 = SDL_SCANCODE_F4,
        K_F5 = SDL_SCANCODE_F5,
        K_F6 = SDL_SCANCODE_F6,
        K_F7 = SDL_SCANCODE_F7,
        K_F8 = SDL_SCANCODE_F8,
        K_F9 = SDL_SCANCODE_F9,
        K_F10 = SDL_SCANCODE_F10,
        K_F11 = SDL_SCANCODE_F11,
        K_F12 = SDL_SCANCODE_F12,

        K_SPACE = SDL_SCANCODE_SPACE,
        K_COMMA = SDL_SCANCODE_COMMA,
        K_PERIOD = SDL_SCANCODE_PERIOD,
        K_SLASH = SDL_SCANCODE_SLASH,
        K_SEMICOLON = SDL_SCANCODE_SEMICOLON,
        K_APOSTROPHE = SDL_SCANCODE_APOSTROPHE,
        K_LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET,
        K_RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET,
        K_BACKSLASH = SDL_SCANCODE_BACKSLASH,
        K_MINUS = SDL_SCANCODE_MINUS,
        K_EQUALS = SDL_SCANCODE_EQUALS,
        K_BACKSPACE = SDL_SCANCODE_BACKSPACE,
        K_RETURN = SDL_SCANCODE_RETURN,

        K_CAPSLOCK = SDL_SCANCODE_CAPSLOCK,
        K_SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK,
        K_NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR,
        K_INSERT = SDL_SCANCODE_INSERT,
        K_HOME = SDL_SCANCODE_HOME,
        K_PAGEUP = SDL_SCANCODE_PAGEUP,
        K_DELETE = SDL_SCANCODE_DELETE,
        K_END = SDL_SCANCODE_END,
        K_PAGEDOWN = SDL_SCANCODE_PAGEDOWN,
        K_RIGHT = SDL_SCANCODE_RIGHT,
        K_LEFT = SDL_SCANCODE_LEFT,
        K_DOWN = SDL_SCANCODE_DOWN,
        K_UP = SDL_SCANCODE_UP,

        K_KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
        K_KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY,
        K_KP_MINUS = SDL_SCANCODE_KP_MINUS,
        K_KP_PLUS = SDL_SCANCODE_KP_PLUS,
        K_KP_ENTER = SDL_SCANCODE_KP_ENTER,
        K_KP_1 = SDL_SCANCODE_KP_1,
        K_KP_2 = SDL_SCANCODE_KP_2,
        K_KP_3 = SDL_SCANCODE_KP_3,
        K_KP_4 = SDL_SCANCODE_KP_4,
        K_KP_5 = SDL_SCANCODE_KP_5,
        K_KP_6 = SDL_SCANCODE_KP_6,
        K_KP_7 = SDL_SCANCODE_KP_7,
        K_KP_8 = SDL_SCANCODE_KP_8,
        K_KP_9 = SDL_SCANCODE_KP_9,
        K_KP_0 = SDL_SCANCODE_KP_0,
        K_KP_PERIOD = SDL_SCANCODE_KP_PERIOD,

        K_APPLICATION = SDL_SCANCODE_APPLICATION,
        K_POWER = SDL_SCANCODE_POWER,
        K_KP_EQUALS = SDL_SCANCODE_KP_EQUALS,
        K_F13 = SDL_SCANCODE_F13,
        K_F14 = SDL_SCANCODE_F14,
        K_F15 = SDL_SCANCODE_F15,
        K_F16 = SDL_SCANCODE_F16,
        K_F17 = SDL_SCANCODE_F17,
        K_F18 = SDL_SCANCODE_F18,
        K_F19 = SDL_SCANCODE_F19,
        K_F20 = SDL_SCANCODE_F20,
        K_F21 = SDL_SCANCODE_F21,
        K_F22 = SDL_SCANCODE_F22,
        K_F23 = SDL_SCANCODE_F23,
        K_F24 = SDL_SCANCODE_F24,
        K_EXECUTE = SDL_SCANCODE_EXECUTE,
        K_HELP = SDL_SCANCODE_HELP,
        K_MENU = SDL_SCANCODE_MENU,
        K_SELECT = SDL_SCANCODE_SELECT,
        K_STOP = SDL_SCANCODE_STOP,
        K_AGAIN = SDL_SCANCODE_AGAIN,
        K_UNDO = SDL_SCANCODE_UNDO,
        K_CUT = SDL_SCANCODE_CUT,
        K_COPY = SDL_SCANCODE_COPY,
        K_PASTE = SDL_SCANCODE_PASTE,
        K_FIND = SDL_SCANCODE_FIND,
        K_MUTE = SDL_SCANCODE_MUTE,
        K_VOLUMEUP = SDL_SCANCODE_VOLUMEUP,
        K_VOLUMEDOWN = SDL_SCANCODE_VOLUMEDOWN,
    } K_Code;
    /*window flag here*/
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

    /*Texture flags ?*/

    /*event type here*/
    typedef enum
    {
        QUIT = SDL_QUIT,
        KEYUP = SDL_KEYUP,
        KEYDOWN = SDL_KEYDOWN,
        MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,
        MOUSEBUTTONUP = SDL_MOUSEBUTTONUP,
        MOUSEMOTION = SDL_MOUSEMOTION,
        MOUSEWHEEL = SDL_MOUSEWHEEL,
        WINDOWEVENT = SDL_WINDOWEVENT,
        USEREVENT = SDL_USEREVENT
    } Event_Code;

    typedef enum
    {
        WINDOWSHOWN = SDL_WINDOWEVENT_SHOWN,              // Window became shown
        WINDOWHIDDEN = SDL_WINDOWEVENT_HIDDEN,            // Window became hidden
        WINDOWEXPOSED = SDL_WINDOWEVENT_EXPOSED,          // Window got updated by some external event
        WINDOWMOVED = SDL_WINDOWEVENT_MOVED,              // Window got moved
        WINDOWRESIZED = SDL_WINDOWEVENT_RESIZED,          // Window got resized
        WINDOWSIZECHANGED = SDL_WINDOWEVENT_SIZE_CHANGED, // Window changed its size
        WINDOWMINIMIZED = SDL_WINDOWEVENT_MINIMIZED,      // Window was minimized
        WINDOWMAXIMIZED = SDL_WINDOWEVENT_MAXIMIZED,      // Window was maximized
        WINDOWRESTORED = SDL_WINDOWEVENT_RESTORED,        // Window was restored
        WINDOWENTER = SDL_WINDOWEVENT_ENTER,              // Mouse entered the window
        WINDOWLEAVE = SDL_WINDOWEVENT_LEAVE,              // Mouse left the window
        WINDOWFOCUSGAINED = SDL_WINDOWEVENT_FOCUS_GAINED, // Window gained focus
        WINDOWFOCUSLOST = SDL_WINDOWEVENT_FOCUS_LOST,     // Window lost focus
        WINDOWCLOSE = SDL_WINDOWEVENT_CLOSE,              // Window was closed
        WINDOWTAKEFOCUS = SDL_WINDOWEVENT_TAKE_FOCUS,     // Window was offered focus (SDL backend >= 2.0.5)
        WINDOWHITTEST = SDL_WINDOWEVENT_HIT_TEST,         // Window has a special hit test (SDL backend >= 2.0.5)
    } Window_Event;
    /*Variable here*/

    /**
     * @return base path to the exe file that call this function
     */
    std::string get_base_path()
    {
        return std::string(SDL_GetBasePath());
    }
    /**
     * @brief namespace for time function and class in sdlgame
     */
    namespace time
    {
        /**
         * @return get time from init in milisecond
         */
        Uint64 get_ticks()
        {
            return SDL_GetTicks64();
        }
        /**
         * get time from init in milisecond
         */
        void wait(Uint32 miliseconds)
        {
            SDL_Delay(miliseconds);
        }

        /**
         * Clock object for time manegement in game
         */
        class Clock
        {
        private:
            Uint32 time;
            std::list<Uint32> elapsedTimes;
            const int MAX_FPS = 120;
            double bullet_time_multiplier = 1;

        public:
            Clock()
            {
                this->time = SDL_GetTicks();
                this->tick();
            }
            /**
             * Update the clock
             * @return the time has passed since the last call to this function
             * @param fps desired FPS, if the fps is too high, it just run as fast as possible
             */
            Uint32 tick(double fps = 0)
            {
                if (fps == 0)
                    fps = MAX_FPS;
                Uint32 currentTime = SDL_GetTicks();
                Uint32 elapsedTime = currentTime - this->time;
                this->time = currentTime;

                if (fps > 0)
                {
                    Uint32 frameTime = 1000 / fps;
                    if (frameTime > elapsedTime)
                    {
                        SDL_Delay(frameTime - elapsedTime);
                        elapsedTime = frameTime;
                    }
                }

                elapsedTimes.push_back(elapsedTime);
                if (elapsedTimes.size() > 10)
                    elapsedTimes.pop_front();
                return elapsedTime;
            }

            /**
             * @return delta-time, time passed that calculated from the lastest call to tick() function
             */
            double delta_time() const
            {
                return elapsedTimes.back() * 1.0 / 1000.0 * bullet_time_multiplier;
            }
            /**
             * function to set bullet time or slow motion by multiply deltatime with certain percentage,
             * this only work if user use delta_time for movement instead of fixed fps with normal increment
             * @param percentage the value is clamp to [1,100], is how much slower time should
             * flow compare to real-time
             */
            void set_bullettime_multiplier(double percentage)
            {
                bullet_time_multiplier = (percentage < 1 ? 1 : (percentage > 100 ? 100 : percentage)) / 100.0;
            }
            /**
             * @return fps rely on 10 last delta time from tick function
             */
            double get_fps() const
            {
                double res = 0;
                for (auto et : elapsedTimes)
                {
                    res += et;
                }
                res /= elapsedTimes.size() * 1000;
                res = 1 / res;
                return res;
            }
        };

    };

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
         * WARNING: not fully tested yet
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
    };

    namespace color
    {
        /**
         *  class for color, all values range from [0,255]
         */
        std::unordered_map<std::string, std::vector<uint8_t>> color_name = {
            {"maroon", {128, 0, 0}},
            {"dark red", {139, 0, 0}},
            {"brown", {165, 42, 42}},
            {"firebrick", {178, 34, 34}},
            {"crimson", {220, 20, 60}},
            {"red", {255, 0, 0}},
            {"tomato", {255, 99, 71}},
            {"coral", {255, 127, 80}},
            {"indian red", {205, 92, 92}},
            {"light coral", {240, 128, 128}},
            {"dark salmon", {233, 150, 122}},
            {"salmon", {250, 128, 114}},
            {"light salmon", {255, 160, 122}},
            {"orange red", {255, 69, 0}},
            {"dark orange", {255, 140, 0}},
            {"orange", {255, 165, 0}},
            {"gold", {255, 215, 0}},
            {"dark golden rod", {184, 134, 11}},
            {"golden rod", {218, 165, 32}},
            {"pale golden rod", {238, 232, 170}},
            {"dark khaki", {189, 183, 107}},
            {"khaki", {240, 230, 140}},
            {"olive", {128, 128, 0}},
            {"yellow", {255, 255, 0}},
            {"yellow green", {154, 205, 50}},
            {"dark olive green", {85, 107, 47}},
            {"olive drab", {107, 142, 35}},
            {"lawn green", {124, 252, 0}},
            {"chartreuse", {127, 255, 0}},
            {"green yellow", {173, 255, 47}},
            {"dark green", {0, 100, 0}},
            {"green", {0, 128, 0}},
            {"forest green", {34, 139, 34}},
            {"lime", {0, 255, 0}},
            {"lime green", {50, 205, 50}},
            {"light green", {144, 238, 144}},
            {"pale green", {152, 251, 152}},
            {"dark sea green", {143, 188, 143}},
            {"medium spring green", {0, 250, 154}},
            {"spring green", {0, 255, 127}},
            {"sea green", {46, 139, 87}},
            {"medium aqua marine", {102, 205, 170}},
            {"medium sea green", {60, 179, 113}},
            {"light sea green", {32, 178, 170}},
            {"dark slate gray", {47, 79, 79}},
            {"teal", {0, 128, 128}},
            {"dark cyan", {0, 139, 139}},
            {"aqua", {0, 255, 255}},
            {"cyan", {0, 255, 255}},
            {"light cyan", {224, 255, 255}},
            {"dark turquoise", {0, 206, 209}},
            {"turquoise", {64, 224, 208}},
            {"medium turquoise", {72, 209, 204}},
            {"pale turquoise", {175, 238, 238}},
            {"aqua marine", {127, 255, 212}},
            {"powder blue", {176, 224, 230}},
            {"cadet blue", {95, 158, 160}},
            {"steel blue", {70, 130, 180}},
            {"corn flower blue", {100, 149, 237}},
            {"deep sky blue", {0, 191, 255}},
            {"dodger blue", {30, 144, 255}},
            {"light blue", {173, 216, 230}},
            {"sky blue", {135, 206, 235}},
            {"light sky blue", {135, 206, 250}},
            {"midnight blue", {25, 25, 112}},
            {"navy", {0, 0, 128}},
            {"dark blue", {0, 0, 139}},
            {"medium blue", {0, 0, 205}},
            {"blue", {0, 0, 255}},
            {"royal blue", {65, 105, 225}},
            {"blue violet", {138, 43, 226}},
            {"indigo", {75, 0, 130}},
            {"dark slate blue", {72, 61, 139}},
            {"slate blue", {106, 90, 205}},
            {"medium slate blue", {123, 104, 238}},
            {"medium purple", {147, 112, 219}},
            {"dark magenta", {139, 0, 139}},
            {"dark violet", {148, 0, 211}},
            {"dark orchid", {153, 50, 204}},
            {"medium orchid", {186, 85, 211}},
            {"purple", {128, 0, 128}},
            {"thistle", {216, 191, 216}},
            {"plum", {221, 160, 221}},
            {"violet", {238, 130, 238}},
            {"magenta", {255, 0, 255}},
            {"fuchsia", {255, 0, 255}},
            {"orchid", {218, 112, 214}},
            {"medium violet red", {199, 21, 133}},
            {"pale violet red", {219, 112, 147}},
            {"deep pink", {255, 20, 147}},
            {"hot pink", {255, 105, 180}},
            {"light pink", {255, 182, 193}},
            {"pink", {255, 192, 203}},
            {"antique white", {250, 235, 215}},
            {"beige", {245, 245, 220}},
            {"bisque", {255, 228, 196}},
            {"blanched almond", {255, 235, 205}},
            {"wheat", {245, 222, 179}},
            {"corn silk", {255, 248, 220}},
            {"lemon chiffon", {255, 250, 205}},
            {"light golden rod yellow", {250, 250, 210}},
            {"light yellow", {255, 255, 224}},
            {"saddle brown", {139, 69, 19}},
            {"sienna", {160, 82, 45}},
            {"chocolate", {210, 105, 30}},
            {"peru", {205, 133, 63}},
            {"sandy brown", {244, 164, 96}},
            {"burly wood", {222, 184, 135}},
            {"tan", {210, 180, 140}},
            {"rosy brown", {188, 143, 143}},
            {"moccasin", {255, 228, 181}},
            {"navajo white", {255, 222, 173}},
            {"peach puff", {255, 218, 185}},
            {"misty rose", {255, 228, 225}},
            {"lavender blush", {255, 240, 245}},
            {"linen", {250, 240, 230}},
            {"old lace", {253, 245, 230}},
            {"papaya whip", {255, 239, 213}},
            {"sea shell", {255, 245, 238}},
            {"mint cream", {245, 255, 250}},
            {"slate gray", {112, 128, 144}},
            {"light slate gray", {119, 136, 153}},
            {"light steel blue", {176, 196, 222}},
            {"lavender", {230, 230, 250}},
            {"floral white", {255, 250, 240}},
            {"alice blue", {240, 248, 255}},
            {"ghost white", {248, 248, 255}},
            {"honeydew", {240, 255, 240}},
            {"ivory", {255, 255, 240}},
            {"azure", {240, 255, 255}},
            {"snow", {255, 250, 250}},
            {"black", {0, 0, 0}},
            {"dim gray", {105, 105, 105}},
            {"dim grey", {105, 105, 105}},
            {"gray", {128, 128, 128}},
            {"grey", {128, 128, 128}},
            {"dark gray", {169, 169, 169}},
            {"dark grey", {169, 169, 169}},
            {"silver", {192, 192, 192}},
            {"light gray", {211, 211, 211}},
            {"light grey", {211, 211, 211}},
            {"gainsboro", {220, 220, 220}},
            {"white smoke", {245, 245, 245}},
            {"white", {255, 255, 255}}};
        class Color
        {
        public:
            Uint8 r, g, b, a;
            Color()
            {
                r = 0;
                g = 0;
                b = 0;
                a = 0;
            }
            Color(const char *c_name)
            {
                std::string name = std::string(c_name);
                if (name == "none")
                {
                    r = 0;
                    g = 0;
                    b = 0;
                    a = 0;
                    return;
                }
                for (char &c : name)
                    c = std::tolower(c);
                if (color_name.find(name) == color_name.end())
                {
                    printf("no such color: %s\n", c_name);
                    exit(0);
                }
                r = color_name[name][0];
                g = color_name[name][1];
                b = color_name[name][2];
                a = 255;
            }
            Color(std::string name)
            {
                if (name == "none")
                {
                    r = 0;
                    g = 0;
                    b = 0;
                    a = 0;
                    return;
                }
                for (char &c : name)
                    c = std::tolower(c);
                if (color_name.find(name) == color_name.end())
                {
                    std::cout << "no such color: " << name << "\n";
                    exit(0);
                }
                r = color_name[name][0];
                g = color_name[name][1];
                b = color_name[name][2];
                a = 255;
            }
            template <class T>
            Color(T _r, T _g, T _b)
            {
                r = _r;
                g = _g;
                b = _b;
                a = 255;
            }
            template <class T>
            Color(T _r, T _g, T _b, T _a)
            {
                r = _r;
                g = _g;
                b = _b;
                a = _a;
            }

            SDL_Color to_SDL_Color() const
            {
                SDL_Color res = {r, g, b, a};
                return res;
            }
            /**return Uint32 kind of color*/
            Uint32 toUint32Color() const
            {
                return SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32), r, g, b, a);
            }
            std::string toString()
            {
                return "Color(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + "," + std::to_string(a) + ")";
            }
        };
    }

    // forward declare
    namespace surface
    {
        class Surface;
    }
    // forward declare
    namespace display
    {
        extern SDL_Window *window;
        extern SDL_Renderer *renderer;
        extern bool isInit;
    }

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

    namespace display
    {
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        sdlgame::surface::Surface win_surf;
        bool isInit = false;

        /**
         * @return hardware resolution, if you have a fullHD monitor
         * this should return a vector2 (1920,1080)
         */
        sdlgame::math::Vector2 get_desktop_size()
        {
            int w = GetSystemMetrics(SM_CXSCREEN);
            int h = GetSystemMetrics(SM_CYSCREEN);
            return sdlgame::math::Vector2(w, h);
        }
        /**
         * Setup a window surface for use
         * @param width the resolution width of the window
         * @param height the resolution height of the window
         * @param flags flags for the window, look for Window_Flags enum for more
         * @return a surface that represent the window, what action affect this window will affect what display on screen
         */
        sdlgame::surface::Surface &set_mode(int width = 0, int height = 0, Uint32 flags = 0)
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
    }

    namespace image
    {
        /**
         * Currently only support JPG and PNG type
         */
        void init()
        {
            if (IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG != IMG_INIT_JPG)
            {
                printf("Failed to init JPG image flags\n%s\n", IMG_GetError());
                exit(0);
            }
            else if (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG != IMG_INIT_PNG)
            {
                printf("Failed to init PNG image flags\n%s\n", IMG_GetError());
                exit(0);
            }
            else
            {
                printf("Image successfully initialized\n");
                return;
            }
        }
        sdlgame::surface::Surface load(std::string path)
        {
            SDL_Texture *tex = IMG_LoadTexture(sdlgame::display::renderer, path.c_str());
            if (tex == NULL)
            {
                printf("Cant load image\n%s\n", IMG_GetError());
                exit(0);
            }
            sdlgame::surface::Surface res = sdlgame::surface::Surface(tex);
            return res;
        }

    }

    namespace key
    {
        namespace
        {
            const Uint8 *keyState;
            std::vector<bool> keys;
        }
        /**
         *  assume that you called the SDL_PumpEvents function before calling this, this funciton should work fine
         */
        std::vector<bool> &get_pressed()
        {
            int numKeys;
            SDL_PumpEvents();
            keyState = SDL_GetKeyboardState(&numKeys);
            if (keys.size() == 0)
                keys.resize(numKeys);
            for (int i = 0; i < numKeys; ++i)
            {
                keys[i] = keyState[i];
            }
            return keys;
        }
    }

    namespace mouse
    {
        // this weird shiet called anonymous namespace, which can only access within the same namespace unit
        // best for not mess up these var some how
        namespace
        {
            sdlgame::math::Vector2 last_mouse_pos = sdlgame::math::Vector2(-1, -1);
            bool isVisible = true;
        }
        sdlgame::math::Vector2 get_pos()
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            return sdlgame::math::Vector2(x, y);
        }
        std::vector<bool> get_pressed()
        {
            int numButtons = 32;
            Uint32 buttonState = SDL_GetMouseState(NULL, NULL);

            std::vector<bool> buttons(numButtons);
            for (int i = 0; i < numButtons; ++i)
            {
                buttons[i] = buttonState & (1 << i);
            }
            return buttons;
        }
        sdlgame::math::Vector2 get_rel()
        {
            if (last_mouse_pos == sdlgame::math::Vector2(-1, -1))
                return sdlgame::math::Vector2(0, 0);
            int x, y;
            SDL_GetMouseState(&x, &y);
            sdlgame::math::Vector2 res = sdlgame::math::Vector2(x, y) - last_mouse_pos;
            last_mouse_pos = sdlgame::math::Vector2(x, y);
            return res;
        }
        void set_visible(int enable)
        {
            isVisible = SDL_ShowCursor(enable);
        }
        bool get_visible()
        {
            return isVisible;
        }
    }

    namespace event
    {
        /**
         *  class represent a event like keyboard input or mouse click (anything happening in the game)
         */
        class Event
        {
        private:
            std::map<std::string, Uint32> dict;

        public:
            Uint32 type;
            Uint32 timestamp;
            SDL_Event tmp_e;
            Event() {}
            Event(SDL_Event e)
            {
                tmp_e = e;
                type = e.type;
                /**
                 * @todo: leave these here in case need, now type only is good enough
                 */
                if (e.type == SDL_WINDOWEVENT)
                {
                    timestamp = e.window.timestamp;
                    dict["windowID"] = e.window.windowID; /**< The associated window */
                    dict["event"] = e.window.event;
                }
                else if (e.type == SDL_KEYDOWN or e.type == SDL_KEYUP)
                {
                    timestamp = e.key.timestamp;
                    dict["key"] = e.key.keysym.scancode;
                }
                else if (e.type == SDL_QUIT)
                {
                    // lol, just here to write const event
                }
                else if (e.type == SDL_MOUSEWHEEL)
                {
                    timestamp = e.wheel.timestamp;
                    dict["x"] = e.wheel.x;
                    dict["y"] = e.wheel.y;
                }
                else if (e.type == SDL_MOUSEBUTTONUP or e.type == SDL_MOUSEBUTTONDOWN)
                {
                    timestamp = e.button.timestamp;
                    dict["button"] = e.button.button;
                    dict["x"] = e.button.x;
                    dict["y"] = e.button.y;
                }
                else if (e.type == SDL_MOUSEMOTION)
                {
                    timestamp = e.motion.timestamp;
                    dict["x"] = e.motion.x;
                    dict["y"] = e.motion.y;
                    dict["xrel"] = e.motion.xrel;
                    dict["yrel"] = e.motion.yrel;
                }
                // else if(e.type == SDL_TEXTINPUT)
                // {

                // }
            }
            Uint32 operator[](std::string key)
            {
                if (dict.find(key) != dict.end())
                {
                    return dict[key];
                }
                else
                {
                    throw std::invalid_argument("There's no such key: " + key);
                }
            }
        };
        std::vector<Event> current_events;
        std::vector<Event> &get()
        {
            SDL_PumpEvents();
            current_events.clear();
            SDL_Event e;
            while (SDL_PollEvent(&e))
                current_events.push_back(Event(e));
            return current_events;
        }
        Event tmp;
        /**please only use this for user event*/
        void post(Uint32 event_type)
        {
            tmp.tmp_e.type = event_type;
            SDL_PushEvent(&tmp.tmp_e);
        }
    }

    /**
     *  for the optimization purposes, draw function that affect dirrectly to window now
     * will have a window_ prefix, for example, for draw a rect to window, the funcion name is window_rect
     * every other draw function without the window_ prefix still use CPU to draw, not GPU
     */
    namespace draw
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
    }

    namespace transform
    {
        /**
         * @return a flipped image in certain axis
         * @param surface source surface
         * @param flip_x whether to flip x or not
         * @param flip_y whether to flip y or not
         */
        sdlgame::surface::Surface flip(sdlgame::surface::Surface surface, bool flip_x, bool flip_y)
        {
            sdlgame::surface::Surface res = surface;
            if (SDL_SetRenderTarget(sdlgame::display::renderer, res.texture))
            {
                printf("Failed to set target: %s\n", SDL_GetError());
            }
            SDL_RendererFlip flipType = SDL_FLIP_NONE;
            if (flip_x)
                flipType = (SDL_RendererFlip)(flipType | SDL_FLIP_HORIZONTAL);
            if (flip_y)
                flipType = (SDL_RendererFlip)(flipType | SDL_FLIP_VERTICAL);
            if (SDL_RenderCopyEx(sdlgame::display::renderer, surface.texture, NULL, NULL, 0, NULL, flipType))
                printf("Failed to flip\n");
            if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
            {
                printf("Failed to set target: %s\n", SDL_GetError());
            }
            return res;
        }
        sdlgame::surface::Surface scale(sdlgame::surface::Surface surface, sdlgame::math::Vector2 size)
        {
            sdlgame::surface::Surface res = sdlgame::surface::Surface(size.x, size.y);
            if (SDL_SetRenderTarget(sdlgame::display::renderer, res.texture))
            {
                printf("Failed to set target: %s\n", SDL_GetError());
            }
            SDL_RenderCopyF(sdlgame::display::renderer, surface.texture, NULL, NULL);
            if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
            {
                printf("Failed to set target: %s\n", SDL_GetError());
            }
            return res;
        }

        sdlgame::surface::Surface scale_by(sdlgame::surface::Surface surface, double factor)
        {
            return sdlgame::transform::scale(surface, surface.get_size() * factor);
        }

        /**
         * return a surface that rotated a certain angle counter-clokcwise with passed center
         * angle unit is degrees
         * TODO: calculate the new size for the res surface
         */
        sdlgame::surface::Surface rotate(sdlgame::surface::Surface surface, double angle_deg, sdlgame::math::Vector2 center)
        {
            sdlgame::math::Vector2 newtopleft = (surface.getRect().getTopLeft() - center).rotate(angle_deg);
            sdlgame::math::Vector2 newbotleft = (surface.getRect().getBottomLeft() - center).rotate(angle_deg);
            sdlgame::math::Vector2 newtopright = (surface.getRect().getTopRight() - center).rotate(angle_deg);
            sdlgame::math::Vector2 newbotright = (surface.getRect().getBottomRight() - center).rotate(angle_deg);

            sdlgame::surface::Surface res = sdlgame::surface::Surface(
                std::max({newtopleft.x, newbotleft.x, newbotright.x, newtopright.x}) - std::min({newtopleft.x, newbotleft.x, newbotright.x, newtopright.x}),
                std::max({newtopleft.y, newbotleft.y, newbotright.y, newtopright.y}) - std::min({newtopleft.y, newbotleft.y, newbotright.y, newtopright.y}));
            if (SDL_SetRenderTarget(sdlgame::display::renderer, res.texture))
            {
                printf("Failed to set target: %s\n", SDL_GetError());
            }
            SDL_FPoint tmp = {float(center.x), float(center.y)};
            SDL_RenderCopyExF(sdlgame::display::renderer, surface.texture, NULL, NULL, angle_deg, &tmp, SDL_FLIP_NONE);
            if (SDL_SetRenderTarget(sdlgame::display::renderer, NULL))
            {
                printf("Failed to set target: %s\n", SDL_GetError());
            }
            return res;
        }
    }
    /**
     * Should be test heavyly around pointer
     * just use stack-alloc like normal
     * treat the pointer as a address holder only,
     * not an pointer to a heap allocated object
     */
    namespace sprite
    {
        /**
         *
         * The base class for visible game objects.
         * Derived classes will want to override the Sprite.update() and assign a Sprite.image and Sprite.rect attributes.
         * The initializer can accept any number of Group instances to be added to
         *
         */
        class Sprite;
        class Group
        {
        public:
            std::set<Sprite *> sprite_list;
            Group(std::vector<Sprite *> sprites = std::vector<Sprite *>())
            {
                for (auto sprite : sprites)
                    this->add(sprite);
            }
            Group &operator=(Group oth)
            {
                sprite_list = oth.sprite_list;
                return *this;
            }
            std::set<Sprite *> &sprites();
            void add(Sprite *sprite);
            void add(std::vector<Sprite *> &sprites);
            void remove(std::vector<Sprite *> &sprites);
            void remove(Sprite *sprite);
            bool has(std::vector<Sprite *> &sprites);
            bool has(Sprite *sprite);
            void update();
            void draw(sdlgame::surface::Surface &surface);
        };

        class Sprite
        {
        public:
            sdlgame::rect::Rect rect;
            sdlgame::surface::Surface image;
            std::set<Group *> group_list;
            Sprite(std::vector<Group *> groups = std::vector<Group *>())
            {
                for (Group *group : groups)
                    this->add(group);
            }
            /**
             * return a set of group that conrtain this sprite
             */
            std::set<Group *> &groups()
            {
                return group_list;
            }
            virtual void update() = 0;
            void add(std::vector<Group *> groups)
            {
                for (auto &group : groups)
                {
                    group->sprite_list.insert(this);
                    group_list.insert(group);
                }
            }
            void add(Group *group)
            {
                group->sprite_list.insert(this);
                group_list.insert(group);
            }
            void remove(std::vector<Group *> groups)
            {
                for (auto &group : groups)
                {
                    auto it = group_list.find(group);
                    if (it != group_list.end())
                    {
                        group->sprite_list.erase(this);
                        group_list.erase(group);
                    }
                }
            }
            void remove(Group *group)
            {
                auto it = group_list.find(group);
                if (it != group_list.end())
                {
                    group->sprite_list.erase(this);
                    group_list.erase(group);
                }
            }
            /**
             * remove this sprite from all group, still usable after call
             */
            void kill()
            {
                for (auto &group : group_list)
                    group->sprite_list.erase(this);
                group_list.clear();
            }
            bool alive()
            {
                return group_list.size() > 0;
            }
        };

        std::set<Sprite *> &Group::sprites()
        {
            return sprite_list;
        }
        void Group::add(Sprite *sprite)
        {
            sprite_list.insert(sprite);
            sprite->group_list.insert(this);
        }
        void Group::add(std::vector<Sprite *> &sprites)
        {
            for (auto &sprite : sprites)
            {
                sprite_list.insert(sprite);
                sprite->group_list.insert(this);
            }
        }
        void Group::remove(std::vector<Sprite *> &sprites)
        {
            for (auto &sprite : sprites)
            {
                auto it = sprite_list.find(sprite);
                if (it != sprite_list.end())
                {
                    sprite->remove(this);
                    sprite_list.erase(it);
                }
            }
        }
        void Group::remove(Sprite *sprite)
        {
            auto it = sprite_list.find(sprite);
            if (it != sprite_list.end())
            {
                sprite->remove(this);
                sprite_list.erase(it);
            }
        }
        bool Group::has(std::vector<Sprite *> &sprites)
        {
            for (auto &sprite : sprites)
            {
                if (sprite_list.find(sprite) == sprite_list.end())
                    return false;
            }
            return true;
        }
        bool Group::has(Sprite *sprite)
        {
            if (sprite_list.find(sprite) == sprite_list.end())
                return false;
            return true;
        }
        void Group::update()
        {
            for (auto &sprite : sprite_list)
            {
                sprite->update();
            }
        }
        void Group::draw(sdlgame::surface::Surface &surface)
        {
            for (auto &sprite : sprite_list)
            {
                surface.blit(sprite->image, sprite->rect.getTopLeft());
            }
        }
        /**
         * Also a sprite group, the only difference is it only hold 1 sprite,
         * if you call add, it will replace that sprite
         */
        class GroupSingle
        {
        public:
            Sprite *sprite;
            GroupSingle(Sprite *sprite = NULL)
            {
                this->sprite = sprite;
            }
            void add(Sprite *sprite)
            {
                this->sprite = sprite;
            }
            void remove()
            {
                sprite = NULL;
            }
            void update()
            {
                sprite->update();
            }
            void draw(sdlgame::surface::Surface &surface)
            {
                surface.blit(sprite->image, sprite->rect.getTopLeft());
            }
        };

        /**
         * @return a list containing all Sprites in a Group that intersect with another Sprite.
         * Intersection is determined by comparing the Sprite.rect attribute of each Sprite.
         * The dokill argument is a bool. If set to True, all Sprites that collide will be removed from the Group.
         */
        std::vector<Sprite *> spritecollide(Sprite *sprite, Group *group, bool dokill = false)
        {
            std::vector<Sprite *> res;
            for (auto &img : group->sprite_list)
            {
                if (img->rect.colliderect(sprite->rect))
                {
                    res.push_back(img);
                }
            }
            if (dokill)
                group->remove(res);
            return res;
        }
        /**
         * @return if 2 sprite is collide or not, but using 2 sprite, both must have rect attr defined
         */
        bool collide_rect(Sprite *left, Sprite *right)
        {
            return left->rect.colliderect(right->rect);
        }
        /**
         * Tests for collision between two sprites,
         * by testing to see if two circles centered on the sprites overlap.
         * If the radius value is passed, it will check if 2 circle center at the both rect center is collide with that center and that radius or not
         * otherwise a circle is created that is big enough to completely enclose the sprites rect as given by the "rect" attribute.
         */
        bool collide_circle(Sprite *left, Sprite *right, double left_radius = 0, double right_radius = 0)
        {
            left_radius = (left_radius == 0 ? (left->rect.getTopLeft() - left->rect.getBottomRight()).magnitude() / 2 : left_radius);
            right_radius = (right_radius == 0 ? (right->rect.getTopLeft() - right->rect.getBottomRight()).magnitude() / 2 : right_radius);
            return (left->rect.getCenter() - right->rect.getCenter()).magnitude() <= left_radius + right_radius;
        }

    }

    /**
     * @brief due to its complexity, it's best practice to call init function as use in main function
     */
    namespace mixer
    {

        /*set number of playback channel, default is 8*/
        void set_num_channels(int count)
        {
            Mix_AllocateChannels(count);
        }
        /**
         * @param freq freqency of the audio
         * @param size determine the audio format, you can choose between 16 or 32 bit audio
         * @param channels 1 for mono, 2 for stereo
         * @param buffer size of sample that fed to the computer, the larger then better qualiy, but more audio lag
         * @param devicename name of the device, leave it as empty to be default system
         * Init the mixer module, it not guarantee that all flag can be sucessfully init since it depend on what in the os
         */
        void init(int freq = 44100, Uint16 size = 16, int channels = 2, int buffer = 512)
        {
            size = (size == 16 ? AUDIO_S16SYS : AUDIO_F32SYS);
            if (Mix_Init(MIX_INIT_MP3) & MIX_INIT_MP3 != MIX_INIT_MP3)
            {
                printf("Failed to init mp3 type\nErr:%s\n", Mix_GetError());
            }
            else if (Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG != MIX_INIT_OGG)
            {
                printf("Failed to init ogg type\nErr:%s\n", Mix_GetError());
            }
            else if (Mix_Init(MIX_INIT_WAVPACK) & MIX_INIT_WAVPACK != MIX_INIT_WAVPACK)
            {
                printf("Failed to init wav pack\nErr:%s\n", Mix_GetError());
            }
            else if (Mix_OpenAudio(freq, size, channels, buffer))
            {
                printf("Failed to init mixer\nErr:%s\n", Mix_GetError());
                exit(0);
            }
            else
            {
                printf("Mixer successfully initialized\n");
            }
        }
        int get_num_channels()
        {
            return Mix_AllocateChannels(-1);
        }
        class Sound;

        int convert_volume_value(float value)
        {
            return int((value >= 1 ? 1 : value) / 1.0 * 128);
        }
        /**
         * A Channel object to controll playback at certain channel id,
         * in its core, it just a int var hold the id to the channel after all
         */
        class Channel
        {
        private:
            int id;
            float volume = 1;

        public:
            Channel(int id)
            {
                this->id = id;
            }
            void play(Sound sound, int loops = 0, int maxtime_ms = -1, int fade_ms = 0);
            void set_volume(float value);
            int get_volume();
        };

        /**
         * class represent a Sound object, should be only support WAV and OGG,
         * if you need to play music, use music namepsace instead
         */
        class Sound
        {
        private:
            std::atomic_int channels;
            float volume = 1;

        public:
            Mix_Chunk *chunk = NULL;
            Sound() = default;
            Sound(std::string path)
            {
                chunk = Mix_LoadWAV(path.c_str());
                if (chunk == NULL)
                {
                    printf("Cant load track\nErr:%s\n", Mix_GetError());
                    exit(0);
                }
            }
            /**
             * @param loops -1 to loop infinitely, 0 is play once, 1 is twice...
             * @param maxtime_ms maximum time in miliseconds the sound will be play in ms until it stop
             * @param fade_ms fade in time in miliseconds
             */
            Channel play(int loops = 0, int maxtime_ms = -1, int fade_ms = 0)
            {
                int channel = Mix_FadeInChannelTimed(-1, chunk, loops, fade_ms, maxtime_ms);
                if (channel == -1)
                {
                    printf("cant play sound for some reason\nErr:%s\n", Mix_GetError());
                    exit(0);
                }
                return Channel(channel);
            }
            void load(std::string path)
            {
                if (chunk != NULL)
                    Mix_FreeChunk(chunk);
                chunk = Mix_LoadWAV(path.c_str());
                if (chunk == NULL)
                {
                    printf("Cant load track\nErr:%s\n", Mix_GetError());
                    exit(0);
                }
            }
            void fadeout(int ms)
            {
                Mix_FadeOutChannel(channels, ms);
            }
            /**
             * This will set the playback volume (loudness) for this Sound.
             * This will immediately affect the Sound if it is playing.
             * It will also affect any future playback of this Sound.
             * @param value (float) --
                volume in the range of 0.0 to 1.0 (inclusive)
                If value < 0.0, the volume will not be changed
                If value > 1.0, the volume will be set to 1.0
            */
            void set_volume(float value)
            {
                Mix_VolumeChunk(chunk, convert_volume_value(value));
            }
            int get_volume() const
            {
                return Mix_VolumeChunk(chunk, -1);
            }
            ~Sound()
            {
                if (chunk != NULL)
                    Mix_FreeChunk(chunk);
            }
        };

        void Channel::play(Sound sound, int loops, int maxtime_ms, int fade_ms)
        {
            if (Mix_FadeInChannelTimed(id, sound.chunk, loops, fade_ms, maxtime_ms) == -1)
            {
                printf("cant play sound for some reason\nErr:%s\n", Mix_GetError());
                exit(0);
            }
        }
        void Channel::set_volume(float value)
        {
            Mix_Volume(id, convert_volume_value(value));
        }
        int Channel::get_volume()
        {
            return Mix_Volume(id, -1);
        }
    }

    namespace font
    {
        // std::string window_font_path = "C:/Windows/Fonts/";
        /**
         * @brief initialize font, after call this function, you should be able to use other function and class
         */
        void init()
        {
            if (TTF_Init())
            {
                printf("Failed to init font\n%s\n", TTF_GetError());
                exit(0);
            }
            else
            {
                printf("Font successfully initialized\n");
                return;
            }
        }
        /**
         * Load a new font from a given filename or a python file object.
         * The size is the height of the font in pixels
         */
        class Font
        {
        private:
            int height;

        public:
            TTF_Font *font;

            Font(std::string path, int size = 12)
            {
                height = size;
                font = TTF_OpenFont(path.c_str(), size);
                if (!font)
                {
                    printf("Cant load font\n%s\n", TTF_GetError());
                    exit(0);
                }
            }

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
            sdlgame::surface::Surface render(const std::string text, int antialias, sdlgame::color::Color color, uint32_t wrap_length = 0, sdlgame::color::Color background = sdlgame::color::Color(0, 0, 0, 0))
            {
                SDL_Surface *surface;
                if (!antialias)
                {
                    surface = TTF_RenderUTF8_Solid_Wrapped(font, text.c_str(), color.to_SDL_Color(), wrap_length);
                }
                else if (antialias == 1)
                {
                    surface = TTF_RenderUTF8_Shaded_Wrapped(font, text.c_str(), color.to_SDL_Color(), sdlgame::color::Color(0, 0, 0, 0).to_SDL_Color(), wrap_length);
                }
                else
                {
                    surface = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color.to_SDL_Color(), wrap_length);
                }
                if (surface == NULL)
                {
                    printf("Error render font\n%s\n", TTF_GetError());
                    exit(0);
                }
                sdlgame::surface::Surface res(surface->w, surface->h);
                res.fill(background);
                SDL_SetRenderTarget(sdlgame::display::renderer, res.texture);
                if (SDL_RenderCopy(sdlgame::display::renderer,
                                   SDL_CreateTextureFromSurface(sdlgame::display::renderer, surface), NULL, NULL))
                {
                    printf("Error create a rendered font\n%s\n", SDL_GetError());
                    exit(0);
                }
                SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
                return res;
            }
        };

        // /**
        //  * @param path directory to the font
        //  * @param size height of the font in pixel
        //  * @return a Font object that is a font from system
        // */
        // Font SysFont(std::string path, int size = 12)
        // {
        //     return Font(window_font_path + path, size);
        // }
    }

    namespace random
    {
        /*
         * return a random interger in range [l,r], if l > r, it automatically swap
         * the range can be up to 2^30
         */
        int randint(int l, int r)
        {
            srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
            if (l > r)
                std::swap(l, r);
            return (rand() * rand()) % (r - l + 1) + l;
        }

        /**
         * return a random value between 0 and 1
         */
        float randf()
        {
            return randint(0, 1000000) / 1000000.0;
        }
    }

    namespace music
    {
        Mix_Music *music = NULL;
        bool playing = 0;
        void load(std::string path)
        {
            if (music != NULL)
                Mix_FreeMusic(music);
            music = Mix_LoadMUS(path.c_str());
            if (!music)
            {
                printf("Cant load music\nErr:%s\n", Mix_GetError());
                exit(0);
            }
        }
        void play(int loop = 0)
        {
            if (Mix_PlayMusic(music, loop))
            {
                printf("Cant play music\nErr:%s\n", Mix_GetError());
                exit(0);
            }
        }
        void pause()
        {
            Mix_PauseMusic();
        }
        void resume()
        {
            Mix_ResumeMusic();
        }
        void stop()
        {
            Mix_HaltMusic();
        }
        // Return duration of the music in second
        double duration()
        {
            return Mix_MusicDuration(music);
        }
    }

    void init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            printf("Error initializing SDL: %s\n", SDL_GetError());
            exit(0);
        }
        else
        {
            printf("SDL successfully initialized\n");
        }
    }
    void quit()
    {
        SDL_DestroyWindowSurface(sdlgame::display::window);
        SDL_DestroyRenderer(sdlgame::display::renderer);
        SDL_DestroyWindow(sdlgame::display::window);
        IMG_Quit();
        Mix_Quit();
        TTF_Quit();
        SDL_Quit();
    }
};

#endif