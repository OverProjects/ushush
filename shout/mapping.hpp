#ifndef DEF_MAP
#define DEF_MAP

const int maxBlocks = 50;

class Mapping
{
private :

    sf::Vector2f m_resetPos;

    sf::IntRect m_blocks[maxBlocks];

    sf::VertexArray m_cont[maxBlocks];

public :
    Mapping();

    void init(std::string, float);
    void show(sf::RenderWindow&);

    const int getMaxBlocks() {return maxBlocks;}
    sf::IntRect getBlock(int i) {return m_blocks[i];}
    sf::Vector2f getResetPos() {return m_resetPos;}
};

#endif // DF_MAP
