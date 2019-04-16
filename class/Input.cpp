#include <iostream>
#include <SFML/Graphics.hpp>

#include "Input.hpp"

void Input::setButton(int button, bool state)
{
    switch(button)
    {
        case m_LEFT : m_button.leftBut = state; break;
        case m_RIGHT : m_button.rightBut = state; break;
        case m_UP : m_button.upBut = state; break;
        case m_DOWN : m_button.downBut = state; break;

        default : break;
    }
}

void Input::handleInputs(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed : window.close(); break;
            case sf::Event::LostFocus : window.setTitle("FF no focus"); break;
            case sf::Event::GainedFocus : window.setTitle("FF focusing"); break;

            case sf::Event::MouseMoved : m_mouse.oMouseX = m_mouse.mouseX;
                m_mouse.oMouseY = m_mouse.mouseY;
                m_mouse.mouseX = event.mouseMove.x;
                m_mouse.mouseY = event.mouseMove.y; break;

            case sf::Event::KeyPressed :
                event.key.code == sf::Keyboard::Left ? m_button.leftBut = true : m_button.leftBut = false;
                event.key.code == sf::Keyboard::Right ? m_button.rightBut = true : m_button.rightBut = false;
                event.key.code == sf::Keyboard::Up ? m_button.upBut = true : m_button.upBut = false;
                event.key.code == sf::Keyboard::Down ? m_button.downBut = true : m_button.downBut = false;
                event.key.code == sf::Keyboard::A ? m_button.aBut = true : m_button.aBut = false;
                event.key.code == sf::Keyboard::Z ? m_button.bBut = true : m_button.bBut = false;
                event.key.code == sf::Keyboard::Q ? m_button.xBut = true : m_button.xBut = false;
                event.key.code == sf::Keyboard::S ? m_button.yBut = true : m_button.yBut = false;
                event.key.code == sf::Keyboard::E ? m_button.rBut = true : m_button.rBut = false;
                event.key.code == sf::Keyboard::D ? m_button.lBut = true : m_button.lBut = false;

                if (event.key.code == sf::Keyboard::Escape) {window.close();}

                break;

            case sf::Event::KeyReleased :
                event.key.code == sf::Keyboard::Left ? m_button.leftBut = true : m_button.leftBut = false;
                event.key.code == sf::Keyboard::Right ? m_button.rightBut = true : m_button.rightBut = false;
                event.key.code == sf::Keyboard::Up ? m_button.upBut = true : m_button.upBut = false;
                event.key.code == sf::Keyboard::Down ? m_button.downBut = true : m_button.downBut = false;
                event.key.code == sf::Keyboard::A ? m_button.aBut = true : m_button.aBut = false;
                event.key.code == sf::Keyboard::Z ? m_button.bBut = true : m_button.bBut = false;
                event.key.code == sf::Keyboard::Q ? m_button.xBut = true : m_button.xBut = false;
                event.key.code == sf::Keyboard::S ? m_button.yBut = true : m_button.yBut = false;
                event.key.code == sf::Keyboard::E ? m_button.rBut = true : m_button.rBut = false;
                event.key.code == sf::Keyboard::D ? m_button.lBut = true : m_button.lBut = false;

                break;

            default : break;
        }
    }
    sf::Joystick::isButtonPressed(0,0) ? m_jbutton.aJoy = true : m_jbutton.aJoy = false;
    sf::Joystick::isButtonPressed(0,1) ? m_jbutton.bJoy = true : m_jbutton.bJoy = false;
    sf::Joystick::isButtonPressed(0,2) ? m_jbutton.xJoy = true : m_jbutton.xJoy = false;
    sf::Joystick::isButtonPressed(0,3) ? m_jbutton.yJoy = true : m_jbutton.yJoy = false;
    sf::Joystick::isButtonPressed(0,4) ? m_jbutton.lJoy = true : m_jbutton.lJoy = false;
    sf::Joystick::isButtonPressed(0,5) ? m_jbutton.rJoy = true : m_jbutton.rJoy = false;
    sf::Joystick::isButtonPressed(0,6) ? m_jbutton.selectJoy = true : m_jbutton.selectJoy = false;
    sf::Joystick::isButtonPressed(0,7) ? m_jbutton.startJoy = true : m_jbutton.startJoy = false;

    m_jbutton.joy1.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    m_jbutton.joy1.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

    m_jbutton.joy2.x = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
    m_jbutton.joy2.y = sf::Joystick::getAxisPosition(0, sf::Joystick::R);

}
