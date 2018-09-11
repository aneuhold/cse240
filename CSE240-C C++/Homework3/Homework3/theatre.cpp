/*
	Contains the implementation for the functions of the Theatre class.
	Homework 3 Part 2
	Completion time: 4 hours

	author: Anton Neuhold
	version: 1.0
*/

#include "theatre.h"

/*
	Initializes a theater seating 2d array with the designated rows and
	cols. Each location in the theater seating 2 dimensional array will be
	filled with the default patron.
	int rowNum: the number of rows to use for the theater seating
	int columnNum: the number of columns to use for the theater seating
*/
Theatre::Theatre(int rowNum, int columnNum) {
	this->numRows = rowNum;
	this->numCols = columnNum;
	this->seating = new Patron*[rowNum];
	for (int row = 0; row < rowNum; row++) {
		this->seating[row] = new Patron[columnNum];
	}
}

/*
	Deconstructs this Theatre instance by removing each row of Patrons, then
	the 2d array, then the theatreString.
*/
Theatre::~Theatre() {
	for (int row = 0; row < numRows; row++) {
		delete[] this->seating[row];
	}
	delete[] this->seating;
	delete[] this->theatreString;
}

/*
	Gets the patron at the designated row and column then returns it. 
	int row: the row to get the patron from
	int col: the col to get the patron from
	returns NULL if there does not exist a patron at that location
*/
Patron* Theatre::getPatronAt(int row, int col) {
	if (checkBoundaries(row, col)) {
		return &this->seating[row][col];
	}
	else {
		return NULL;
	}
}

/*
	Attempts to assign a patron to the given row and column location. It will
	successfully assign a patron if there are no other patrons located there.
	int row: the row to assign the patron
	int col: the col to assign the patron
	Patron *tempPatron: the patron to assign to the given row and column
	returns: true if the Patron was successfully assigned to the seat
*/
bool Theatre::assignPatronAt(int row, int col, Patron *tempPatron) {
	if (checkBoundaries(row, col) &&
		!strcmp(this->seating[row][col].getFirstName(), "***") &&
		!strcmp(this->seating[row][col].getLastName(), "***")) {
		this->seating[row][col] = *tempPatron;
		return true;
	}
	else {
		return false;
	}
}

/*
	Checks the given row and column number to see if it breaks the boundaries
	of this theatre seating array.
	int row: the row number
	int col: the column number
	returns: true if the seating location is valid, and false otherwise
*/
bool Theatre::checkBoundaries(int row, int col) {
	if (row >= 0 &&
		row < this->numRows &&
		col >= 0 &&
		col < this->numCols) {
		return true;
	}
	else {
		return false;
	}
}

/*
	Returns a memory safe character array of each patron in the theater 
	seating array in a 2d grid using the toString function of the patron 
	structure.
*/
char* Theatre::toString() {
	string str;
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			str = str + seating[row][col].toString() + " ";
		}
		str = str + "\n";
	}
	delete[] theatreString;
	theatreString = new char[str.length()+1];
	strcpy(theatreString, str.c_str());
	return theatreString;
}