#ifndef ANIMAL_HPP_INCLUDED
#define ANIMAL_HPP_INCLUDED

#include <string>

#include "util.hpp"

using namespace std;

enum class Espece {renard, lapin, rien};

struct Animal {
private:
    int aId;
    Espece aType;
    Coord aCoord;
public:
    //Constructors
    Animal();
    Animal(int id, Espece type, Coord coord);

    //Methods
    int getId() const;

    Coord getCoord() const;

    void setCoord(Coord c);

    Espece getEspece() const;

    string toString() const;
};



struct Population {
public:
    //constructor
    Population();

    //methods
    Animal get(int id) const;

    Ensemble getIds(Espece type) const;

    int reserve();

    void set(Espece type, Coord c);

    void supprime(int id);
private:
    Animal pop[400];
    vector<int> freeId;
};



struct Grille {
public:
    Grille();

    bool caseVide(Coord c) const;

    int getCase(Coord c) const;

    void videCase(Coord c);

    void setCase(int id, Espece e, Coord c);

private:
    vector<vector<Animal>> board;
};

#endif // ANIMAL_HPP_INCLUDED
