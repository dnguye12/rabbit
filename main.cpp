#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "jeu.hpp"

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

    Jeu j{};
    /*
    vector<Coord> hekoer =  j.voisinsVides( *(new Coord {2,3}));
    for(int i = 0; i < hekoer.size(); i++) {
        cout << hekoer[i].getLin() << " "<< hekoer[i].getCol() << endl;
    }*/

   while(j.verifieGrille())
    {
        system("cls");
        j.affiche();
        chrono::seconds dura(1);
        //this_thread::sleep_for( dura );
        j.deplace();
    }

    return 0;
}
