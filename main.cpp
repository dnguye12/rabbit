#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

#include "jeu.hpp"
#include <SFML/Graphics.hpp>
#include "menu.hpp"

using namespace std;
using namespace sf;
/*
void MainMenu() {
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
}*/


void SimMenu()
{

}
int main()
{


    /*
    Population p {};

    //cout << p.reserve()<< endl << p.reserve() << endl;

    Coord c1{5,6};
    Coord c2{5,5};

    p.set(Espece::lapin, c1);
    p.set(Espece::lapin, c2);

    cout << p.get(0).toString() << endl;

    cout << p.getIds(Espece::lapin);*/

    //Jeu j{};
    /*
    vector<Coord> hekoer =  j.voisinsVides( *(new Coord {2,3}));
    for(int i = 0; i < hekoer.size(); i++) {
        cout << hekoer[i].getLin() << " "<< hekoer[i].getCol() << endl;
    }*/
    /*
       while(j.verifieGrille())
        {
            system("cls");
            j.affiche();
            chrono::seconds dura(1);
            //this_thread::sleep_for( dura );
            j.deplace();
        }
    */
    //Menu m {600,600};
    //m.MainMenu();


    const Color rien(255,255,255);
    const Color lapin(0,0,255);
    const Color renard(255,0,0);

    const int cell_size = 4;
    const int cell_border = 0;

    const int window_size = cell_size * TAILLEGRILLE;
    //const int window_size = 700;
    const int window_extra = 220;

    const unsigned int offset_x = 0;
    const unsigned int offset_y = 5;
    const unsigned int plot_offset_x = 50;
    const unsigned int plot_offset_y = window_extra -20;

    bool wait = 1;
    const float update_delay = 0.01;

    unsigned int turn = 1;
    unsigned int n_generation_save = 500;
    unsigned int counter_save = 0;
    unsigned int lapin_count[n_generation_save] = {0};
    unsigned int renard_count[n_generation_save] = {0};

    srand(time(0));
    Clock clk;
    clk.restart();

    Font font;
    if(!font.loadFromFile("Fonts/ConnectionIi-2wj8.otf"))
    {
        throw invalid_argument("Fonts not found");
    }

    stringstream oss;
    oss << 1;
    string str = "Turn = " + oss.str();

    Text text,text2,text3,text4;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(12);
    text.setPosition(window_size*.75, window_size + 10);

    text2.setFont(font);
    text2.setString("Press Space to Start/Pause\nPress Esc to quit");
    text2.setCharacterSize(12);
    text2.setPosition(15, window_size + offset_y + 1);

    text3.setFont(font);
    text3.setString("Time");
    text3.setCharacterSize(10);
    text3.setPosition(window_size/2, window_size + window_extra -15);

    text4.setFont(font);
    text4.setString("Lapin Population,\nRenard Population x 4");
    text4.setCharacterSize(10);

    text4.setPosition(plot_offset_x-35, window_size + window_extra*.7);
    text4.setRotation(-90.0);




// Setting up drawing entities. VertexArrays and Rectangle shapes
    VertexArray grid_draw(Quads,TAILLEGRILLE*TAILLEGRILLE*4);   // for drawing fish, shark and empty cells
    VertexArray plot_axes(Lines,4);         // for drawing plot axes

    RectangleShape cell(Vector2f(2,2));              // for drawing the plot
    RectangleShape cell_legend_lapin(Vector2f(5,5));  // for drawing the fish legend on the plot
    RectangleShape cell_legend_renard(Vector2f(5,5)); // for drawing the shark legend on the plot

    // cell.setFillColor(Color(2,252,251));

// Initializing
    cell.setFillColor(lapin);
    cell.setOutlineColor(Color(0,0,0));
    cell.setOutlineThickness(cell_border);

// Setting the position, color etc. of the plot legends
    cell_legend_lapin.setFillColor(lapin);
    cell_legend_lapin.setOutlineColor(Color(0,0,0));
    cell_legend_lapin.setOutlineThickness(cell_border);
    cell_legend_lapin.setPosition(window_size*0.75-12,window_size + window_extra*.27);

    cell_legend_renard.setFillColor(renard);
    cell_legend_renard.setOutlineColor(Color(0,0,0));
    cell_legend_renard.setOutlineThickness(cell_border);
    cell_legend_renard.setPosition(window_size*0.75-12,window_size + window_extra*.27+13);

    plot_axes[0].position = Vector2f(plot_offset_x,plot_offset_y + window_size);
    plot_axes[1].position = Vector2f(window_size-plot_offset_x, plot_offset_y + window_size);
    plot_axes[2].position = Vector2f(plot_offset_x,plot_offset_y + window_size);
    plot_axes[3].position = Vector2f(plot_offset_x,  window_size + 50);



// Render the window
    RenderWindow window(VideoMode(window_size,window_size + window_extra), "Predetor-Prey dynamics (Wa-Tor)");
    // window.clear(Color(216,27,29));
    window.clear(Color::Black);

    while(window.isOpen())
    {
        Event e;
        Jeu j;

        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed || e.key.code == Keyboard::Escape)   window.close();
            if (e.type == Event::KeyPressed && e.key.code == Keyboard::Space)  wait = !wait;
        }

        if (clk.getElapsedTime().asSeconds() > update_delay && !wait)
        {
            lapin_count[counter_save] = j.lapinPop();
            renard_count[counter_save] = j.renardPop();

            counter_save++;

            if(counter_save >= n_generation_save)
            {
                counter_save = n_generation_save -1;
                for(int i = 0; i < counter_save; i++)
                {
                    lapin_count[i] = lapin_count[i  + 1];
                }
            }

            turn = turn + 1;

            oss.str("");
            oss << turn;
            str = "Turn = " + oss.str();

            oss.str("");
            oss << j.lapinPop();
            str = str + "\n\n\nRabbit population = " + oss.str();

            oss.str("");
            oss << j.renardPop();
            str = str + "\nRenard population = " + oss.str();


            text.setString(str);


            clk.restart();   // Restart the clock (very important)
        }

        unsigned int counter = 0;
        for (int i = 0; i < TAILLEGRILLE; i ++)
        {
            for (int j = 0; j < TAILLEGRILLE; j ++)
            {

                // cell.setPosition(i*cell_size_x + offset_x, j*cell_size_y + offset_y);


                grid_draw[counter].position = Vector2f(i*cell_size + offset_x, j*cell_size + offset_y);
                grid_draw[counter+1].position = Vector2f((i+1)*cell_size + offset_x, j*cell_size + offset_y);
                grid_draw[counter+2].position = Vector2f((i+1)*cell_size + offset_x, (j+1)*cell_size + offset_y);
                grid_draw[counter+3].position = Vector2f(i*cell_size + offset_x, (j+1)*cell_size + offset_y);




                if (j.lapinPop() > 0)
                {
                    // cell.setFillColor(fish_color);
                    grid_draw[counter].color = lapin;
                    grid_draw[counter+1].color = lapin;
                    grid_draw[counter+2].color = lapin;
                    grid_draw[counter+3].color = lapin;
                }
                else
                {
                    // cell.setFillColor(dead_cell);
                    grid_draw[counter].color = rien;
                    grid_draw[counter+1].color = rien;
                    grid_draw[counter+2].color = rien;
                    grid_draw[counter+3].color = rien;
                }





                if (shark_population[i][j] > 0)
                {

                    grid_draw[counter].color = shark_color;
                    grid_draw[counter+1].color = shark_color;
                    grid_draw[counter+2].color = shark_color;
                    grid_draw[counter+3].color = shark_color;
                }

                // window.draw(cell);
                // int temp1 = rand()%3;
                // if (temp1 == 2)  std:: cout << temp1 << std:: endl;
                counter = counter + 4;

            }   // end j
            // window.draw(cell);
        }   // end i

        window.draw(grid_draw);
        window.draw(plot_axes);

        for (int i = 0; i < counter_save; i++)
        {
            cell.setPosition((window_size-2*plot_offset_x)*i/n_generation_save + plot_offset_x, window_size + plot_offset_y  -  150*lapin_count[i]/(TAILLEGRILLE*TAILLEGRILLE));
            cell.setFillColor(lapin);
            window.draw(cell);
            cell.setPosition((window_size-2*plot_offset_x)*i/n_generation_save  + plot_offset_x, window_size + plot_offset_y -  600*renard_count[i]/(TAILLEGRILLE*TAILLEGRILLE));
            cell.setFillColor(renard);
            window.draw(cell);
        }


        window.display();
        window.clear(Color::Black);

        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(cell_legend_lapin);
        window.draw(cell_legend_renard);
    }



    return 0;
}
