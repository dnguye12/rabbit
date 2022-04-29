#define DOCTEST_CONFIG_IMPLEMENT

#include <chrono>
#include <time.h>
#include <thread>

#include "doctest.h"
#include "coord.hpp"
#include "jeu.hpp"
#include "animal.hpp"
#include "population.hpp"
#include "grille.hpp"

TEST_CASE("Coord test")
{
    Coord c1{5,6};
    Coord c2{5,5};
    Coord c3{5,5};
    Coord c4{19,19};
    Coord c5{390};
    CHECK(c1 != c2);
    CHECK(c3 == c2);
    CHECK(c4.toInt() == 969);
    CHECK(c5 == *(new Coord{7,40}) );
}

void voisin_vide_affichage()
{
    Jeu j {};
    Coord c1{5,6};
    vector<Coord> helper = j.voisinsVides(c1);
    for(int i = 0; i < helper.size(); i++)
    {
        cout << helper[i];
    }
}

void animal_testing()
{
    Animal a{20, Espece::lapin, *(new Coord{10,11})};
    cout << a.getId() << endl;
    cout << a.getCoord().getCol() << " " << a.getCoord().getLin() << endl;
    cout << a.toString() << endl;
}

/*
//No longer work, need to set jPop in Jeu.hpp and pop in population.hpp to public for testing
void jeu_deplacement_testing()
{
    Jeu j{};
    for(int i = 0; i < 10; i++)
    {
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
    for(int i = 0; i < 10; i++)
    {
        cout << j.jPop.pop[i].getCoord() << endl;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << j.jGri.printCase(* (new Coord{0, i}) ) <<" ";
    }
    cout << endl;
    j.jGri = *(new Grille{});

    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        Animal a = j.jPop.getIndex(i);
        if(a.getEspece() != Espece::rien)
        {
            Coord c = a.getCoord();
            j.jGri.setCase(a.getId(), a.getEspece(), c);
        }
    }
    cout << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << j.jGri.printCase(* (new Coord{0, i}) ) <<" ";
    }
    cout << endl;
}
*/
void jeu_basic_testing() {
    Jeu j{};
       while(j.verifieGrille())
    {
        system("cls");
        j.affiche();
        chrono::seconds dura(1);
        this_thread::sleep_for( dura );
        j.deplace();
    }
}

int main(int argc, const char **argv)
{
    doctest::Context context(argc, argv);
    int test_result = context.run();
    if (context.shouldExit()) return test_result;

    //jeu_basic_testing();
    return 0;
}
