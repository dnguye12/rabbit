#include "animal.hpp"

Animal::Animal() {
    aType = Espece::rien;
}

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
    switch(aType) {
    case Espece::lapin:
        return "Lapin";
    case Espece::renard:
        return "Renard";
    default:
        return " ";
    }
}




Population::Population() {
    //pop = Animal[400];
    for(int i = 0; i < 400; i++) {
        freeId.push_back(i);
    }
}

Animal Population::get(int id) {
    for(int i = 0; i < 400; i++) {
        if(pop[i].getId() == id) {
            return pop[i];
        }
    }
    return *(new Animal{});
}
