/*
	A class declaration for the Theatre class which contains a 2d array of
	Patron objects, *theatreString, numRows, and numCols.
	Homework 3 Part 2
	Completion time: 15 min

	author: Anton Neuhold
	version: 1.0
*/

#include "patron.h"

/*
	Represents a Theatre seating array holding patrons in each seat.
*/
class Theatre {
private:
	Patron **seating;
	char *theatreString;
	int numRows;
	int numCols;

public:
	Theatre(int rowNum, int columnNum);
	~Theatre();
	Patron* getPatronAt(int row, int col);
	bool assignPatronAt(int row, int col, Patron *tempPatron);
	bool checkBoundaries(int row, int col);
	char* toString();
};