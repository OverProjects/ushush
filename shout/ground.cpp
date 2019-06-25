#include <iostream>
#include <SFML/Graphics.hpp>

#include "ground.hpp"

bool Ground::init(std::string path)
{
    if (!m_tex.loadFromFile(path)) {std::cerr << "no load for background" << std::endl;}

    else
    {
        m_spri.setTexture(m_tex);
        m_spri.setPosition(0, 0);
    }
}

void Ground::update(sf::RenderWindow& window)
{

}

void Ground::showBack(sf::RenderWindow& window)
{
    window.draw(m_spri);
}
