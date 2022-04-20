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

int Coord::getLin() const
{
    return lin;
}

int Coord::getCol() const
{
    return col;
}

void Coord::setLin(int i) {
    lin = i;
}
void Coord::setCol(int i) {
    col = i;
}

vector<Coord> Coord::voisins(Coord c) const {
    vector<Coord> helper;
    int lin = c.getLin();
    int col = c.getCol();

    for(int l = lin -1 ; l <= lin +1 ; l++) {
        for(int c = col - 1 ; c <= col +1; c++) {
            if(c > 19 or l > 19 or c <0 or l <0 or  (c == col and l == lin)) {
                continue;
            }else {
                helper.push_back(*(new Coord{lin, col}));
            }
        }
    }
    return helper;
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



