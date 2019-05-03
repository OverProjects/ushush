#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


#include "Display.hpp"

bool Display::init(std::string str, int what)
{
    m_clo.restart();
    m_tim = m_clo.getElapsedTime();
    m_timInt = m_tim.asSeconds();

    if (!what) // Sprite
    {
        if (!m_texture.loadFromFile(str))
            {std::cerr << "no load for " << str << std::endl; return false;}
        m_sprite.setTexture(m_texture);

        m_size.x = m_sprite.getLocalBounds().width;
        m_size.y = m_sprite.getLocalBounds().height;
        m_what = what;
    }

    else if (what) // Texte
    {
        if (!m_fon.loadFromFile("GFX/font/arial.ttf"))
            {std::cerr << "Can't load Arial" << std::endl; return false;}
        m_tex.setFont(m_fon);
        m_tex.setString(str);
        m_tex.setCharacterSize(24);
        m_tex.setFillColor(sf::Color::Red);
        m_what = what;
    }
}

void Display::update(int what)
{
    m_tim = m_clo.getElapsedTime();
    m_timInt = m_tim.asSeconds();

    if (what == 3) // Texte time
    {
        m_tex.setString(std::to_string(m_timInt));
    }
}

void Display::show(sf::RenderWindow &window)
{
    if (!m_what) {window.draw(m_sprite);} // Sprite
    if (m_what) {window.draw(m_tex);} // Texte
}

void Display::setSpriteScale(int x, int y, sf::RenderWindow& window)
{
    m_sprite.setScale((window.getSize().x / x) / m_sprite.getLocalBounds().width,
                       (window.getSize().y / y) / m_sprite.getLocalBounds().height);
    m_size.x = m_sprite.getLocalBounds().width;
    m_size.y = m_sprite.getLocalBounds().height;
}
