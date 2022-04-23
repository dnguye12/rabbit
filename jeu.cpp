#include "jeu.hpp"
#include <time.h>

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
        else if(helper > 7 and helper <= 20)
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
    cout << "Renard Population: " << jPop.getIds(Espece::renard).size() << endl << jGri.renardPop() << endl;
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
    vector<Coord> otto;
    for(int i = 0; i < helper.size(); i++)
    {
        if(jGri.caseVide(helper[i]))
        {
            otto.push_back(helper[i]);
        }
    }
    return otto;
}

vector<Coord> Jeu::voisinsLapins(Coord c) const
{
    vector<Coord> helper = c.voisins();
    vector<Coord> otto;
    for(int i = 0; i < helper.size(); i++)
    {
        if((jGri.getAnimal(helper[i]).getEspece()==Espece::lapin))
        {
            otto.push_back(helper[i]);
        }
    }
    return otto;
}

vector<Coord> Jeu::voisinsRenards(Coord c) const
{
    vector<Coord> helper = c.voisins();
    vector<Coord> otto;
    for(int i = 0; i < helper.size(); i++)
    {
        if((jGri.getAnimal(helper[i]).getEspece()==Espece::renard))
        {
            otto.push_back(helper[i]);
        }
    }
    return otto;
}

void Jeu::deplaceLapin()
{
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        Animal a = jPop.getIndex(i);
        if(a.getEspece() == Espece::lapin)
        {
            Coord c = a.getCoord();
            int id = a.getId();
            vector<Coord> videc = voisinsVides(c);
            if(videc.size() == 0) {
                return;
            }
            if(videc.size() >= a.getMinFreeBirthLapin())
            {
                int birth = rand() % 100 +1;
                if(birth <= a.getProbReproLapin())
                {

                    int choix = rand() % videc.size();
                    Coord newc = videc[choix];
                    jPop.changeCoord(id, newc);
                    jGri.setCase(a.getId(), a.getEspece(), newc);
                    jGri.videCase(c);
                    int nid = jPop.set(Espece::lapin, c);
                    if(nid != -1)
                    {
                        jGri.setCase(nid, Espece::lapin, c);
                    }


                }
                else
                {
                    int choix = rand() % videc.size();
                    Coord newc = videc[choix];
                    jPop.changeCoord(id, newc);
                    jGri.setCase(a.getId(), a.getEspece(), newc);
                    jGri.videCase(c);
                }

            }
            else
            {
                int choix = rand() % videc.size();
                Coord newc = videc[choix];
                jPop.changeCoord(id, newc);
                jGri.setCase(a.getId(), a.getEspece(), newc);
                jGri.videCase(c);
            }
        }

    }
}

void Jeu::deplaceRenard()
{
    for(int i = 0; i < TAILLEGRILLE*TAILLEGRILLE; i++)
    {
        Animal a = jPop.getIndex(i);
        if(a.getEspece() == Espece::renard)
        {
            Coord c = a.getCoord();
            int id = a.getId();
            vector<Coord> videl = voisinsLapins(c);
            vector<Coord> videc = voisinsVides(c);
            if(videc.size() == 0) {
                return;
            }
            int choix;
            if(videl.size() > 0)
            {
                choix = rand() % videl.size();
                int lid = jGri.getCase(videl[choix]);
                jPop.supprime(lid);
                jGri.videCase(videl[choix]);
                jPop.changeCoord(id, videl[choix]);
                jGri.setCase(a.getId(), a.getEspece(), videl[choix]);
                jGri.videCase(c);
            }
            else
            {
                choix = rand() % videc.size();
                Coord newc = videc[choix];
                jPop.changeCoord(id, newc);
                jGri.setCase(a.getId(), a.getEspece(), newc);
                jGri.videCase(c);
            }

        }

    }
}

void Jeu::deplace()
{
    deplaceLapin();
    deplaceRenard();
}

bool vectorContient(vector<int> vec, int x)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == x)
        {
            return true;
        }
    }
    return false;
}
