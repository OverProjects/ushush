#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "perso.hpp"
#include "skill.hpp"

sf::Vector2f colli(int x, int y, sf::RenderWindow& window)
{
    sf::Vector2f off;
    off.x = x; off.y = y;

    if (x < 0) {off.x = 0;}
    else if ((unsigned)x > window.getSize().x) {off.x = window.getSize().x;}

    if (y < 0) {off.y = 0;}
    else if ((unsigned)y > window.getSize().y) {off.y = window.getSize().y;}

    return off;
}

Perso::Perso(std::string str)
{
    m_cloLeftMouse.restart();
    m_clo.restart();
    m_tim = m_clo.getElapsedTime();

    m_tex.loadFromFile(str);
    m_spri.setTexture(m_tex);
    m_spri.setPosition(100, 100);

    m_cont.setPrimitiveType(sf::LinesStrip);
    m_cont.resize(5);

    for (int unsigned i = 0; i < m_cont.getVertexCount(); i++)
        {m_cont[i].color = sf::Color::Blue;}

    m_scal.x = 1; m_scal.y = 1;
       m_rotat = 0;

    m_spri.setOrigin(m_spri.getGlobalBounds().width / 2, m_spri.getGlobalBounds().height / 2);

    m_shape.setFillColor(sf::Color::Blue);
    m_shape.setRadius(5);
    m_shape.setOrigin(m_shape.getGlobalBounds().width / 2, m_shape.getGlobalBounds().height / 2);
    m_shape.setPosition(m_spri.getOrigin().x + m_spri.getGlobalBounds().left,
                          m_spri.getOrigin().y + m_spri.getGlobalBounds().top);
    m_showCont = true;
    m_showCent = true;
    m_showSpri = true;

    m_mousePosition = sf::Mouse::getPosition();

    m_toMouse.x = m_spri.getPosition().x - m_mousePosition.x;
    m_toMouse.y = m_spri.getPosition().y - m_mousePosition.y;

    m_lin.setPrimitiveType(sf::Lines);
    m_lin.resize(2);
    m_lin[0].color = sf::Color::Green; m_lin[1].color = sf::Color::Green;
    }

void Perso::update(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {this->setSscale(1, window);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {this->setSscale(0, window);}

    m_tim = m_cloLeftMouse.getElapsedTime();
    if (m_tim.asMilliseconds() > 100)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {this->createObject();}
        m_cloLeftMouse.restart();
    }

    // Ici commence la rotat

    m_mousePosition = sf::Mouse::getPosition(window);

    m_toMouse.x = m_spri.getPosition().x - m_mousePosition.x;
    m_toMouse.y = m_spri.getPosition().y - m_mousePosition.y;

    m_rotat = (atan2(m_toMouse.y, m_toMouse.x)) * 180 / PI;
    m_spri.setRotation(m_rotat);

    // Ici fini la rotat

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {m_spri.move(0, 0 - 10);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {m_spri.move(0, 10);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {m_spri.move(0 - 10, 0);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {m_spri.move(10, 0);}

    m_spri.setPosition(colli(m_spri.getPosition().x, m_spri.getPosition().y, window));

    m_tim = m_clo.getElapsedTime();

    m_cont[0].position = sf::Vector2f(m_spri.getGlobalBounds().left,
                                   m_spri.getGlobalBounds().top);
    m_cont[1].position = sf::Vector2f(m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width,
                                   m_spri.getGlobalBounds().top);
    m_cont[2].position = sf::Vector2f(m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width,
                                   m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height);
    m_cont[3].position = sf::Vector2f(m_spri.getGlobalBounds().left,
                                   m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height);
    m_cont[4].position = sf::Vector2f(m_spri.getGlobalBounds().left,
                                   m_spri.getGlobalBounds().top);

    m_lin[0].position = sf::Vector2f(m_spri.getPosition().x, m_spri.getPosition().y);
    m_lin[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

    m_shape.setPosition(m_spri.getOrigin().x + m_spri.getGlobalBounds().left,
                      m_spri.getOrigin().y + m_spri.getGlobalBounds().top);

    for (int i = 0; i < nbObject; i++)
    {
        if (m_object[i].getUsed()) {m_object[i].update(window);}
    }
}

void Perso::show(sf::RenderWindow& window)
{
    if (m_showSpri) {window.draw(m_spri);}
    if (m_showCont) {window.draw(m_cont);}
    if (m_showCent) {window.draw(m_shape);}
    window.draw(m_lin);

    for (int i = 0; i < nbObject; i++)
    {
        if (m_object[i].getUsed()) {m_object[i].show(window);}
    }
}

void Perso::setSscale(bool x, sf::RenderWindow& window)
{
    if (x) {m_spri.scale(1.1, 1.1); if (m_spri.getScale().x > 2) {m_spri.setScale(2, 2);};}
    else {m_spri.scale(0.9, 0.9); if (m_spri.getScale().x < 0.1) {m_spri.setScale(0.1,0.1);};}

}

void Perso::setShow(bool sprite, bool contour, bool center, bool lin)
{
    m_showSpri = sprite;
    m_showCont = contour;
    m_showCent = center;
    m_showLin = lin;
}

void Perso::createObject()
{
    int i{0};

    while (m_object[i].getUsed()) {if (i < nbObject) {i++;};}

    if (i < nbObject)
        {m_object[i].init(5, 2000, m_toMouse , 1, m_spri.getPosition());}
    else {std::cout << "i  = " << i << std::endl;}
}
