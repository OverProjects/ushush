#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "class/Display.hpp"
#include "class/Move.hpp"
#include "class/Input.hpp"
#include "class/Random.hpp"

int main()
{
    Randoma rdd;

    Display didi;
    didi.init("GFX/back/bg1");

    sf::RenderWindow window(sf::VideoMode(didi.getSize().x, didi.getSize().y),
                            "Le debut du commencement");
    int nbshape{500};
    sf::CircleShape shape[nbshape];
    sf::Vector2i sPos;

    sf::Clock cloFPS;
    sf::Time timFPS;

    Display diFPS;
    diFPS.init(std::to_string(timFPS.asMilliseconds()), 1);
    diFPS.setTPosition(window.getSize().x - 100, 0);

    sf::Image icon;
    if (!icon.loadFromFile("GFX/icone.png")) {std::cerr << "No load for icone.png" << std::endl;}
    window.setIcon(225,225,icon.getPixelsPtr());

    for (int i = 0; i < nbshape; i++)
    {
        shape[i].setFillColor(sf::Color::White);
        shape[i].setRadius(1);
        shape[i].setPosition(rdd.genRand(0, window.getSize().x), rdd.genRand(0, window.getSize().y));
    }


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
                //shape.setFillColor(sf::Color::Red);
            }

        }

        window.clear();

        didi.update();

        didi.show(window);
        diFPS.show(window);

        for (int i = 0; i < nbshape; i++)
        {
            sPos.x = shape[i].getPosition().x - rdd.genRand(0, 1) + rdd.genRand(0, 1);
            sPos.y = shape[i].getPosition().y - rdd.genRand(0 ,1) + rdd.genRand(0, 1);

            if (sPos.x > window.getSize().x) {sPos.x = window.getSize().x;}
            else if (sPos.x < 0) {sPos.x = 0;}
            if (sPos.y > window.getSize().y) {sPos.y = window.getSize().y;}
            else if (sPos.y < 0) {sPos.y = 0;}

            shape[i].setPosition(sPos.x, sPos.y);
            window.draw(shape[i]);
        }
        window.display();

        timFPS = cloFPS.getElapsedTime();
        while(timFPS.asMilliseconds() < 50)
            {timFPS = cloFPS.getElapsedTime();}
        if (timFPS.asMilliseconds() > 100) {std::cout << "oula" << std::endl;}
        diFPS.update(std::to_string(timFPS.asMilliseconds()));

        cloFPS.restart();
    }

    return 0;
}
