#ifndef SDLGAME_TIME_
#define SDLGAME_TIME_

namespace sdlgame
{
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

    }
} // namespace sdlgame


#endif