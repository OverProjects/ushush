#ifndef DEF_TEST
#define DEF_TEST

#include <cmath>

const float PI = 3.14159265;

int lauchTest();

class Perso
{
private :

    sf::Clock m_clo;
    sf::Time m_tim;

    sf::VertexArray m_cont;
    sf::VertexArray m_lin;

    sf::Sprite m_spri;
    sf::Texture m_tex;

    sf::CircleShape m_shape;

    sf::Vector2f m_scal;

    sf::Vector2i m_mousePosition;
    sf::Vector2f m_toMouse;

    int m_rotat;

    bool m_showCont;
    bool m_showSpri;
    bool m_showCent;
    bool m_showLin;

public :

    Perso();
    Perso(std::string str)
    {
        m_clo.restart();
        m_tim = m_clo.getElapsedTime();

        m_tex.loadFromFile(str);
        m_spri.setTexture(m_tex);
        m_spri.setPosition(100, 100);

        m_cont.setPrimitiveType(sf::LinesStrip);
        m_cont.resize(5);

        for (int unsigned i = 0; i < m_cont.getVertexCount(); i++)
            {m_cont[i].color = sf::Color::Blue;}

        m_scal.x = 1; m_scal.y = 1;
        m_rotat = 0;

        m_spri.setOrigin(m_spri.getGlobalBounds().width / 2, m_spri.getGlobalBounds().height / 2);

        m_shape.setFillColor(sf::Color::Blue);
        m_shape.setRadius(5);
        m_shape.setOrigin(m_shape.getGlobalBounds().width / 2, m_shape.getGlobalBounds().height / 2);
        m_shape.setPosition(m_spri.getOrigin().x + m_spri.getGlobalBounds().left,
                          m_spri.getOrigin().y + m_spri.getGlobalBounds().top);
        m_showCont = true;
        m_showCent = true;
        m_showSpri = true;

        m_mousePosition = sf::Mouse::getPosition();

        m_toMouse.x = m_spri.getPosition().x - m_mousePosition.x;
        m_toMouse.y = m_spri.getPosition().y - m_mousePosition.y;

        m_lin.setPrimitiveType(sf::Lines);
        m_lin.resize(2);
        m_lin[0].color = sf::Color::Green; m_lin[1].color = sf::Color::Green;
    }

    void update(sf::RenderWindow &window)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {this->setSscale(1, window);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {this->setSscale(0, window);}

        // Ici commence la rotat

        m_mousePosition = sf::Mouse::getPosition();

        m_toMouse.x = m_spri.getPosition().x - m_mousePosition.x;
        m_toMouse.y = m_spri.getPosition().y - m_mousePosition.y;

        m_rotat = (atan2(m_toMouse.y, m_toMouse.x)) * 180 / PI;
        m_spri.setRotation(m_rotat);

        // Ici fini la rotat

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {m_spri.move(0, 0 - 10);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {m_spri.move(0, 10);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {m_spri.move(0 - 10, 0);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {m_spri.move(10, 0);}

        m_tim = m_clo.getElapsedTime();

        m_cont[0].position = sf::Vector2f(m_spri.getGlobalBounds().left,
                                       m_spri.getGlobalBounds().top);
        m_cont[1].position = sf::Vector2f(m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width,
                                       m_spri.getGlobalBounds().top);
        m_cont[2].position = sf::Vector2f(m_spri.getGlobalBounds().left + m_spri.getGlobalBounds().width,
                                       m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height);
        m_cont[3].position = sf::Vector2f(m_spri.getGlobalBounds().left,
                                       m_spri.getGlobalBounds().top + m_spri.getGlobalBounds().height);
        m_cont[4].position = sf::Vector2f(m_spri.getGlobalBounds().left,
                                       m_spri.getGlobalBounds().top);

        m_lin[0].position = sf::Vector2f(m_spri.getPosition().x, m_spri.getPosition().y);
        m_lin[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        m_shape.setPosition(m_spri.getOrigin().x + m_spri.getGlobalBounds().left,
                          m_spri.getOrigin().y + m_spri.getGlobalBounds().top);
    }

    void show(sf::RenderWindow& window)
    {
        if (m_showSpri) {window.draw(m_spri);}
        if (m_showCont) {window.draw(m_cont);}
        if (m_showCent) {window.draw(m_shape);}
        window.draw(m_lin);
    }

    void setSscale(bool x, sf::RenderWindow& window)
    {
        if (x) {m_spri.scale(1.1, 1.1); if (m_spri.getScale().x > 2) {m_spri.setScale(2, 2);};}
        else {m_spri.scale(0.9, 0.9); if (m_spri.getScale().x < 0.1) {m_spri.setScale(0.1,0.1);};}

    }

    void setShow(bool sprite, bool contour, bool center, bool lin)
    {
        m_showSpri = sprite;
        m_showCont = contour;
        m_showCent = center;
        m_showLin = lin;
    }
};

#endif // DEF_TEST
