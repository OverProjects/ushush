#ifndef DEF_DIS
#define DEF_DIS

class Display
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    sf::Vector2i m_size;

public :
    bool init(std::string);
    void show(sf::RenderWindow&);

    sf::Vector2i getSize() {return m_size;}
};

#endif
