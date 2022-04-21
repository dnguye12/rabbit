#ifndef POPULATION_HPP_INCLUDED
#define POPULATION_HPP_INCLUDED

#include "animal.hpp"

#include <vector>

struct Population {
public:
    //constructor
    Population();

    //methods
    Animal get(int id) const;

    Ensemble getIds(Espece type) const;

    int reserve();

    int set(Espece type, Coord c);

    void supprime(int id);

    void changeCoord(int id, Coord c);
private:
    Animal pop[TAILLEGRILLE * TAILLEGRILLE * 2];
    vector<int> freeId;
};

#endif // ANIMAL_HPP_INCLUDED
