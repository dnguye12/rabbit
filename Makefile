all: main


main: animal.o coord.o ensemble.o grille.o population.o jeu.o menu.o tilemap.o main.o
	g++ -std=c++11 -Wall -o main animal.o coord.o ensemble.o grille.o population.o menu.o jeu.o tilemap.o main.o

# fichiers objets
main.o: main.cpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c main.cpp obj/Debug/main.o
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
tilemap.o: tilemap.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c tilemap.hpp
menu.o: menu.cpp menu.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c menu.cpp obj/Debug/menu.o

test: test.o coord.o
	g++ -o test test.o coord.o
test.o: test.cpp coord.hpp
	g++ -std=c++11 -Wall -c test.cpp

clean:
	rm -f *.o main
