#ifndef DEF_DIS
#define DEF_DIS

class Display
{
protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    sf::Vector2i m_size;

    sf::Clock m_clo;
    sf::Time m_tim;

    int m_timInt;

    sf::Font m_fon;
    sf::Text m_tex;

    int m_what;

public :
    bool init(std::string, int);

    void update(int);

    void show(sf::RenderWindow&);

    // SetText
    void setTString(std::string str) {m_tex.setString(str);}
    void setTSize(int tail) {m_tex.setCharacterSize(tail);}
    void setTPosition(int x, int y) {m_tex.setPosition(x, y);}
    // void setTColor(sf::Color color) {m_tex.setColor(color);} // ne marche pas??
    // end SetText

    void setPosition(int x, int y) {m_sprite.setPosition(x, y);}
    void setSpriteScale(int, int, sf::RenderWindow&);

    void setCloRestart() {m_clo.restart();}

    sf::Text getTex() {return m_tex;}
    sf::Time getTim() {return m_tim;}
    int getTimeInt() {return m_timInt;}

    sf::Vector2i getSize() {return m_size;}
};

#endif
