#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "coord.hpp"

TEST_CASE("Coord test")
{
    Coord c1{5,6};
    Coord c2{5,5};
    Coord c3{5,5};
    Coord c4{19,19};
    Coord c5{390};
    CHECK(c1 != c2);
    CHECK(c3 == c2);
    CHECK(c4.toInt() == 399);
    CHECK(c5 == *(new Coord{19,10}) );
}

int main(int argc, const char **argv)
{
    doctest::Context context(argc, argv);
    int test_result = context.run();
    if (context.shouldExit()) return test_result;

    //voisin vides affichage
    /*Coord c1{5,6};
        vector<Coord> helper = j.voisinsVides(c1);
        for(int i = 0; i < helper.size(); i++) {
          cout << helper[i];
        }*/

    //Animal testing
    /*
    Animal a{20, Espece::lapin, *(new Coord{10,11})};
    cout << a.getId() << endl;
    cout << a.getCoord().getCol() << " " << a.getCoord().getLin() << endl;
    cout << a.toString() << endl;*/

    //Jeu deplacement testing
    /*
    for(int i = 0; i < 10; i++) {
        cout << j.jPop.pop[i].getCoord() << endl;
    }

    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        Animal a = j.jPop.getIndex(i);
        if(a.getEspece() != Espece::rien)
        {
            Coord c = a.getCoord();
            int id = a.getId();
            vector<Coord> videc = j.voisinsVides(c);
            int choix = rand() % videc.size();
            Coord newc = videc[choix];
            j.jPop.changeCoord(id, newc);
        }

    }

    cout << endl << endl;
    for(int i = 0; i < 10; i++) {
        cout << j.jPop.pop[i].getCoord() << endl;
    }

    for(int i = 0; i < 10; i++) {
        cout << j.jGri.printCase(* (new Coord{0, i}) ) <<" ";
    }
    cout << endl;
    j.jGri = *(new Grille{});

    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++) {
        Animal a = j.jPop.getIndex(i);
        if(a.getEspece() != Espece::rien) {
            Coord c = a.getCoord();
            j.jGri.setCase(a.getId(), a.getEspece(), c);
        }
    }
    cout << endl;
        for(int i = 0; i < 10; i++) {
        cout << j.jGri.printCase(* (new Coord{0, i}) ) <<" ";
    }
    cout << endl;
*/
    return 0;
}
