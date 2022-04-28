#include <stdexcept>

#include "menu.hpp"
#include "jeu.hpp"

using namespace std;

Menu::Menu(float w, float h)
{
    if(!font.loadFromFile("Fonts/ConnectionIi-2wj8.otf"))
    {
        throw invalid_argument("Fonts not found");
    }

    text[0].setFont(font);
    text[0].setFillColor(Color::Red);
    text[0].setString("Start");
    text[0].setCharacterSize(h / 20);
    text[0].setPosition(Vector2f(w/2, h / (MENU_ITEMS + 1)* 1));

    text[1].setFont(font);
    text[1].setFillColor(Color::White);
    text[1].setString("Continue");
    text[0].setCharacterSize(h / 20);
    text[1].setPosition(Vector2f(w/2, h / (MENU_ITEMS + 1)* 2));

    text[2].setFont(font);
    text[2].setFillColor(Color::White);
    text[2].setString("Quit");
    text[0].setCharacterSize(h / 20);
    text[2].setPosition(Vector2f(w/2, h / (MENU_ITEMS + 1)* 3));

    selectedItem = 0;
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow &window)
{
    for(int i =0; i < MENU_ITEMS; i++)
    {

        window.draw(text[i]);
    }
}

void Menu::moveUp()
{
        text[selectedItem].setColor(Color::White);
        selectedItem--;
        if(selectedItem <= -1)
        {
            selectedItem = 2;
        }
        text[selectedItem].setColor(Color::Red);

}

void Menu::moveDown()
{
        text[selectedItem].setColor(Color::White);
        selectedItem++;
        if(selectedItem >= 3)
        {
            selectedItem = 0;
        }
        text[selectedItem].setColor(Color::Red);

}

void Menu::MainMenu() {
    RenderWindow window(VideoMode(600,600), "Main Menu");

    Menu menu(window.getSize().x, window.getSize().y);

    while(window.isOpen())
    {
        Event e;

        while(window.pollEvent(e))
        {
            switch(e.type)
            {
            case Event::KeyReleased:
                switch(e.key.code)
                {
                case Keyboard::Up:
                    menu.moveUp();
                    break;
                case Keyboard::Down:
                    menu.moveDown();
                    break;

                case Keyboard::Return:
                    switch(menu.getPressesd()) {
                    case 2:
                        window.close();
                        break;
                    }
                    break;
                }

                break;
            case Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();

        menu.draw(window);

        window.display();
    }
}
