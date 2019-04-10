#include <iostream>

#include "Display.hpp"

bool Display::init(std::string path)
{
    if (!m_texture.loadFromFile(path)) {std::cerr << "no load for " << path << std::endl;}
    m_sprite.setTexture(m_texture);
}

void Display::show(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}
