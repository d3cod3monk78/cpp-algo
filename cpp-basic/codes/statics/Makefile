all: test

test: Main.o Statics.o
	g++ -Wall -o test Main.o Statics.o -std=c++17

Main.o: Main.cpp
	g++ -Wall -c Main.cpp -std=c++17

Statics.o: Statics.cpp
	g++ -Wall -c Statics.cpp -std=c++17

clean:
	rm *.o test