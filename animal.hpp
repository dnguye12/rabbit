#ifndef ANIMAL_HPP_INCLUDED
#define ANIMAL_HPP_INCLUDED

#include "util.hpp"

enum class Espece {renard, lapin};

struct Animal {
private:
    int aId;
    Espece aType;
    Coord aCoord;
public:
    //Constructors
    Animal(int id, Espece type, Coord coord);

    //Methods
    int getId();

    Coord getCoord();

    void setCoord();

    Espece getEspece();

    string toString();
};

#endif // ANIMAL_HPP_INCLUDED
