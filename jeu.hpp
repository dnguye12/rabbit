#ifndef JEU_HPP_INCLUDED
#define JEU_HPP_INCLUDED

#include "animal.hpp"
#include "population.hpp"
#include "grille.hpp"
#include "ensemble.hpp"

class Jeu {
public:
    Jeu();

    void ajouteAnimal(Espece type, Coord coord);

    void affiche() const;

    bool verifieGrille() const;

    vector<Coord> voisinsVides(Coord c) const;

    vector<Coord> voisinsLapins(Coord c) const;

    vector<Coord> voisinsRenards(Coord c) const;

    void deplace();

private:
    Population jPop;
    Grille jGri;
};

bool vectorContient(vector<int> vec, int x);

#endif // ANIMAL_HPP_INCLUDED
