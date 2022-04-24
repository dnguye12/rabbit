#ifndef POPULATION_HPP_INCLUDED
#define POPULATION_HPP_INCLUDED

#include "animal.hpp"
#include "ensemble.hpp"

#include <vector>

class Population {
public:
    //constructor
    Population();

    //methods
    Animal get(int id) const;

    Animal getIndex(int i) const;

    vector<int> getIds(Espece type) const;

    int reserve();

    int set(Espece type, Coord c);

    void supprime(int id);

    void changeCoord(int id, Coord c);

    void setFoodInit(int id, int i);
//private:
    Animal pop[TAILLEGRILLE * TAILLEGRILLE];
    vector<int> freeId;
};

#endif // ANIMAL_HPP_INCLUDED
