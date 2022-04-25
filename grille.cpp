#include "grille.hpp"

Grille::Grille()
{
    vector<Animal> h1 {TAILLEGRILLE, *(new Animal)};
    vector<vector<Animal>> h2 {TAILLEGRILLE, h1};
    board = h2;

    for(int l = 0; l < TAILLEGRILLE; l++)
    {
        for(int c = 0; c < TAILLEGRILLE; c++)
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
        throw invalid_argument("trying setcase() in case not vide");
    }
    board[c.getLin()][c.getCol()] = *(new Animal{id, e, c});
}

void Grille::setCase(int id, Coord c, Population p) {
    if(not caseVide(c))
    {
        throw invalid_argument("trying setcase() in case not vide");
    }
    board[c.getLin()][c.getCol()] = *(new Animal{id, p.get(id).getEspece(), c});
    board[c.getLin()][c.getCol()].setFoodInit(p.get(id).getFoodInit());

}

string Grille::printCase(Coord c) const
{
    return board[c.getLin()][c.getCol()].toString();
}

int Grille::lapinPop() const {
    int count = 0;
    for(int l = 0; l  < board[0].size(); l++) {
        for(int  c = 0; c < board[0].size(); c++) {
            if(board[l][c].getEspece() == Espece::lapin) {
                count++;
            }
        }
    }
    return count;
}

int Grille::renardPop() const {
    int count = 0;
    for(int l = 0; l  < board[0].size(); l++) {
        for(int  c = 0; c < board[0].size(); c++) {
            if(board[l][c].getEspece() == Espece::renard) {
                count++;
            }
        }
    }
    return count;
}
