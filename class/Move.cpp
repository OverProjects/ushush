#include <iostream>
#include <SFML/Graphics.hpp>

#include "Move.hpp"


Mov::Mov(sf::RenderWindow& window)
{
    m_screenSize.x = window.getSize().x;
    m_screenSize.y = window.getSize().y;
    m_direction = DROITE;
    m_sprite.setPosition(window.getSize().x, window.getSize().y);
}

void Mov::update(std::string str)
{
    if (str == "Ligne")
    {
        switch(m_direction)
        {
            case DROITE : m_sprite.setPosition(m_sprite.getPosition().x + 1, m_sprite.getPosition().y);
                if (m_sprite.getPosition().x > m_screenSize.x)
                    {m_sprite.setPosition(m_screenSize.x, m_sprite.getPosition().y); m_direction = GAUCHE;}
                break;
            case GAUCHE : m_sprite.setPosition(m_sprite.getPosition().x - 1, m_sprite.getPosition().y);
                if (m_sprite.getPosition().x < 0)
                    {m_sprite.setPosition(0, m_sprite.getPosition().y); m_direction = DROITE;}
            default : break;
        }
    }
}
