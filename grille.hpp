#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED

#include "coord.hpp"
#include "animal.hpp"

class Grille {
public:
    Grille();

    bool caseVide(Coord c) const;

    int getCase(Coord c) const;

    Animal getAnimal(Coord c) const;

    void videCase(Coord c);

    void setCase(int id, Espece e, Coord c);

    string printCase(Coord c) const;

    int lapinPop() const;

    int renardPop() const;

private:
    vector<vector<Animal>> board;
};

#endif // ANIMAL_HPP_INCLUDED
