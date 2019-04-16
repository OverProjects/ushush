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
    bool init(std::string, bool);

    void update();
    void update(std::string str) {m_tex.setString(str);}

    void show(sf::RenderWindow&);

    void setPosition(int x, int y) {m_sprite.setPosition(x, y);}
    void setTPosition(int x, int y) {m_tex.setPosition(x, y);}

    sf::Vector2i getSize() {return m_size;}
};

#endif
