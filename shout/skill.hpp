#ifndef DEF_SKILL
#define DEF_SKILL

class Object
{
private :
    sf::Clock m_clo;
    sf::Time m_tim;

    int m_leftTime;

    sf::CircleShape m_object;

    sf::Vector2f m_dir;
    sf::Vector2f m_vUnitaire;
    float m_speed;
    float m_ratio;

    bool m_showIt;
    bool m_used;

    void toDefault();

public :

    Object();

    void init(int radius, int leftTime, sf::Vector2f dir, float speed,
              sf::Vector2f position);

    void update(sf::RenderWindow& window);

    void show(sf::RenderWindow& window);

    bool getUsed() {return m_used;}
};

#endif // DEF_SKILL
