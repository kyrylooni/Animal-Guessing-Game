CCXFLAGS = -Wall -g -std=c++11

all: AnimalGame



AnimalGame.o: AnimalGame.cpp animal.h 
	g++ $(CCXFLAGS) -c AnimalGame.cpp



animal.o: animal.cpp animal.h
	g++ $(CCXFLAGS) -c animal.cpp

AnimalGame: AnimalGame.o animal.o
	g++ $(CCXFLAGS) -o AnimalGame AnimalGame.o animal.o


clean:
	rm -f AnimalGame *.o




