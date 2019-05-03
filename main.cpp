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
    // init window
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                        sf::VideoMode::getDesktopMode().height),
                                        "Le debut du commencement");
    sf::Image icon;
    if (!icon.loadFromFile("GFX/icone.png")) {std::cerr << "No load for icone.png" << std::endl;}
    else {window.setIcon(225,225,icon.getPixelsPtr());}
    // end init window

    // construct classes

    Randoma rdd;

    Display background;
    Display diTime;
    Display diFPS;

    sf::Clock cloFPS;
    sf::Time timFPS;

    // end construct classes

    // init classes

    background.init("GFX/back/bg1", 0);
    background.setSpriteScale(1, 1, window);

    diTime.init("manger", 1); //manque un truc
    diTime.setTPosition(0, 0);

    diFPS.init("manger2", 1);
    diFPS.setTPosition(0, 100);

    // end init classes

    int nbshape{5000}; // max 100 000 10ms (pas de test plus loin)
    sf::VertexArray stars(sf::Points, nbshape);
    for (int i = 0; i < nbshape; i++)
    {
        stars[i].position = sf::Vector2f(rdd.genRand(0, window.getSize().x), rdd.genRand(0, window.getSize().y));
    }

    // test
    Mov perso(window);
    //perso.init("GFX/renard.png");
    perso.setSpriteScale(5, 3, window);
    perso.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    // end test

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
        // update and show

        rdd.update();

        diTime.update(3);
        diFPS.update(3);
        background.update(0);

            //test
        //perso.update("ligne");
        //perso.show(window);
            //end test

        diFPS.setTPosition(window.getSize().x - diFPS.getTex().getLocalBounds().width - 5, 0);

        background.show(window);
        diTime.show(window);

        for (int i = 0; i < nbshape; i++)
        {
            stars[i].position = sf::Vector2f(stars[i].position.x - rdd.genEzRand(2) + rdd.genEzRand(2),
                                           stars[i].position.y - rdd.genEzRand(2) + rdd.genEzRand(2));
            if (stars[i].position.x > window.getSize().x) {stars[i].position.x = 0;}
            else if (stars[i].position.x < 0) {stars[i].position.x = window.getSize().x;}

            if (stars[i].position.y > window.getSize().y) {stars[i].position.y = 0;}
            else if (stars[i].position.y < 0) {stars[i].position.y = window.getSize().y;}
        }
        window.draw(stars);

        // end update and show

        // gestion fps

        timFPS = cloFPS.getElapsedTime();

        while(diFPS.getTim().asMilliseconds() < 50)
            {diFPS.update(3);}
        if (diFPS.getTim().asMilliseconds() > 300) {std::cout << "oula" << std::endl;}

        diFPS.show(window);
        diFPS.setCloRestart();

        // end gestion fps

        window.display();

// END BOUCLE PRINCIPALE
    }

    return 0;
}
