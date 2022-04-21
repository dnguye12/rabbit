#include <bits/stdc++.h>
#include <random>

#include "animal.hpp"

Animal::Animal()
{
    aId = -1;
    aType = Espece::rien;
}

Animal::Animal(int id, Espece type, Coord coord)
{
    aId = id;
    aType = type;
    aCoord = coord;
}

int Animal::getId() const
{
    return aId;
}

Coord Animal::getCoord() const
{
    return aCoord;
}

void Animal::setCoord(Coord c)
{
    aCoord = c;
}

Espece Animal::getEspece() const
{
    return aType;
}

string Animal::toString() const
{
    switch(aType)
    {
    case Espece::lapin:
        return "L";
    case Espece::renard:
        return "R";
    default:
        return " ";
    }
}

bool operator==(Animal a1, Animal a2)
{
    return a1.getId() == a2.getId() and a1.getCoord() == a2.getCoord() and a1.getEspece() == a2.getEspece();
}

