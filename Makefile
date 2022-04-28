all: main


main: animal.o coord.o ensemble.o grille.o population.o jeu.o main.o
	g++ -std=c++11 -Wall -o main animal.o coord.o ensemble.o grille.o population.o jeu.o menu.o main.o

# fichiers objets
main.o: main.cpp
	info-111 g++ main.cpp -o main -lsfml-system -lsfml-window -lsfml-graphics
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
	info-111 g++ menu.cpp -o menu -lsfml-system -lsfml-window -lsfml-graphics

test: test.o coord.o
	g++ -o test test.o coord.o
test.o: test.cpp coord.hpp
	g++ -std=c++11 -Wall -c test.cpp

clean:
	rm -f *.o main
