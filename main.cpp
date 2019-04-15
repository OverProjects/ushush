#include <iostream>
#include <SFML/Graphics.hpp>

#include "class/Display.hpp"

int main()
{
    Display didi;
    didi.init("GFX/back/bg1");

    sf::RenderWindow window(sf::VideoMode(didi.getSize().x, didi.getSize().y),
                            "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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
        didi.show(window);
        window.draw(shape);
        window.display();
    }

    return 0;
}
