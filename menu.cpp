#include <stdexcept>
#include <sstream>
#include <iostream>

#include "menu.hpp"
#include "jeu.hpp"
#include "tilemap.hpp"

#include <SFML/Audio.hpp>

using namespace std;

Menu::Menu(float w, float h)
{
    if(!font.loadFromFile("Fonts/ConnectionIi-2wj8.otf"))
    {
        throw invalid_argument("Fonts not found");
    }
}

Menu::~Menu()
{

}

void Menu::MainMenu()
{
    Image icon;
    icon.loadFromFile("icon.png");
    /*Music music;
    if (!music.openFromFile("music.ogg"))
        throw invalid_argument("Music not found");
    music.setLoop(true);
    music.play();*/
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

    /*
        Texture texture;
        if(!texture.loadFromFile("logo1.png"))
        {
            throw invalid_argument("Logo not found");
        }
        Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(Vector2f(120.f, 10.f));*/

    Texture texture1;
    if(!texture1.loadFromFile("bg.jpg"))
    {
        throw invalid_argument("Background not found");
    }
    Sprite sprite1;
    sprite1.setTexture(texture1);

    Texture texture2;
    if(!texture2.loadFromFile("startbutton.png"))
    {
        throw invalid_argument("Start button not found");
    }
    Sprite start;
    start.setTexture(texture2);
    start.setPosition(Vector2f(TAILLEGRILLE * cell_size/2 - (start.getLocalBounds().width/2), (TAILLEGRILLE * cell_size + 220) / 4 - 30));

    Texture texture3;
    if(!texture3.loadFromFile("stopbutton.png"))
    {
        throw invalid_argument("Stop button not found");
    }
    Sprite stop;
    stop.setTexture(texture3);
    stop.setPosition(Vector2f(TAILLEGRILLE * cell_size/2 - (start.getLocalBounds().width/2), (TAILLEGRILLE * cell_size + 220) / 4 + 180));




    size_t gene = 0;



    Jeu j {};
    stringstream oss;
    oss << 0;
    string str = "Generation = " + oss.str();
    string str1 = "Lapin Population = " + to_string(j.lapinPop());
    string str2 = "Renard Population = " + to_string(j.renardPop());

    Text text1, text2, text3, text4;
    text1.setFont(font);
    text1.setString("| Space |: Pause/Start\n| N |: Create a new board\n| Esc |: Quit the game");
    text1.setCharacterSize(12);
    text1.setPosition(20, TAILLEGRILLE * cell_size + 25);

    text2.setFont(font);
    text2.setString(str);
    text2.setCharacterSize(12);
    text2.setPosition(TAILLEGRILLE * cell_size - 200, TAILLEGRILLE * cell_size + 25);

    text3.setFont(font);
    text3.setString(str1);
    text3.setCharacterSize(12);
    text3.setPosition(TAILLEGRILLE * cell_size - 200, TAILLEGRILLE * cell_size + 37);

    text4.setFont(font);
    text4.setString(str2);
    text4.setCharacterSize(12);
    text4.setPosition(TAILLEGRILLE * cell_size - 200, TAILLEGRILLE * cell_size + 49);

    RectangleShape cell_legend_lapin(Vector2f(cell_size,cell_size));
    const Color rabbit_color(0,255,255);
    cell_legend_lapin.setFillColor(rabbit_color);
    cell_legend_lapin.setPosition(TAILLEGRILLE * cell_size - 224, TAILLEGRILLE * cell_size + 40);

    RectangleShape cell_legend_renard(Vector2f(cell_size,cell_size));
    const Color renard_color(255,0,0);
    cell_legend_renard.setFillColor(renard_color);
    cell_legend_renard.setPosition(TAILLEGRILLE * cell_size - 224, TAILLEGRILLE * cell_size + 52);



    RenderWindow window(VideoMode(TAILLEGRILLE * cell_size,TAILLEGRILLE * cell_size + 125), "Main Menu");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Menu menu(window.getSize().x, window.getSize().y);

    while(window.isOpen())
    {
        Event e;

        while(window.pollEvent(e))
        {
            switch(e.type)
            {
            case Event::MouseButtonPressed:
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    if (stop.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        window.close();
                    }
                    if (start.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        window.close();
                        bool wait = true;

                        srand(time(0));
                        Clock clk;
                        clk.restart();
                        const float update_delay = 0.01;



                        sf::RenderWindow window1(sf::VideoMode(TAILLEGRILLE * cell_size, TAILLEGRILLE * cell_size + 100), "Simulation Display");
                        window1.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

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
                                if(e.type == Event::KeyReleased and e.key.code == Keyboard::N)
                                {
                                    j = *(new Jeu{});
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
                                    gene = 0;
                                    text2.setString(str);
                                    str1 = "Lapin Population = " + to_string(j.lapinPop());
                                    str2 = "Renard Population = " + to_string(j.renardPop());
                                    text3.setString(str1);
                                    text4.setString(str2);
                                    map.load(tile_name, sf::Vector2u(cell_size, cell_size), level, TAILLEGRILLE, TAILLEGRILLE);
                                    clk.restart();
                                }
                                if(e.type == sf::Event::Closed or e.key.code == Keyboard::Escape)
                                    window1.close();
                                if(e.type == Event::KeyReleased and e.key.code == Keyboard::Space)
                                {
                                    wait = !wait;
                                }
                            }
                            if (clk.getElapsedTime().asSeconds() > update_delay && !wait)
                            {
                                oss.str("");
                                oss << gene;
                                str = "Generation = " + oss.str();
                                j.deplace();
                                gene++;
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
                                text2.setString(str);
                                str1 = "Lapin Population = " + to_string(j.lapinPop());
                                str2 = "Renard Population = " + to_string(j.renardPop());
                                text3.setString(str1);
                                text4.setString(str2);
                                map.load(tile_name, sf::Vector2u(cell_size, cell_size), level, TAILLEGRILLE, TAILLEGRILLE);
                                clk.restart();
                            }

                            window1.clear(Color::Black);
                            window1.draw(map);
                            window1.draw(text1);
                            window1.draw(text2);
                            window1.draw(text3);
                            window1.draw(text4);
                            window1.draw(cell_legend_lapin);
                            window1.draw(cell_legend_renard);
                            window1.display();


                        }
                    }
                }
                break;
            case Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();

        window.draw(sprite1);
        //window.draw(sprite);
        window.draw(start);
        window.draw(stop);
        window.display();
    }
}
