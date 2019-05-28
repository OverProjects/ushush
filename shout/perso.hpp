#ifndef DEF_PERSO
#define DEF_PERSO

#include "skill.hpp"
#include "mapping.hpp"

const float PI = 3.14159265;
const int nbObject = 200;

int lauchTest();
sf::Vector2f colli(int, int, sf::RenderWindow&);

class Perso
{
private :

    sf::Vector2f m_vel;
    float m_modulVel;

    float m_ratio;
    float m_speed;

    sf::Vector2i m_vUnit;
    float m_modulUnit;

    sf::Clock m_clo;
    sf::Clock m_cloLeftMouse;
    sf::Time m_tim;

    sf::VertexArray m_cont;
    sf::VertexArray m_lin;

    sf::Sprite m_spri;
    sf::Texture m_tex;

    sf::CircleShape m_shape;

    sf::Vector2f m_scal;

    sf::Vector2i m_mousePosition;
    sf::Vector2f m_toMouse;

    Object m_object[nbObject];

    int m_rotat;

    bool m_showCont;
    bool m_showSpri;
    bool m_showCent;
    bool m_showLin;

    void createObject();

    void colliMap(Mapping&);

public :

    Perso();
    Perso(std::string str);

    void update(sf::RenderWindow&, Mapping&);

    void show(sf::RenderWindow& window);

    void setSscale(bool x, sf::RenderWindow& window);

    void setShow(bool sprite, bool contour, bool center, bool lin);
};

#endif // DEF_TEST
