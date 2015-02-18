all: main

main: main.cpp sudoku.h
	g++ -c main.cpp

clean: rm *.o main
