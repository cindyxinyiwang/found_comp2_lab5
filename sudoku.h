/* Xinyi Wang
 * cse20212 sp2015 lab5
 * sudoku.h
 *
 * a templated class to read and display sudoku
 */
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
class sudoku;

template <typename T>
ostream &operator<<(ostream&, const sudoku<T>&);

template <typename T>
class sudoku {
	friend ostream &operator<< <T>(ostream&, const sudoku<T>&);

	public:
		sudoku();	// empty constructor
		void readData(string);	// put	file data into v2d	
		//void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ");	// split the string
	private:
		vector<vector<T> > v2d;

};

template <typename T>
sudoku<T>::sudoku() {

}
// overloaded output operator
template <typename T>
ostream &operator<<(ostream &output, const sudoku<T> &puz){
	for (vector<vector<T> >::const_iterator row = (puz.v2d).begin(); row != (puz.v2d).end(); ++row){
		for (vector<T>::const_iterator col = row->begin(); col != row->end(); ++ col) {
			output << *col << " ";
		}
		output << "\n";
	}
}
template <typename T>
void sudoku<T>::readData(string filename) {
	ifstream mfile(filename);
	string line;
	if (mfile.is_open()) {
		while (getline( mfile, line)) {
			vector<T> currentVec;
			stringstream stream(line);
			T n;
			while (stream >> n) {
				currentVec.push_back(n);
			}
			v2d.push_back(currentVec);
		}
	mfile.close();
	}
}

/*
template <typename T>
void sudoku<T>::tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ") {
	// skip delimiters at beginning
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// find first non-delimiter
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos) {
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}

}
*/

#endif
