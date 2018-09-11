/*
	A command line program that takes patrons information and creates a
	seating chart for them in a theatre.
	Homework 3 Part 2
	Completion time: 20 min

	author: Anton Neuhold, Dr. Javier Gonzalez (Because it was copy pasted
	out of the assignment text)
	version: 1.0
*/

#include "theatre.h"

/*
	Tests part 2 of the homework by getting input from the user and running
	that input through the Theatre and Patron classes.
*/
int main() {
	Theatre* theatre;
	Patron* tempPatron;
	int row, col, rowNum, columnNum;
	char patronInfo[30];
	// Ask a user to enter a number of rows for a theatre seating
	cout << "Please enter a number of rows for a theatre seating.\n";
	cin >> rowNum;
	// Ask a user to enter a number of columns for a theatre seating
	cout << "Please enter a number of columns for a theatre seating.\n";
	cin >> columnNum;
	// theatre_seating
	theatre = new Theatre(rowNum, columnNum);
	cout << "Please enter a patron information or enter \"Q\" to quit.\n";
	/*** reading a patron's information ***/
	cin >> patronInfo;
	/* we will read line by line **/
	while (strcmp(patronInfo, "q")) {
		cout << "A patron information is read.\n";
		// printing information.
		cout << patronInfo;
		// patron
		tempPatron = new Patron(patronInfo);
		// Ask a user to decide where to seat a patron by asking
		// for row and column of a seat
		cout << "Please enter a row number where the patron wants to sit."
			<< endl;
		cin >> row;
		cout << "Please enter a column number where the patron wants to sit."
			<< endl;
		cin >> col;
		// Checking if the row number and column number are valid
		// (exist in the theatre that we created.)
		if (theatre->checkBoundaries(row, col) == false) {
			cout << "row or column number is not valid.\n";
			cout << "A patron" << (*tempPatron).getFirstName() << " " <<
				(*tempPatron).getLastName() << " is not assigned a seat.\n";
		}
		else {
			// Assigning a seat for a patron
			if (theatre->assignPatronAt(row, col, tempPatron) == true) {
				cout << "\nThe seat at row " << row << " and column " << col
					<< " is assigned to the patron, "
					<< tempPatron->toString() << endl;
				cout << theatre->toString() << endl;
			}
			else {
				cout << "\nThe seat at row " << row << " and column " 
					<< col << " is taken." << endl;
			}
		}
		// Read the next patronInfo
		cout << "Please enter a patron information or enter \"Q\" to quit.";
		/*** reading a patron's information ***/
		cin >> patronInfo;
	}
	delete theatre;
}