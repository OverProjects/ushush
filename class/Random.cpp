#include <iostream>
#include <random>

#include "Random.hpp"

int Randoma::genRand(int x, int y)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(x,y); // distribution in range [1, 6]

    //std::cout << dist6(rng) << std::endl;

    return dist6(rng);
}
