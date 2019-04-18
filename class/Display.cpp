#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


#include "Display.hpp"

bool Display::init(std::string path)
{
    if (!m_texture.loadFromFile(path)) {std::cerr << "no load for " << path << std::endl;
                                        return false;}
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(0, 0);

    m_size.x = m_sprite.getGlobalBounds().width;
    m_size.y = m_sprite.getGlobalBounds().height;

    m_clo.restart();

    if (!m_fon.loadFromFile("GFX/font/arial.ttf"))
        {std::cerr << "Can't load Arial" << std::endl; return false;}
    else
    {
        m_tex.setFont(m_fon);
        m_tex.setString("manger");
        m_tex.setCharacterSize(24);
        m_tex.setFillColor(sf::Color::Red);
    }

    std::cout << path << std::endl;

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

void Display::show(sf::RenderWindow &window, bool tete)
{
    window.draw(m_sprite);
    if (tete) {window.draw(m_tex);}
}

void Display::setSpriteScale(int x, int y, sf::RenderWindow& window)
{
    m_sprite.setScale((window.getSize().x / x) / m_sprite.getLocalBounds().height,
                       (window.getSize().y / y) / m_sprite.getLocalBounds().width);
    std::cout << (window.getSize().x / x) / m_sprite.getLocalBounds().height << " | " <<
    (window.getSize().y / y) / m_sprite.getLocalBounds().width << std:: endl;
}
