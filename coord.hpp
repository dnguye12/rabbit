#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED

#include <vector>
#include <iostream>

using namespace std;

const int TAILLEGRILLE = 20;

class Coord
{
private:
    int lin;
    int col;
public:
    //constructeurs
    Coord();

    Coord(int a, int b);

    Coord(int a);

    //methodes
    int getLin() const;
    int getCol() const;

    void setLin(int i);
    void setCol(int i);

    int toInt() const;

    vector<Coord> voisins() const;

};

ostream &operator<<(ostream &out, Coord c);

bool operator==(Coord c1, Coord c2);

bool operator!=(Coord c1, Coord c2);

#endif
