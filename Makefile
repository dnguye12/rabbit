all: main

LIBS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/lib

main: animal.o coord.o ensemble.o grille.o population.o jeu.o menu.o main.o
	g++ -std=c++11 -Wall $(LIBRARY_PATHS) -o main animal.o coord.o ensemble.o grille.o population.o menu.o jeu.o main.o $(LIBS)

# fichiers objets
main.o: main.cpp
	g++ -Wall -fexceptions -g $(INCLUDE_PATHS) -c main.cpp
animal.o: animal.cpp animal.hpp
	g++ -std=c++11 -Wall -c animal.cpp
coord.o: coord.cpp coord.hpp
	g++ -std=c++11 -Wall -c coord.cpp
ensemble.o: ensemble.cpp ensemble.hpp
	g++ -std=c++11 -Wall -c ensemble.cpp
grille.o: grille.cpp grille.hpp
	g++ -std=c++11 -Wall -c grille.cpp
population.o: population.cpp population.hpp
	g++ -std=c++11 -Wall -c population.cpp
jeu.o: jeu.cpp jeu.hpp
	g++ -std=c++11 -Wall -c jeu.cpp
menu.o: menu.cpp menu.hpp
	g++ -Wall -fexceptions -g $(INCLUDE_PATHS) -c menu.cpp

test: test.o coord.o jeu.o population.o animal.o grille.o
	g++ -o test test.o coord.o jeu.o population.o animal.o grille.o
test.o: test.cpp coord.hpp jeu.hpp population.cpp animal.cpp grille.cpp
	g++ -std=c++11 -Wall -c test.cpp jeu.hpp population.cpp animal.cpp grille.cpp

clean:
	rm -f *.o main
