#ifndef SDLGAME_RANDOM_
#define SDLGAME_RANDOM_

namespace sdlgame {
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
}

#endif