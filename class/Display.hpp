#ifndef DEF_DIS
#define DEF_DIS

class Display
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    sf::Vector2i m_size;

    sf::Clock m_clo;
    sf::Time m_tim;

    int m_timInt;

    sf::Font m_fon;
    sf::Text m_tex;

public :
    bool init(std::string);
    void update();
    void show(sf::RenderWindow&);

    void setPosition(int x, int y) {m_sprite.setPosition(x, y);}

    sf::Vector2i getSize() {return m_size;}
};

#endif
