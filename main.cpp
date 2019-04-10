#include <iostream>
#include <SFML/Graphics.hpp>

#include "class/Display.hpp"

int main()
{
    Display didi;
    didi.init("GFX/boy.jpg");

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
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
