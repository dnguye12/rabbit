#all: main
#info-111 g++ main.cpp animal.cpp coord.cpp ensemble.cpp grille.cpp population.cpp jeu.cpp menu.cpp -o main -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
main: animal.o coord.o ensemble.o grille.o population.o jeu.o menu.o main.o
	g++ -L/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/lib -o main animal.o coord.o ensemble.o grille.o population.o menu.o jeu.o main.o -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# fichiers objets
main.o: main.cpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c main.cpp
animal.o: animal.cpp animal.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c animal.cpp
coord.o: coord.cpp coord.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c coord.cpp
ensemble.o: ensemble.cpp ensemble.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c ensemble.cpp
grille.o: grille.cpp grille.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c grille.cpp
population.o: population.cpp population.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c population.cpp
jeu.o: jeu.cpp jeu.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c jeu.cpp
menu.o: menu.cpp menu.hpp
	g++ -Wall -fexceptions -g -I/home/tp-home011/07423cc3-2cb5-4121-a984-6deee5e7a545/SFML-2.5.1/include -c menu.cpp

test: test.o coord.o jeu.o population.o animal.o grille.o
	g++ -o test test.o coord.o jeu.o population.o animal.o grille.o
test.o: test.cpp coord.hpp jeu.hpp population.cpp animal.cpp grille.cpp
	g++ -std=c++11 -Wall -c test.cpp jeu.hpp population.cpp animal.cpp grille.cpp

no-sfml: animal.o coord.o ensemble.o grille.o population.o jeu.o no-sfml.o
	g++ -std=c++11 -Wall -o no-sfml animal.o coord.o ensemble.o grille.o population.o jeu.o no-sfml.o
no-sfml.o: no-sfml.cpp
	g++ -std=c++11 -Wall -c no-sfml.cpp

clean:
	rm -f *.o main
