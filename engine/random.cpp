#include "random.hpp"
#include <chrono>
#include <random>

int sdlgame::random::randint(int l, int r)
{
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    if (l > r)
        std::swap(l, r);
    return (rand() * rand()) % (r - l + 1) + l;
}

/**
 * return a random value between 0 and 1
 */
float sdlgame::random::randf()
{
    return randint(0, 1000000) / 1000000.0;
}