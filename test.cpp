#include <iostream>
#include <SFML/Graphics.hpp>

#include "test.hpp"

int lauchTest()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                          sf::VideoMode::getDesktopMode().height),
                                          "A new brand");

    sf::Clock clo;
    sf::Time tim;

    Perso perso("GFX/paki2.png");
    perso.setShow(true, true, true,true);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) {window.close();}
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window.close();}

        window.clear(sf::Color::White);

        perso.update(window);

        perso.show(window);

        do
        {
            tim = clo.getElapsedTime();
        }   while (tim.asMilliseconds() < 25);

        clo.restart();

        window.display();
    }

    return 0;
}
