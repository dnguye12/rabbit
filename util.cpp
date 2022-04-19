#include <stdexcept>
#include <iostream>

#include "util.hpp"

using namespace std;

Coord::Coord(): lin{0}, col{0} {}

Coord::Coord(int a, int b): lin{a}, col{b}
{
    if(a > 20 or b > 20 or a < 0 or b < 0)
    {
        throw invalid_argument("out of grille bound");
    }
}

int Coord::getLin()
{
    return lin;
}

int Coord::getCol()
{
    return col;
}

bool operator==(Coord c1, Coord c2) {
    return c1.getLin() == c2.getLin() and c1.getCol() == c2.getCol();
}

bool operator!=(Coord c1, Coord c2) {
    return not(c2 == c1);
}








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


