#ifndef DEF_GROUND
#define DEF_GROUND

class Ground
{
private :
    sf::Texture m_tex;
    sf::Sprite m_spri;

public :
    bool init(std::string);
    void update(sf::RenderWindow&);
    void showBack(sf::RenderWindow&);
};

#endif // DEF_GROUND
