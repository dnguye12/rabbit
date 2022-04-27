#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "SFML/Graphics.hpp"

using namespace sf;

#define MENU_ITEMS 3

class Menu
{
public:
    Menu(float w, float h);
    ~Menu();

    void draw(RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressesd() const{
        return selectedItem;
    }

    void MainMenu();

private:
    int selectedItem;
    Font font;
    Text text[MENU_ITEMS];
    Texture imageSource;
};

#endif // MENU_HPP_INCLUDED
