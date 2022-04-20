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



Grille::Grille()
{
    vector<Animal> h1 {20, *(new Animal)};
    vector<vector<Animal>> h2 {20, h1};
    board = h2;

    for(int l = 0; l < 20; l++)
    {
        for(int c = 0; c < 20; c++)
        {
            board[l][c] = *(new Animal{ -1, Espece::rien, *(new Coord{l,c})  });
        }
    }
}

bool Grille::caseVide(Coord c) const
{
    return board[c.getLin()][c.getCol()].getEspece() == Espece::rien;
}

int Grille::getCase(Coord c) const
{
    if(caseVide(c))
    {
        return -1;
    }
    return board[c.getLin()][c.getCol()].getId();
}

void Grille::videCase(Coord c)
{
    if(caseVide(c))
    {
        return;
    }
    board[c.getLin()][c.getCol()] = *(new Animal{-1, Espece::rien, c});
}

void Grille::setCase(int id, Espece e, Coord c)
{

    if(not caseVide(c))
    {
        return;
    }
    board[c.getLin()][c.getCol()] = *(new Animal{id, e, c});
}

string Grille::printCase(Coord c) const {
    return board[c.getLin()][c.getCol()].toString();
}




void Jeu::ajouteAnimal(Espece type, Coord coord)
{
    int helper = jPop.set(type, coord);
    jGri.setCase(helper, type, coord);

}

Jeu::Jeu()
{
    srand(time(NULL));
    int helper;
    for(int i = 0; i < 400; i++)
    {
        bool found = false;
        Coord c;
        while(not found)
        {
            c.setLin(rand() % 20);
            c.setCol(rand() % 20);
            if(jGri.caseVide(c))
            {
                found = true;
            }
        }
        helper = rand() % 100 + 1;
        if(helper <= 7)
        {
            int id = jPop.set(Espece::renard, c);
            jGri.setCase(id, Espece::renard, c);
        }
        else if(helper > 7 and helper <= 27)
        {
            int id = jPop.set(Espece::lapin, c);
            jGri.setCase(id, Espece::lapin, c);
        }
    }
}

void Jeu::affiche()
{
    for(int i = 0; i < 81; i++)
    {
        cout << "-";
    }
    cout << endl;

    for(int l =0; l < 20; l++)
    {
        for(int c = 0; c < 20; c++)
        {
            if(c == 0)
            {
                cout << "| " << jGri.printCase(* (new Coord{l, c}) ) << " | ";
            }
            else
            {
                cout << jGri.printCase(* (new Coord{l, c}) ) << " | ";
            }
        }
        cout << endl;
        for(int i = 0; i < 81; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
}
