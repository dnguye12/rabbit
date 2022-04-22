#include "jeu.hpp"

Jeu::Jeu()
{
    srand(time(NULL));
    int helper;
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        bool found = false;
        Coord c;
        while(not found)
        {
            c.setLin(rand() % TAILLEGRILLE);
            c.setCol(rand() % TAILLEGRILLE);
            if(jGri.caseVide(c))
            {
                found = true;
            }
        }
        helper = rand() % 100 + 1;
        if(helper <= 7)
        {
            ajouteAnimal(Espece::renard, c);
        }
        else if(helper > 7 and helper <= 27)
        {
            ajouteAnimal(Espece::lapin, c);
        }
    }
}

void Jeu::ajouteAnimal(Espece type, Coord coord)
{
    int helper = jPop.set(type, coord);
    jGri.setCase(helper, type, coord);

}


void Jeu::affiche() const
{
    for(int i = 0; i < TAILLEGRILLE*4+1; i++)
    {
        cout << "-";
    }
    cout << endl;

    for(int l =0; l < TAILLEGRILLE; l++)
    {
        for(int c = 0; c < TAILLEGRILLE; c++)
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
        for(int i = 0; i < TAILLEGRILLE*4+1; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    cout << "Lapin Population: " << jPop.getIds(Espece::lapin).size() << endl << jGri.lapinPop() << endl;
}

bool Jeu::verifieGrille() const
{
    for(int l = 0; l< TAILLEGRILLE; l++)
    {
        for(int c = 0; c < TAILLEGRILLE; c++)
        {
            Coord co{l,c};
            if(not jGri.caseVide(co))
            {
                Animal a = jGri.getAnimal(co);
                int id = a.getId();
                if(!(a == jPop.get(id)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<Coord> Jeu::voisinsVides(Coord c) const
{
    vector<Coord> helper = c.voisins();
    for(int i = 0; i < helper.size(); i++)
    {
        if(not jGri.caseVide(helper[i]))
        {
            helper.erase(helper.begin() + i);
        }
    }
    return helper;
}

vector<Coord> Jeu::voisinsLapins(Coord c) const
{
    vector<Coord> helper = c.voisins();
    for(int i = 0; i < helper.size(); i++)
    {
        if(not (jGri.getAnimal(helper[i]).getEspece()==Espece::lapin))
        {
            helper.erase(helper.begin() + i);
        }
    }
    return helper;
}

vector<Coord> Jeu::voisinsRenards(Coord c) const
{
    vector<Coord> helper = c.voisins();
    for(int i = 0; i < helper.size(); i++)
    {
        if(not (jGri.getAnimal(helper[i]).getEspece()==Espece::renard))
        {
            helper.erase(helper.begin() + i);
        }
    }
    return helper;
}

void Jeu::deplace()
{
    vector<Animal> h1 {TAILLEGRILLE, *(new Animal{})};
    vector<vector<Animal>> h2 {TAILLEGRILLE, h1};

    for(int l = 0; l < TAILLEGRILLE; l++)
    {
        for(int c = 0; c < TAILLEGRILLE; c++)
        {
            h2[l][c] = *(new Animal{ -1, Espece::rien, *(new Coord{l,c})  });
        }
    }
    for(int l = 0; l < TAILLEGRILLE; l++)
    {
        for(int c = 0; c < TAILLEGRILLE; c++)
        {
            Coord coord {l,c};
            if(jGri.getAnimal(coord).getEspece() == Espece::lapin)
            {
                vector<Coord> voisins = voisinsVides(coord);
                if(voisins.size() == 0)
                {
                    continue;
                }
                else if(h2[l][c].getEspece() == Espece::rien)
                {
                    int choix = rand() % voisins.size();
                    Coord new_coord = voisins[choix];
                    int id = jGri.getAnimal(coord).getId();
                    jPop.changeCoord(id, new_coord);
                    jGri.setCase(id, Espece::lapin, new_coord);
                    jGri.videCase(coord);
                }
            }
        }
    }
}
