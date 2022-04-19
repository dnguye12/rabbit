#include <iostream>

using namespace std;

#include "animal.hpp"

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

    Population p {};

    //cout << p.reserve()<< endl << p.reserve() << endl;

    Coord c1{5,6};
    Coord c2{5,5};

    p.set(Espece::lapin, c1);
    p.set(Espece::lapin, c2);

    cout << p.get(0).toString() << endl;

    cout << p.getIds(Espece::lapin);

    return 0;
}
