#ifndef DEF_DIS
#define DEF_DIS

class Display
{
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public :
    bool init(std::string);
    void show(sf::RenderWindow&);
};
