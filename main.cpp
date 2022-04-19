#include <iostream>

//#include "source.hpp"
#include "animal.hpp"
#include <chrono>
#include <thread>

using namespace std;



int main()
{
    Coord c {5, 10};
    Ensemble v1{ {1,5,10} };

    //cout << v1.element()<< endl;

    //AnimalType a = AnimalType::lapin;
    //cout << a;

    //Animal b{};

    //cout << b.getCoord().getLin();

    Grille g {};

    //Lapin l{c};

    //cout << l.getType();

    //cout << stringAnimalType(g.pos[0][0].getType());
    //g.affiche();

//    cout << g.voisineVide(*new Coord{19,19});

    //cout << g.pop.renaldPop();
    while(true) {
        system("clear");
        g.affiche();
        chrono::seconds dura( 1);
        this_thread::sleep_for( dura );
        g.pop.move();

    }
    return 0;
}
