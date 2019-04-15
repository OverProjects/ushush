#include <iostream>
#include <SFML/Graphics.hpp>


#include "Display.hpp"

bool Display::init(std::string path)
{
    if (!m_texture.loadFromFile(path)) {std::cerr << "no load for " << path << std::endl;
                                        return false;}
    m_sprite.setTexture(m_texture);

    m_size.x = m_sprite.getGlobalBounds().width;
    m_size.y = m_sprite.getGlobalBounds().height;

    return true;
}

void Display::show(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}
