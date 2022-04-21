#include "coord.hpp"
#include "doctest.h"
#include <stdexcept>

using namespace std;

Coord::Coord(): lin{0}, col{0} {}

Coord::Coord(int a, int b): lin{a}, col{b}
{
    if(a >= TAILLEGRILLE or b > TAILLEGRILLE or a < 0 or b < 0)
    {
        throw invalid_argument("out of grille bound");
    }
}

Coord::Coord(int a) {
    if(a >= TAILLEGRILLE*TAILLEGRILLE) {
        throw invalid_argument("out of grille bound");
    }else {
        lin = a / TAILLEGRILLE;
        col = a % TAILLEGRILLE;
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


int Coord::toInt() const {
    return lin * TAILLEGRILLE + col;
}

vector<Coord> Coord::voisins() const {
    vector<Coord> helper;

    for(int l = lin -1 ; l <= lin +1 ; l++) {
        for(int c = col - 1 ; c <= col +1; c++) {
            if(c > TAILLEGRILLE-1 or l > TAILLEGRILLE-1  or c <0 or l <0 or  (c == col and l == lin)) {
                continue;
            }else {
                helper.push_back(*(new Coord{l, c}));
            }
        }
    }
    return helper;
}

ostream &operator<<(ostream &out, Coord c) {
    out << c.getLin() << ":" << c.getCol();
    return out;
}

bool operator==(Coord c1, Coord c2) {
    return c1.getLin() == c2.getLin() and c1.getCol() == c2.getCol();
}

bool operator!=(Coord c1, Coord c2) {
    return not(c2 == c1);
}

TEST_CASE("Coord test")
{
    Coord c1{5,6};
    Coord c2{5,5};
    Coord c3{5,5};
    Coord c4{19,19};
    CHECK(c1 != c2);
    CHECK(c3 == c2);
    CHECK(c4.toInt() == 399);
}

