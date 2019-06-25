#include <iostream>
#include <SFML/Graphics.hpp>

#include "perso.hpp"
#include "mapping.hpp"
#include "ground.hpp"

int launchUshush()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                          sf::VideoMode::getDesktopMode().height),
                                          "A new brand");
    sf::View view;
    view.reset(sf::FloatRect(0, 0, 500, 500));

    sf::Clock clo;
    sf::Time tim;

    Ground ground;
    ground.init("GFX/shout/background/echec.jpg");

    Perso perso("GFX/paki2.png", window);
    perso.setShow(true, true, true,true);

    Mapping mapping;
    mapping.init("GFX/shout/MAP.tt", 0);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) {window.close();}
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window.close();}

        window.clear(sf::Color::White);

        perso.update(window, mapping);

        ground.showBack(window);
        perso.show(window);
        mapping.show(window);

        do {
            tim = clo.getElapsedTime();
        }   while (tim.asMilliseconds() < 25);

        clo.restart();

        view.reset(sf::FloatRect(perso.getSprite().getPosition().x - 400,
                                 perso.getSprite().getPosition().y - 400,
                                 800, 800));
        window.setView(view);
        window.display();
    }

    return 0;
}
