#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


#include "Display.hpp"

bool Display::init(std::string path)
{
    if (!m_texture.loadFromFile(path)) {std::cerr << "no load for " << path << std::endl;
                                        return false;}
    m_sprite.setTexture(m_texture);

    m_size.x = m_sprite.getGlobalBounds().width;
    m_size.y = m_sprite.getGlobalBounds().height;

    m_clo.restart();

    if (!m_fon.loadFromFile("GFX/font/arial.ttf"))
        {std::cerr << "Can't load Arial" << std::endl;}
    else
    {
        m_tex.setFont(m_fon);
        m_tex.setString("manger");
        m_tex.setCharacterSize(24);
        m_tex.setFillColor(sf::Color::Red);
    }

    return true;
}

bool Display::init(std::string str, bool texte)
{
    if (!m_fon.loadFromFile("GFX/font/arial.ttf"))
        {std::cerr << "Can't load Arial" << std::endl;}
    else
    {
        m_tex.setFont(m_fon);
        m_tex.setString("manger");
        m_tex.setCharacterSize(24);
        m_tex.setFillColor(sf::Color::Red);
    }
}

void Display::update()
{
    m_tim = m_clo.getElapsedTime();
    m_timInt = m_tim.asSeconds();
    m_tex.setString(std::to_string(m_timInt));
}

void Display::show(sf::RenderWindow &window)
{
    window.draw(m_sprite);
    window.draw(m_tex);
}
