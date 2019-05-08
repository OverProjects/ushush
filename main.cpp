#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "class/Display.hpp"
#include "class/Move.hpp"
#include "class/Input.hpp"
#include "class/Random.hpp"

#include "stars/stars.hpp"
#include "shout/shout.hpp"

int main()
{
    bool isWorking{true};
    int decision{0};

    while (isWorking)
    {
        std::cout << std::endl << "Hello to this amazing world of progress\nPlease select your amusement by typing the number decided\n" <<
        "0. Quit\n1. Stars\n2. Mc Gonagal" << std::endl;

        std::cin >> decision;

        switch (decision)
        {
            case 1 : launchStars(); break;
            case 2 : lauchShoot(); break;
            case 0 : isWorking = false; break;
            default : break;
        }
    }
}
