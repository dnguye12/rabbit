#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

#include "jeu.hpp"
#include "coord.hpp"
#include <SFML/Graphics.hpp>
#include "menu.hpp"

using namespace std;
using namespace sf;


class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

int main()
{
    Jeu j{};
    // create the window
    sf::RenderWindow window(sf::VideoMode(TAILLEGRILLE * 5, TAILLEGRILLE * 5), "Tilemap");

    // define the level with an array of tile indices
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
    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("tile.png", sf::Vector2u(5, 5), level, TAILLEGRILLE, TAILLEGRILLE))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed and event.key.code == Keyboard::Space)
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
                map.load("tile.png", sf::Vector2u(5, 5), level, TAILLEGRILLE, TAILLEGRILLE);
            }
        }

        // draw the map
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
