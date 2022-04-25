#include "population.hpp"

#include <algorithm>
#include <stdlib.h>

Population::Population()
{
    //pop = Animal[400];
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        freeId.push_back(i);
    }
}

Animal Population::get(int id) const
{
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        if(pop[i].getId() == id)
        {
            return pop[i];
        }
    }
    return *(new Animal{});
}

Animal Population::getIndex(int i) const {
    return pop[i];
}

vector<int> Population::getIds(Espece type) const
{
    vector<int> helper;
    int pop_size = sizeof(pop) / sizeof(pop[0]);
    for(int i = 0; i < pop_size; i++)
    {
        if(pop[i].getEspece() == type)
        {
            helper.push_back(pop[i].getId());
        }
    }
    return helper;
}

int Population::reserve()
{
    if(freeId.size() == 0)
    {
        return -1;
    }
    else
    {
        int helper = freeId[0];
        freeId.erase(freeId.begin());
        return helper;
    }
}

int Population::set(Espece type, Coord c)
{
    int id = reserve();
    if(id == -1)
    {
        return -1;
    }
    pop[id] = *(new Animal{id, type, c});
    return id;
}

void Population::supprime(int id)
{
    pop[id] = {};
    freeId.push_back(id);
    sort(freeId.begin(), freeId.end());
}

void Population::changeCoord(int id, Coord c) {
    pop[id].setCoord(c);
}

void Population::setFoodInit(int id, int i) {

    if(i > pop[id].getMaxFood()) {
        pop[id].setFoodInit(pop[id].getMaxFood());
    }else {
    pop[id].setFoodInit(i);
    }
}
