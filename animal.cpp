#include "animal.hpp"

Animal::Animal(int id, Espece type, Coord coord)
{
    aId = id;
    aType = type;
    aCoord = coord;
}

int Animal::getId()
{
    return aId;
}

Coord Animal::getCoord()
{
    return aCoord;
}

void Animal::setCoord(Coord c) {
    aCoord = c;
}

Espece Animal::getEspece() {
    return aType;
}

string Animal::toString() {

}
