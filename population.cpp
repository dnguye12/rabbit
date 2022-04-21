#include "population.hpp"

#include <algorithm>

Population::Population()
{
    //pop = Animal[400];
    for(int i = 0; i < 800; i++)
    {
        freeId.push_back(i);
    }
}

Animal Population::get(int id) const
{
    for(int i = 0; i < 800; i++)
    {
        if(pop[i].getId() == id)
        {
            return pop[i];
        }
    }
    return *(new Animal{});
}

Ensemble Population::getIds(Espece type) const
{
    Ensemble helper;
    int pop_size = sizeof(pop) / sizeof(pop[0]);
    for(int i = 0; i < pop_size; i++)
    {
        if(pop[i].getEspece() == type)
        {
            helper.ajoute(pop[i].getId());
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