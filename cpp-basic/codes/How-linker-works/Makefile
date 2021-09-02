.PHONY: all test Main.o Log.o clean

all: test

test: Main.o Log.o
	g++ -Wall -o test Main.o Log.o -std=c++17

Main.o: Main.cpp
	g++ -Wall -c Main.cpp -std=c++17

Log.o: Log.cpp
	g++ -Wall -c Log.cpp -std=c++17

just:
	g++ -Wall -o test Main.cpp -std=c++17

clean:
	rm *.o test