#include <iostream>
#include <SFML/Graphics.hpp>

#include "../class/Display.hpp"
#include "../class/Input.hpp"
#include "../class/Random.hpp"

#include "shout.hpp"

int lauchShoot()
{
// INITIALISATION
    // init window
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
                                        sf::VideoMode::getDesktopMode().height),
                                        "Stars along the way");
    sf::Image icon;
    if (!icon.loadFromFile("GFX/icone.png")) {std::cerr << "No load for icone.png" << std::endl;}
    else {window.setIcon(225,225,icon.getPixelsPtr());}
    // end init window

    // construct classes

    Randoma rdd;

    Input in;

    Display background;
    Display diTime;
    Display diFPS;

    Perso pers;

    // end construct classes
    // init classes

    background.init("GFX/back/bg1", 0);
    background.setSpriteScale(1, 1, window);

    diTime.init("manger", 1);
    diTime.setTPosition(0, 0);

    diFPS.init("manger2", 1);
    diFPS.setTPosition(0, 100);

    pers.init("GFX/renard.jpg", 0);
    pers.setSpriteScale(12, 3, window);
    pers.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // end init classes
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
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            */

        }

        window.clear();
        // update and show

        rdd.update();

        in.handleInputs(window);

        diTime.update(3);
        diFPS.update(4);
        background.update(0);

        pers.update(in);

        background.show(window);
        pers.show(window);
        diTime.show(window);

        // end update and show

        // gestion fps

        while(diFPS.getTim().asMilliseconds() < 50)
            {diFPS.update(4);}
        if (diFPS.getTim().asMilliseconds() > 300) {std::cout << "oula" << std::endl;}

        diFPS.setTPosition(window.getSize().x - diFPS.getTex().getLocalBounds().width - 5, 0);
        diFPS.show(window);
        diFPS.setCloRestart();

        // end gestion fps

        window.display();
    }
// END BOUCLE PRINCIPALE
}
