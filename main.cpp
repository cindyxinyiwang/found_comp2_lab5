/* Xinyi Wang
 * sp2015 cse20212 lab5
 * main.cpp
 *
 * driver program to read and print out sudoku
 */

#include <iostream>
#include "sudoku.h"

using namespace std;

int main() {
	Sudoku<int> mysudoku;
	mysudoku.readData("input.txt");

}
