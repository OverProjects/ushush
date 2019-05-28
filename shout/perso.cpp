#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "perso.hpp"
#include "skill.hpp"
#include "mapping.hpp"

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
    m_spri.setPosition(500, 500);

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

    m_speed = 1;
    m_ratio = 1;

    m_vUnit.x = 5;
    m_vUnit.y = 5;

    m_modulUnit = sqrt((m_vUnit.x * m_vUnit.x) + (m_vUnit.y * m_vUnit.y));

    m_vel.x = 0;
    m_vel.y = 0;

    m_modulVel = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));
    }

void Perso::update(sf::RenderWindow &window, Mapping &ma)
{
    m_vel.x = 0;
    m_vel.y = 0;

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {m_vel.y--;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {m_vel.y++;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {m_vel.x--;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {m_vel.x++;}

    // Partie collision

    m_spri.setPosition(colli(m_spri.getPosition().x, m_spri.getPosition().y, window));
    m_modulVel = sqrt((m_vel.x * m_vel.x) + (m_vel.y * m_vel.y));
    if (m_vel.x != 0 || m_vel.y != 0) {colliMap(ma);}

    // Fin collision



    if (m_vel.x != 0 || m_vel.y != 0)
    {
        m_ratio = (m_modulUnit / m_modulVel);
        m_spri.move(m_vel * m_ratio * m_speed);
    }

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
    else {std::cout << "Max Objects (" << nbObject << ") = " << i << std::endl;}
}

void Perso::colliMap(Mapping& ma)
{
    bool coli{false};
    m_ratio = (m_modulUnit / m_modulVel);

    for (int i = 0; i < ma.getMaxBlocks(); i++)
    {
        if (ma.getBlock(i).left != 9999)
        {
            if (m_spri.getGlobalBounds().left + (m_vel.x * m_ratio * m_speed) >= ma.getBlock(i).left + ma.getBlock(i).width ||
                m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width + (m_vel.x * m_ratio * m_speed) <= ma.getBlock(i).left ||
                m_spri.getGlobalBounds().top + (m_vel.y * m_ratio * m_speed) >= ma.getBlock(i).top + ma.getBlock(i).height ||
                m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height + (m_vel.y * m_ratio * m_speed) <= ma.getBlock(i).top)
                {} // on essaye avec un déplacement unitaire

            else
            {
                if (m_speed == 1)
                {
                    m_speed = 0.2; coli = true;

                    if (m_spri.getGlobalBounds().left + (m_vel.x * m_ratio * m_speed) >= ma.getBlock(i).left + ma.getBlock(i).width ||
                    m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width + (m_vel.x * m_ratio * m_speed) <= ma.getBlock(i).left ||
                    m_spri.getGlobalBounds().top + (m_vel.y * m_ratio * m_speed) >= ma.getBlock(i).top + ma.getBlock(i).height ||
                    m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height + (m_vel.y * m_ratio * m_speed) <= ma.getBlock(i).top)
                    {} // avec 0.2 du déplacement unitaire

                    else
                    {
                        if (m_spri.getGlobalBounds().left >= ma.getBlock(i).left + ma.getBlock(i).width ||
                        m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width <= ma.getBlock(i).left ||
                        m_spri.getGlobalBounds().top >= ma.getBlock(i).top + ma.getBlock(i).height ||
                        m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height <= ma.getBlock(i).top)
                        {} // on regarde si on est pas stuck in wall

                        else {m_spri.setPosition(ma.getResetPos());} // dans ce cas on est stuck -> reset
                        m_vel.x = 0; m_vel.y = 0; coli = true;
                    }
                }

                else
                {
                    if (m_spri.getGlobalBounds().left >= ma.getBlock(i).left + ma.getBlock(i).width ||
                        m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width <= ma.getBlock(i).left ||
                        m_spri.getGlobalBounds().top >= ma.getBlock(i).top + ma.getBlock(i).height ||
                        m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height <= ma.getBlock(i).top)
                        {} // on regarde si on est pas stuck in wall

                    else {m_spri.setPosition(ma.getResetPos());} // dans ce cas on est stuck -> reset

                    m_vel.x = 0; m_vel.y = 0; coli = true;
                }
            }
        }
    }
    if (coli) {m_speed = 0.2;}
    else {m_speed = 1;}
}
