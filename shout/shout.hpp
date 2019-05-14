#ifndef DEF_SHOU
#define DEF_SHOU

#include <cmath>

int lauchShoot();

class Perso : public Display
{
private :

    sf::Vector2i m_vel;
    sf::Vector2i m_latMove;





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
    sf::Vector2i m_toMouse;
    sf::Vector2i m_toUp;
    sf::Vector2f m_omerde;

    void sayYes() {std::cout << "Yes" << std::endl;}

    void update(sf::RenderWindow& window)
    {
        m_vel.x = 0; m_vel.y = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {m_vel.x--;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {m_vel.x++;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {m_vel.y--;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {m_vel.y++;}
        colli();

        m_sprite.setOrigin((m_sprite.getGlobalBounds().width / 2) - 3,(m_sprite.getGlobalBounds().height / 2) + 36);

        m_toUp.x = 5;
        m_toUp.y = 0;

        m_toMouse.x = (sf::Mouse::getPosition(window).x - (m_sprite.getGlobalBounds().left + (m_sprite.getGlobalBounds().width / 2) - 3));
        m_toMouse.y = (sf::Mouse::getPosition(window).y - (m_sprite.getGlobalBounds().top + (m_sprite.getGlobalBounds().height / 2) + 36));

        m_omerde.x = (m_toMouse.x / sqrt((m_toMouse.x * m_toMouse.x) + (m_toMouse.y * m_toMouse.y)));
        m_omerde.y = (m_toMouse.y / sqrt((m_toMouse.x * m_toMouse.x) + (m_toMouse.y * m_toMouse.y)));

        m_sprite.setRotation(abs(m_omerde.x * 360)); // ca marche pas

        /*
        m_omerde.x = 360 - ((m_toUp.x * m_toMouse.x + m_toUp.y * m_toMouse.y) /
         sqrt(m_toUp.x * m_toUp.x + m_toUp.y * m_toUp.y) * sqrt(m_toMouse.x * m_toMouse.x + m_toMouse.y * m_toMouse.y));

        m_omerde.y = ((m_toUp.x * m_toMouse.x + m_toUp.y * m_toMouse.y) /
         sqrt(m_toUp.x * m_toUp.x + m_toUp.y * m_toUp.y) * sqrt(m_toMouse.x * m_toMouse.x + m_toMouse.y * m_toMouse.y));
        */
        //std::cout << m_omerde .x<< " | " << m_omerde.y << std::endl;
        //std::cout << m_toMouse.x<< " | " << m_toMouse.y << std::endl;
        /*

        if (sf::Mouse::getPosition().x < m_sprite.getPosition().x)
        {m_sprite.setRotation(360 - acos((m_toUp.x * m_toMouse.x + m_toUp.y * m_toMouse.y) /
         sqrt(m_toUp.x * m_toUp.x + m_toUp.y * m_toUp.y) * sqrt(m_toMouse.x * m_toMouse.x + m_toMouse.y * m_toMouse.y)));}

        else {m_sprite.setRotation(acos((m_toUp.x * m_toMouse.x + m_toUp.y * m_toMouse.y) /
         sqrt(m_toUp.x * m_toUp.x + m_toUp.y * m_toUp.y) * sqrt(m_toMouse.x * m_toMouse.x + m_toMouse.y * m_toMouse.y)));}
         */
    }

    void show(sf::RenderWindow &window)
    {
        m_latMove.x = window.getSize().x / 60; m_latMove.y = window.getSize().y / 40;
        //m_sprite.setPosition(0,0);
        m_sprite.setPosition(m_sprite.getPosition().x + (m_vel.x * m_latMove.x), m_sprite.getPosition().y + (m_vel.y * m_latMove.y));
        window.draw(m_sprite);
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
