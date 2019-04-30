#ifndef DEF_MOV
#define DEF_MOV

#include "Display.hpp"


enum{DROITE, GAUCHE, HAUT, BAS};

class Mov : public Display
{
protected :
    int m_direction;
    sf::Vector2i m_screenSize;

public :
    Mov(sf::RenderWindow& window);
    virtual void update(std::string str);
};

#endif // DEF_MOV
