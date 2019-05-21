#ifndef DEF_SHOU
#define DEF_SHOU

#include <cmath>

const float PI = 3.14159265;

int lauchShoot();

class Perso : public Display
{
private :

    sf::Vector2i m_vel;
    sf::Vector2i m_latMove;

    sf::Vector2i m_mousePosition;
    sf::Vector2i m_toMouse;
    sf::VertexArray m_lin;

    bool m_showLin;

    int m_rotat;

    void colli()
    {
        if (m_sprite.getPosition().x + (m_latMove.x * m_vel.x) < 0) // à gauche
            {m_vel.x = 0; m_sprite.setPosition(0, m_sprite.getPosition().y);}

        if (m_sprite.getPosition().x + m_sprite.getGlobalBounds().width + (m_latMove.x * m_vel.x) > m_ScreenSize.x) // à droite
            {m_vel.x = 0; m_sprite.setPosition(m_ScreenSize.x - m_sprite.getGlobalBounds().width, m_sprite.getPosition().y);}

        if (m_sprite.getPosition().y + (m_latMove.y * m_vel.y) < 0) // en haut
            {m_vel.y = 0; m_sprite.setPosition(m_sprite.getPosition().x, 0);}

        if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height + (m_latMove.y * m_vel.y) > m_ScreenSize.y) // en, bas
            {m_vel.y = 0; m_sprite.setPosition(m_sprite.getPosition().x, m_ScreenSize.y - m_sprite.getGlobalBounds().height);}
    }

public :

    void sayYes() {std::cout << "Yes" << std::endl;}

    Perso();
    Perso(std::string str, sf::RenderWindow &window)
    {
        m_clo.restart();
        m_tim = m_clo.getElapsedTime();
        m_timInt = m_tim.asSeconds();

        m_ScreenSize.x = window.getSize().x;
        m_ScreenSize.y = window.getSize().y;

        if (!m_texture.loadFromFile(str))
            {std::cerr << "no load for " << str << std::endl;}
        m_sprite.setTexture(m_texture);

        m_what = 0;

        m_cont.setPrimitiveType(sf::LinesStrip);
        m_cont.resize(5);
        for (int unsigned i = 0; i < m_cont.getVertexCount(); i++)
            {m_cont[i].color = sf::Color::Blue;}

        m_scal.x = 1; m_scal.y = 1;
        m_rotat = 0;

        m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

        m_cent.setFillColor(sf::Color::Blue);
        m_cent.setRadius(5);
        m_cent.setOrigin(m_cent.getGlobalBounds().width / 2, m_cent.getGlobalBounds().height / 2);
        m_cent.setPosition(m_sprite.getOrigin().x + m_sprite.getGlobalBounds().left,
                            m_sprite.getOrigin().y + m_sprite.getGlobalBounds().top);
        m_showCent = true;
        m_showCont = true;
        m_showLin = true;
        m_showSpri = true;

        m_mousePosition = sf::Mouse::getPosition();

        m_toMouse.x = m_sprite.getPosition().x - m_mousePosition.x;
        m_toMouse.y = m_sprite.getPosition().y - m_mousePosition.y;

        m_lin.setPrimitiveType(sf::Lines);
        m_lin.resize(2);
        m_lin[0].color = sf::Color::Blue; m_lin[1].color = sf::Color::Blue;
    }

    void update(sf::RenderWindow& window)
    {
        m_vel.x = 0; m_vel.y = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {m_vel.x--;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {m_vel.x++;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {m_vel.y--;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {m_vel.y++;}
        colli();
        // rotat
        m_mousePosition = sf::Mouse::getPosition(window);

        m_toMouse.x = m_sprite.getPosition().x - m_mousePosition.x;
        m_toMouse.y = m_sprite.getPosition().y - m_mousePosition.y;

        m_rotat = (atan2(m_toMouse.y, m_toMouse.x)) * 180 / PI;
        // rotat fini

        m_tim = m_clo.getElapsedTime();

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

        m_lin[0].position = sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y);
        m_lin[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        m_cent.setPosition(m_sprite.getOrigin().x + m_sprite.getGlobalBounds().left,
                            m_sprite.getOrigin().y + m_sprite.getGlobalBounds().top);
    }

    void show(sf::RenderWindow &window)
    {
        m_latMove.x = window.getSize().x / 60; m_latMove.y = window.getSize().y / 40;
        //m_sprite.setPosition(0,0);
        m_sprite.setPosition(m_sprite.getPosition().x + (m_vel.x * m_latMove.x), m_sprite.getPosition().y + (m_vel.y * m_latMove.y));

        if (m_showSpri) {window.draw(m_sprite);}
        if (m_showCent) {window.draw(m_cent);}
        if (m_showCont) {window.draw(m_cont);}
        if (m_showLin) {window.draw(m_lin);}
    }

    void setShow(bool sprite, bool contour, bool center, bool line)
    {
        m_showSpri = sprite;
        m_showCent = center;
        m_showCont = contour;
        m_showLin = line;
    }

};

class Mob : public Display
{
private :

public :

};

class Mouse : public Display
{
private :

public :

    void sayYes () {std::cout << "j'ai dis oui";}

    bool init(std::string str, sf::RenderWindow& window)
    {
        m_clo.restart();
        m_tim = m_clo.getElapsedTime();
        m_timInt = m_tim.asSeconds();

        m_ScreenSize.x = window.getSize().x;
        m_ScreenSize.y = window.getSize().y;

        if (!m_texture.loadFromFile(str))
            {std::cerr << "no load for " << str << std::endl; return false;}
        m_sprite.setTexture(m_texture);

        m_size.x = m_sprite.getLocalBounds().width;
        m_size.y = m_sprite.getLocalBounds().height;
        m_what = 0;

        m_sprite.setTextureRect(sf::IntRect(5,5,65,60));
        setSpriteScale(35, 25, window);

        return true;
    }

    void update(sf::RenderWindow &window)
    {
        m_sprite.setPosition(sf::Mouse::getPosition(window).x - m_sprite.getGlobalBounds().width / 2,
            sf::Mouse::getPosition(window).y - m_sprite.getGlobalBounds().height / 2);
    }

};

#endif // DEF_SHOU
