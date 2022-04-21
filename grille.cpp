#include "grille.hpp"

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

Animal Grille::getAnimal(Coord c) const
{
    return board[c.getLin()][c.getCol()];
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

string Grille::printCase(Coord c) const
{
    return board[c.getLin()][c.getCol()].toString();
}

int Grille::lapinPop() const {
    int count = 0;
    for(int l = 0; l  < 20; l++) {
        for(int  c = 0; c < 20; c++) {
            if(board[l][c].getEspece() == Espece::lapin) {
                count++;
            }
        }
    }
    return count;
}
