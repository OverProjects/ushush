#ifndef DEF_SHOU
#define DEF_SHOU

int lauchShoot();

class Perso : public Display
{
private :

    sf::Vector2i m_vel;

    void colli()
    {
        if (m_sprite.getPosition().x < 0 && m_vel.x < 0) {m_vel.x = 0;}
    }

public :
    void sayYes() {std::cout << "Yes" << std::endl;}

    void update(Input in)
    {
        m_vel.x = 0; m_vel.y = 0;
        if (in.getButton().leftBut)
        {
            m_vel.x--;
        }
        colli();
    }

    void show(sf::RenderWindow &window)
    {
        m_sprite.setPosition(m_sprite.getPosition().x + m_vel.x, m_sprite.getPosition().y + m_vel.y);
        window.draw(m_sprite);
    }

};

class Mob : public Display
{
private :

public :

};

#endif // DEF_SHOU
