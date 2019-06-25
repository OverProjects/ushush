#ifndef DEF_MAP
#define DEF_MAP

const int maxBlocks = 50;

struct Blocks
{
    sf::Sprite spri;
    sf::IntRect block;
    int blockType = 0;
};

class Mapping
{
private :

    sf::Texture m_text[10];

    sf::Vector2f m_resetPos;

    Blocks m_blocks[maxBlocks];

    sf::VertexArray m_cont[maxBlocks];

public :
    Mapping();

    void init(std::string, float);
    void show(sf::RenderWindow&);

    const int getMaxBlocks() {return maxBlocks;}
    sf::IntRect getBlock(int i) {return m_blocks[i].block;}
    sf::Vector2f getResetPos() {return m_resetPos;}
};

#endif // DF_MAP
