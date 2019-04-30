#ifndef DEF_RAND
#define DEF_RAND

class Randoma
{
public :
    Randoma();
    int genRand(int, int);
    int genEzRand(int); //créé des pattern mais c'est deja pas mal

    void update();

private :

    sf::Clock m_clo;
    sf::Time m_tim;

    int aNumber;
    std::vector<int> period;
    int incre;

    int m_nbPeriod;
};

#endif
