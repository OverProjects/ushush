#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "skill.hpp"

Object::Object()
{
    m_clo.restart();
    m_tim = m_clo.getElapsedTime();

    m_leftTime = 0;
    m_speed = 0;

    m_object.setFillColor(sf::Color::Red);
    m_object.setRadius(5);
    m_object.setPosition(0, 0);

    m_vUnitaire.x = 10;
    m_vUnitaire.y = 10;

    m_showIt = false;
    m_used = false;
}

void Object::init(int radius, int leftTime, sf::Vector2f dir, float speed,
              sf::Vector2f position)
{
    m_clo.restart();
    m_tim = m_clo.getElapsedTime();

    m_leftTime = leftTime;

    m_dir.x = 0 - dir.x;
    m_dir.y = 0 - dir.y;

    m_speed = speed;

    m_object.setFillColor(sf::Color::Red);
    m_object.setRadius(radius);
    m_object.setPosition(position);

    m_showIt = true;
    m_used = true;
}

void Object::update(sf::RenderWindow& window)
{
    m_tim = m_clo.getElapsedTime();
    if (m_tim.asMilliseconds() > m_leftTime)
        {m_showIt = false; m_used = false;}

    m_ratio = (sqrt((m_vUnitaire.x * m_vUnitaire.x) + (m_vUnitaire.y + m_vUnitaire.y)) /
                sqrt((m_dir.x * m_dir.x) + (m_dir.y * m_dir.y)));

    m_object.move(m_dir * m_ratio * m_speed );
}

void Object::show(sf::RenderWindow& window)
{
    if  (m_showIt) {window.draw(m_object);}
}
