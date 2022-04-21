#include "jeu.hpp"

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
    cout << "Lapin Population: " << jPop.getIds(Espece::lapin).size() << endl << jGri.lapinPop() << endl;
}

bool Jeu::verifieGrille() const
{
    for(int l = 0; l< 20; l++)
    {
        for(int c = 0; c < 20; c++)
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

void Jeu::deplace() {
    for(int l = 0; l < 20; l++) {
        for(int c = 0; c < 20; c++) {
            Coord coord {l,c};
            vector<Coord> voisins = voisinsVides(coord);
            if(voisins.size() == 0) {
                continue;
            }
            if(jGri.getAnimal(coord).getEspece() == Espece::lapin) {
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
