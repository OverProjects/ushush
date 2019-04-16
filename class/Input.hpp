#ifndef DEF_INPUT
#define DEF_INPUT

class Input
{
    struct Button
    {
        bool leftBut, rightBut, upBut, downBut;
        bool aBut, bBut, xBut, yBut, rBut, lBut;
        bool selectbut, startBut;
    };
    struct Mouse
    {
        int mouseX, mouseY, oMouseX, oMouseY;
    };


    struct jButton
    {
        bool aJoy, bJoy, xJoy, yJoy, rJoy, lJoy;
        bool selectJoy, startJoy;
        sf::Vector2i joy1, joy2;
    };

private :
    Button m_button;
    Mouse m_mouse;
    jButton m_jbutton;

    enum{m_LEFT, m_RIGHT, m_UP, m_DOWN, m_jleft, m_jright, m_jup, m_jdown};

public :
    Input() {m_button = {false}; m_mouse = {0};}
    Button getButton() const {return m_button;}
    Mouse getMouse() const {return m_mouse;}
    jButton getJButton() const {return m_jbutton;}

    void setButton(int button, bool state);

    void handleInputs(sf::RenderWindow &window);
};

#endif // DEF_INPUT


