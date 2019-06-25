#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "mapping.hpp"

Mapping::Mapping()
{
    for(int i = 0; i < maxBlocks; i++)
    {
        this->toDefault(i);

        m_cont[i].setPrimitiveType(sf::LineStrip);
        m_cont[i].resize(5);
        for (int j = 0; j < 5; j++)
        {
            m_cont[i][j].color = sf::Color::Blue;
            if (j == 0 || j == 4) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left,
                                                            m_blocks[i].block.top);}
            if (j == 1) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left + m_blocks[i].block.width,
                                                            m_blocks[i].block.top);}
            if (j == 2) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left + m_blocks[i].block.width,
                                                            m_blocks[i].block.top + m_blocks[i].block.height);}
            if (j == 3) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left,
                                                            m_blocks[i].block.top + m_blocks[i].block.height);}

        }
    }

    if (!m_text[0].loadFromFile("GFX/shout/texture/crate.png")) {std::cerr << "no file for crate" << std::endl;}


    m_OPosition.x = 500;
    m_OPosition.y = 500;
}

void Mapping::init(std::string path, float level)
{
    for (int i = 0; i < maxBlocks; i++)
    {
        this->toDefault(i);
    }

    std::ifstream myFile;
    myFile.open(path);

    std::string theMap = "MAP";
    theMap += std::to_string(level);

    std::cout << theMap << std::endl;

    std::string reading;

    bool endSuccess = false;

    while (getline(myFile, reading))
    {
        if (reading == theMap)
        {
            endSuccess = true;
            for (int i = 0; i < maxBlocks; i++)
            {
                myFile >> m_blocks[i].block.width >> m_blocks[i].block.height >> m_blocks[i].block.left >> m_blocks[i].block.top >> m_blocks[i].blockType;
                m_blocks[i].used = true; m_blocks[i].display = true;

                if (i == 0) {m_OPosition.x = m_blocks[i].block.left; m_OPosition.y = m_blocks[i].block.top;
                            this->toDefault(i);}

                if (m_blocks[i].block.width == 9999 && i != 0) {i = maxBlocks;}
                else
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (j == 0 || j == 4) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left,
                                                                        m_blocks[i].block.top);}
                        if (j == 1) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left + m_blocks[i].block.width,
                                                                        m_blocks[i].block.top);}
                        if (j == 2) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left + m_blocks[i].block.width,
                                                                        m_blocks[i].block.top + m_blocks[i].block.height);}
                        if (j == 3) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].block.left,
                                                                        m_blocks[i].block.top + m_blocks[i].block.height);}
                    }
                    m_blocks[i].spri.setTexture(m_text[m_blocks[i].blockType]);
                    m_blocks[i].spri.setPosition(m_blocks[i].block.left, m_blocks[i].block.top);
                    m_blocks[i].spri.setScale(m_blocks[i].block.width / m_blocks[i].spri.getGlobalBounds().width,
                                              m_blocks[i].block.height / m_blocks[i].spri.getGlobalBounds().height);
                }
            }
        }
    }

    if (!endSuccess) {std::cerr << "no map found" << std::endl;}

    myFile.close();
}

void Mapping::show(sf::RenderWindow &window)
{
    for (int i = 0; i < maxBlocks; i++)
    {
        if (m_blocks[i].used && m_blocks[i].display)
        {
            window.draw(m_blocks[i].spri);
            //window.draw(m_cont[i]);
        }
    }
}

void Mapping::toDefault(int i)
{
    m_blocks[i].block.width = 9999;
    m_blocks[i].block.height = 9999;
    m_blocks[i].block.top = 9999;
    m_blocks[i].block.left = 9999;

    m_blocks[i].used = false;
    m_blocks[i].display = false;
}
