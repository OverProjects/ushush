#ifndef DEF_MAP
#define DEF_MAP

const int maxBlocks = 50;

class Mapping
{
private :

    sf::IntRect m_blocks[maxBlocks];

    sf::VertexArray m_cont[maxBlocks];

public :
    Mapping();

    void init(std::string, float);
    void show(sf::RenderWindow&);
};

#endif // DF_MAP
