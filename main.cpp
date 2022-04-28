#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "jeu.hpp"
#include "menu.hpp"
#include "tilemap.hpp"

using namespace std;
using namespace sf;


int main()
{
    Menu m{960, 720};
    m.MainMenu();


    return 0;
}
