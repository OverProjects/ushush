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
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock cloFPS;
    sf::Time timFPS;

    sf::Image icon;
    if (!icon.loadFromFile("GFX/icone.png")) {std::cerr << "No load for icone.png" << std::endl;}
    window.setIcon(225,225,icon.getPixelsPtr());

    Mov boy[5];

    for (int i = 0; i < 5; i++)
    {
        boy[i].init("GFX/renard.jpg");
        boy[i].setPosition(rdd.genRand(0, 500), rdd.genRand(0,500));
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

        for (int i = 0; i < 5; i++)
        {
            boy[i].show(window);
        }
        //window.draw(shape);
        window.display();

        while(timFPS.asMilliseconds() < (250))
            {timFPS = cloFPS.getElapsedTime();}
        cloFPS.restart();
    }

    return 0;
}
