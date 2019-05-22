#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "mapping.hpp"

Mapping::Mapping()
{
    for(int i = 0; i < maxBlocks; i++)
    {
        m_blocks[i].width = 9999;
        m_blocks[i].height = 9999;
        m_blocks[i].left = 9999;
        m_blocks[i].top = 9999;

        m_cont[i].setPrimitiveType(sf::LineStrip);
        m_cont[i].resize(5);
        for (int j = 0; j < 5; j++)
        {
            m_cont[i][j].color = sf::Color::Blue;
            if (j == 0 || j == 4) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left,
                                                            m_blocks[i].top);}
            if (j == 1) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left + m_blocks[i].width,
                                                            m_blocks[i].top);}
            if (j == 2) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left + m_blocks[i].width,
                                                            m_blocks[i].top + m_blocks[i].height);}
            if (j == 3) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left,
                                                            m_blocks[i].top + m_blocks[i].height);}

        }
    }
}

void Mapping::init(std::string path, float level)
{
        for(int i = 0; i < maxBlocks; i++)
    {
        m_blocks[i].width = 9999;
        m_blocks[i].height = 9999;
        m_blocks[i].left = 9999;
        m_blocks[i].top = 9999;
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
                myFile >> m_blocks[i].width >> m_blocks[i].height >> m_blocks[i].left >> m_blocks[i].top;
                std::cout << m_blocks[i].width << " | " << m_blocks[i].height <<  std::endl;
                for (int j = 0; j < 5; j++)
                {
                    if (j == 0 || j == 4) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left,
                                                                    m_blocks[i].top);}
                    if (j == 1) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left + m_blocks[i].width,
                                                                    m_blocks[i].top);}
                    if (j == 2) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left + m_blocks[i].width,
                                                                    m_blocks[i].top + m_blocks[i].height);}
                    if (j == 3) {m_cont[i][j].position = sf::Vector2f(m_blocks[i].left,
                                                                    m_blocks[i].top + m_blocks[i].height);}
                }

                if (m_blocks[i].width == 9999) {i = maxBlocks;}
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
        if (m_blocks[i].width != 9999) {window.draw(m_cont[i]);}
    }
}
