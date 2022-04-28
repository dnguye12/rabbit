#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

#define MENU_ITEMS 2

class Menu
{
public:
    Menu(float w, float h);
    ~Menu();

    void MainMenu();

private:
    Font font;
    Texture imageSource;
};


#endif // MENU_HPP_INCLUDED
