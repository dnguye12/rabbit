#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#include "jeu.hpp"

int main()
{
    /*
    Coord c1{5,6};
    Coord c2{5,5};
    Coord c3{5,5};

    cout << (c1 == c2) << endl;
    cout << (c2==c3) << endl;*/

    /*
    Animal a{20, Espece::lapin, *(new Coord{10,11})};
    cout << a.getId() << endl;
    cout << a.getCoord().getCol() << " " << a.getCoord().getLin() << endl;
    cout << a.toString() << endl;*/

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
        system("clear");
        j.affiche();
        chrono::seconds dura(1);
        this_thread::sleep_for( dura );
        //j.deplace();
    }

    return 0;
}
