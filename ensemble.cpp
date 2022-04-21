
#include <iostream>

#include "ensemble.hpp"


Ensemble::Ensemble() : set_{} {}

Ensemble::Ensemble(vector<Objet> v): set_{}
{
    for (int i : v) set_.push_back(i);
}
// END: constructeurs

// BEGIN: ajoute
void Ensemble::ajoute(Objet o)
{
    set_.push_back(o);
}
// END: ajoute

// BEGIN: retire
bool Ensemble::retire(Objet o)
{
    // Cherche un n dans le sac
    for(int i = 0; i < set_.size(); i++)
    {
        if(set_[i] == o)
        {
            set_.erase(set_.begin() + i);
            return true;
        }
    }
    return false;
}
// END: retire

// BEGIN: element
Objet Ensemble::element() const
{
    return *set_.begin();
}
// END: element

// BEGIN: estVide
bool Ensemble::estVide() const
{
    return set_.empty();
}
// END: estVide

// BEGIN: contient
bool Ensemble::contient(Objet o) const
{
    if (set_[0] > o or set_[MaxTaille - 1] < o)
    {
        return false;
    }
    return true;
}

int Ensemble::size() const {
    return set_.size();
}

ostream &operator<<(ostream &out, Ensemble e)
{
    // Remplacer la ligne suivante par le code adéquat
    vector<Objet> helper;
    while(not e.estVide())
    {
        helper.push_back(e.element());
        e.retire(e.element());
    }
    for(int i = 0; i < helper.size(); i++)
    {
        out << helper[i] << endl;
    }
    return out;
}



