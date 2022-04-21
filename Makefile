#all: main


main: animal.o util.o main.o
	g++ -std=c++11 -Wall -o main animal.o util.o main.o

# fichiers objets
main.o: main.cpp
	g++ -std=c++11 -Wall -c main.cpp
animal.o: animal.cpp animal.hpp
	g++ -std=c++11 -Wall -c animal.cpp
util.o: util.cpp util.hpp
	g++ -std=c++11 -Wall -c util.cpp

tests: test.o coord.o
	g++ -o tests test.o coord.o

clean:
	rm -f *.o main
