#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "class/Display.hpp"
#include "class/Move.hpp"
#include "class/Input.hpp"
#include "class/Random.hpp"

int main()
{
// INITIALISATION
    Randoma rdd;

    Display didi;
    didi.init("GFX/back/bg1");

    sf::RenderWindow window(sf::VideoMode(didi.getSize().x, didi.getSize().y),
                            "Le debut du commencement");
    int nbshape{1000}; //max 4000 150m

    sf::VertexArray stars(sf::Points, nbshape);

    sf::Clock cloFPS;
    sf::Time timFPS;

    Display diFPS;
    diFPS.init(std::to_string(timFPS.asMilliseconds()), 1);
    diFPS.setTPosition(window.getSize().x - 100, 0);

    sf::Image icon;
    if (!icon.loadFromFile("GFX/icone.png")) {std::cerr << "No load for icone.png" << std::endl;}
    window.setIcon(225,225,icon.getPixelsPtr());

    //test
    Mov perso(window);
    perso.init("GFX/renard.png");
    perso.setSpriteScale(5, 3, window);
    perso.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    //end test
    for (int i = 0; i < nbshape; i++)
    {
        stars[i].position = sf::Vector2f(rdd.genRand(0, window.getSize().x), rdd.genRand(0, window.getSize().y));
    }

// END INITIALISATION
/////////////////////////////////////////////////////////////////////////////////////////////
// BOUCLE PRINCIPALE

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

        }

        window.clear();

        didi.update();
        //TEST
        perso.update("ligne");
        //end test

        didi.show(window, 1);
        //perso.show(window, 0);
        diFPS.show(window, 1);

        for (int i = 0; i < nbshape; i++)
        {
            stars[i].position = sf::Vector2f(stars[i].position.x - rdd.genRand(0, 1) + rdd.genRand(0, 1),
                                           stars[i].position.y - rdd.genRand(0, 1) + rdd.genRand(0, 1));
            //stars[i].position = sf::Vector2f(stars[i].position.x - 1, stars[i].position.y - 1);
        }
        window.draw(stars);

        window.display();

        timFPS = cloFPS.getElapsedTime();
        while(timFPS.asMilliseconds() < 10)
            {timFPS = cloFPS.getElapsedTime();}
        if (timFPS.asMilliseconds() > 300) {std::cout << "oula" << std::endl;}
        diFPS.update(std::to_string(timFPS.asMilliseconds()));

        cloFPS.restart();

// END BOUCLE PRINCIPALE
    }

    return 0;
}
