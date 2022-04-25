#ifndef ANIMAL_HPP_INCLUDED
#define ANIMAL_HPP_INCLUDED

#include <string>

#include "coord.hpp"
#include "ensemble.hpp"

using namespace std;

enum class Espece {renard, lapin, rien};

class Animal {
private:
    int aId;
    int age = 0;
    int maxAge = 30;
    Espece aType;
    Coord aCoord;

    //stats lapin
    int MinFreeBirthLapin = 4;
    int ProbReproLapin = 50;

    //stats renard
    int FoodInit = 5;
    int FoodLapin = 5;
    int FoodReprod = 8;
    int MaxFood = 10;
    int ProbBirthRenard = 5;
public:
    //Constructors
    Animal();
    Animal(int id, Espece type, Coord coord);

    //Methods
    int getId() const;

    Coord getCoord() const;

    void setCoord(Coord c);

    Espece getEspece() const;

    string toString() const;

    int getMinFreeBirthLapin() const;

    int getProbReproLapin() const;




    int getAge() const;

    int getMaxAge() const;

    int aged();



    int getFoodInit() const;

    void setFoodInit(int i);

    int getFoodLapin() const;

    int getFoodReprod() const;

    int getMaxFood() const;

    int getProbBirthRenard() const;
};

bool operator==(Animal a1, Animal a2);

#endif // ANIMAL_HPP_INCLUDED
