#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "class/Display.hpp"
#include "class/Move.hpp"

int main()
{
    Display didi;
    didi.init("GFX/back/bg1");

    sf::RenderWindow window(sf::VideoMode(didi.getSize().x, didi.getSize().y),
                            "Le debut du commencement");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock cloFPS;
    sf::Time timFPS;

    Mov boy;
    boy.init("GFX/boy.jpg");

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
        //window.draw(shape);
        window.display();

        while(timFPS.asMilliseconds() < (250))
            {timFPS = cloFPS.getElapsedTime();}
        cloFPS.restart();
    }

    return 0;
}
