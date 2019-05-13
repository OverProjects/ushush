#include <iostream>
#include <cmath>
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

    //window.setMouseCursorVisible(false);

    // end init window

    // construct classes

    Randoma rdd;

    Mouse mous;

    Display background;
    Display diTime;
    Display diFPS;

    Display dileTruc;

    Perso pers;

    // end construct classes
    // init classes

    mous.init("GFX/shout/vise.png", window);
    //mous.setSpriteScale(10, 10, window);


    background.init("GFX/back/bg1", 0, window);
    background.setSpriteScale(1, 1, window);

    diTime.init("manger", 1, window);
    diTime.setTPosition(0, 0);

    diFPS.init("manger2", 1, window);
    diFPS.setTPosition(0, 100);

    pers.init("GFX/shout/perso.png", 0, window);
    pers.setSpriteScale(20, 6, window);
    pers.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    dileTruc.init("manger3", 1, window);
    dileTruc.setTPosition(100, 100);

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
                    {window.close();}
            if (event.type == sf::Event::Resized)
                    {pers.setScreenSize(window.getSize().x, window.getSize().y);}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {window.close();}

        }

        window.clear();
        // update and show

        rdd.update();

        mous.update(window);

        diTime.update(3);
        diFPS.update(4);
        dileTruc.setTString(std::to_string(pers.m_toMouse.x));
        background.update(0);

        pers.update(window);

        background.show(window);
        pers.show(window);
        diTime.show(window);
        dileTruc.show(window); // la
        mous.show(window);

        // end update and show

        // gestion fps

        while(diFPS.getTim().asMilliseconds() < 25)
            {diFPS.update(4);}
        if (diFPS.getTim().asMilliseconds() > 300) {std::cout << "oula" << std::endl;}

        diFPS.setTPosition(window.getSize().x - diFPS.getTex().getLocalBounds().width - 5, 0);
        diFPS.show(window);
        diFPS.setCloRestart();

        // end gestion fps

        window.display();
    }
// END BOUCLE PRINCIPALE
    window.setMouseCursorVisible(true);

}
