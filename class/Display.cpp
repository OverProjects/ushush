#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


#include "Display.hpp"

bool Display::init(std::string str, int what, sf::RenderWindow &window)
{
    m_clo.restart();
    m_tim = m_clo.getElapsedTime();
    m_timInt = m_tim.asSeconds();

    m_ScreenSize.x = window.getSize().x;
    m_ScreenSize.y = window.getSize().y;

    if (!what) // Sprite
    {
        if (!m_texture.loadFromFile(str))
            {std::cerr << "no load for " << str << std::endl; return false;}
        m_sprite.setTexture(m_texture);

        m_size.x = m_sprite.getLocalBounds().width;
        m_size.y = m_sprite.getLocalBounds().height;

        m_what = what;

        m_cont.setPrimitiveType(sf::LinesStrip);
        m_cont.resize(5);
        for (int unsigned i = 0; i < m_cont.getVertexCount(); i++)
            {m_cont[i].color = sf::Color::Blue;}

        m_scal.x = 1; m_scal.y = 1;

        m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

        m_cent.setFillColor(sf::Color::Blue);
        m_cent.setRadius(5);
        m_cent.setOrigin(m_cent.getGlobalBounds().width / 2, m_cent.getGlobalBounds().height / 2);
        m_cent.setPosition(m_sprite.getOrigin().x + m_sprite.getGlobalBounds().left,
                            m_sprite.getOrigin().y + m_sprite.getGlobalBounds().top);

        m_showCont = true;
        m_showCent = true;
        m_showSpri = true;

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
    return true;
}

void Display::update(int what)
{
    m_tim = m_clo.getElapsedTime();
    m_timInt = m_tim.asMilliseconds();

    m_cont[0].position = sf::Vector2f(m_sprite.getGlobalBounds().left,
                                    m_sprite.getGlobalBounds().top);
    m_cont[1].position = sf::Vector2f(m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width,
                                    m_sprite.getGlobalBounds().top);
    m_cont[2].position = sf::Vector2f(m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width,
                                    m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height);
    m_cont[3].position = sf::Vector2f(m_sprite.getGlobalBounds().left,
                                    m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height);
    m_cont[0].position = sf::Vector2f(m_sprite.getGlobalBounds().left,
                                    m_sprite.getGlobalBounds().top);

    m_cent.setPosition(m_sprite.getOrigin().x + m_sprite.getGlobalBounds().left,
                        m_sprite.getOrigin().y + m_sprite.getGlobalBounds().top);

    if (what == 3) // Texte time in seconds
    {
        m_timInt = m_tim.asSeconds();
        m_tex.setString(std::to_string(m_timInt));
    }

    if (what == 4) // Texte time in ms
    {
        m_tex.setString(std::to_string(m_timInt));
    }
}

void Display::show(sf::RenderWindow &window)
{
    if (!m_what)
    {
        if (m_showSpri) {window.draw(m_sprite);}
        if (m_showCent) {window.draw(m_cent);}
        if (m_showCont) {window.draw(m_cont);}
    } // Sprite
    if (m_what) {window.draw(m_tex);} // Texte
}

void Display::setSpriteScale(int x, int y, sf::RenderWindow& window)
{
    m_sprite.setScale((window.getSize().x / x) / m_sprite.getLocalBounds().width,
                       (window.getSize().y / y) / m_sprite.getLocalBounds().height);
    m_size.x = m_sprite.getLocalBounds().width;
    m_size.y = m_sprite.getLocalBounds().height;
}

void Display::setShow(bool sprite, bool contour, bool center)
{
    m_showSpri = sprite;
    m_showCent = center;
    m_showCont = contour;
}

