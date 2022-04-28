#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "jeu.hpp"
#include "menu.hpp"
#include "tilemap.hpp"

using namespace std;
using namespace sf;


int main()
{
    bool wait = true;

    srand(time(0));
    Clock clk;
    clk.restart();
    const float update_delay = 0.01;

    int cell_size;
    string tile_name;
    if(TAILLEGRILLE <= 20) {
        cell_size = 20;
        tile_name = "tile20.png";
    }else if(TAILLEGRILLE > 20 and TAILLEGRILLE <= 70) {
        cell_size = 10;
        tile_name = "tile10.png";
    }else {
        cell_size = 5;
        tile_name = "tile5.png";
    }

    Jeu j{};
    sf::RenderWindow window(sf::VideoMode(TAILLEGRILLE * cell_size, TAILLEGRILLE * cell_size), "Simulation Display");

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

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed or e.key.code == Keyboard::Escape)
                window.close();
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
        window.clear();
        window.draw(map);
        window.display();


    }


    return 0;
}
