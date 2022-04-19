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
    int getId();

    Coord getCoord();

    void setCoord(Coord c);

    Espece getEspece();

    string toString();
};



struct Population {
public:
    //constructor
    Population();

    //methods
    get(int id);

    getIds(Espece type);
//private:
    Animal pop[400];
    vector<int> freeId;
};

#endif // ANIMAL_HPP_INCLUDED
