#ifndef DEF_MAP
#define DEF_MAP

const int maxBlocks = 50;

struct Blocks
{
    sf::Sprite spri;
    sf::IntRect block;
    int blockType = 0;
    bool used = false;
    bool display = false;
};

class Mapping
{
private :

    sf::Texture m_text[10];

    Blocks m_blocks[maxBlocks];

    sf::VertexArray m_cont[maxBlocks];

    sf::Vector2i m_OPosition;

    void toDefault(int);

public :
    Mapping();

    void init(std::string, float);
    void show(sf::RenderWindow&);

    const int getMaxBlocks() {return maxBlocks;}
    sf::IntRect getBlock(int i) {return m_blocks[i].block;}
    sf::Vector2i getResetPos() {return m_OPosition;}
};

#endif // DF_MAP
