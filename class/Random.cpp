#include <iostream>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Random.hpp"

Randoma::Randoma()
{
    aNumber = 0;
    incre = 1;
    m_nbPeriod = 200;
    for (int i = 0; i < m_nbPeriod; i++)
    {
        period.push_back(genRand(0,50));
    }
}

int Randoma::genRand(int x, int y)
{

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(x,y);

    return dist6(rng);
}

int Randoma::genEzRand(int y)
{
    incre ++;
    if (incre > m_nbPeriod) {incre = 1;}
    aNumber = aNumber * 6 - period[incre] / 12 + period[incre - 1];
    aNumber %= y;
    return aNumber;
    aNumber += incre;
}

void Randoma::update()
{
    m_tim = m_clo.getElapsedTime();
    if (m_tim.asMilliseconds() > 1000)
    {
        for (int i = 0; i < m_nbPeriod; i++)
        {
            period[i] = genRand(0, 50);
        }
        m_clo.restart();
    }
}
