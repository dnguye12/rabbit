#include <stdexcept>

#include "menu.hpp"
#include "jeu.hpp"
#include "tilemap.hpp"

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

void Menu::MainMenu()
{
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
                    switch(menu.getPressesd())
                    {
                    case 0:{
                        window.close();
                        bool wait = true;

                        srand(time(0));
                        Clock clk;
                        clk.restart();
                        const float update_delay = 0.01;

                        int cell_size;
                        string tile_name;
                        if(TAILLEGRILLE <= 20)
                        {
                            cell_size = 20;
                            tile_name = "tile20.png";
                        }
                        else if(TAILLEGRILLE > 20 and TAILLEGRILLE <= 70)
                        {
                            cell_size = 10;
                            tile_name = "tile10.png";
                        }
                        else
                        {
                            cell_size = 5;
                            tile_name = "tile5.png";
                        }

                        Jeu j{};
                        sf::RenderWindow window1(sf::VideoMode(TAILLEGRILLE * cell_size, TAILLEGRILLE * cell_size), "Simulation Display");

                        int level[TAILLEGRILLE * TAILLEGRILLE];
                        for(int l = 0; l < TAILLEGRILLE; l++)
                        {
                            for(int c = 0; c < TAILLEGRILLE; c++)
                            {
                                Coord co {l, c};
                                Animal a = j.jGri.getAnimal(co);
                                if(a.getEspece() == Espece::lapin)
                                {
                                    level[co.toInt()] = 1;
                                }
                                else if (a.getEspece() == Espece::renard)
                                {
                                    level[co.toInt()] = 2;
                                }
                                else
                                {
                                    level[co.toInt()] = 0;
                                }
                            }
                        }
                        TileMap map;
                        if (!map.load(tile_name, sf::Vector2u(cell_size, cell_size), level, TAILLEGRILLE, TAILLEGRILLE))
                            throw invalid_argument("tile not found");

                        while (window1.isOpen())
                        {
                            sf::Event e;
                            while (window1.pollEvent(e))
                            {
                                if(e.type == sf::Event::Closed or e.key.code == Keyboard::Escape)
                                    window1.close();
                                if(e.type == Event::KeyReleased and e.key.code == Keyboard::Space)
                                {
                                    wait = !wait;
                                }
                            }
                            if (clk.getElapsedTime().asSeconds() > update_delay && !wait)
                            {
                                j.deplace();
                                for(int l = 0; l < TAILLEGRILLE; l++)
                                {
                                    for(int c = 0; c < TAILLEGRILLE; c++)
                                    {
                                        Coord co {l, c};
                                        Animal a = j.jGri.getAnimal(co);
                                        if(a.getEspece() == Espece::lapin)
                                        {
                                            level[co.toInt()] = 1;
                                        }
                                        else if (a.getEspece() == Espece::renard)
                                        {
                                            level[co.toInt()] = 2;
                                        }
                                        else
                                        {
                                            level[co.toInt()] = 0;
                                        }
                                    }
                                }
                                map.load(tile_name, sf::Vector2u(cell_size, cell_size), level, TAILLEGRILLE, TAILLEGRILLE);
                                clk.restart();
                            }

                            window1.clear();
                            window1.draw(map);
                            window1.display();


                        }


                        break;}
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
