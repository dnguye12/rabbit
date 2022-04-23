#ifndef ANIMAL_HPP_INCLUDED
#define ANIMAL_HPP_INCLUDED

#include <string>

#include "coord.hpp"
#include "ensemble.hpp"

using namespace std;

enum class Espece {renard, lapin, rien};

class Animal {
private:
    int aId;
    Espece aType;
    Coord aCoord;
    int MinFreeBirthLapin = 4;
    int ProbReproLapin = 30;
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

    int getMinFreeBirthLapin() const;

    int getProbReproLapin() const;
};

bool operator==(Animal a1, Animal a2);

#endif // ANIMAL_HPP_INCLUDED
