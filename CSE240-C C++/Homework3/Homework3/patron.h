/*
	A class declaration for the Patron class which contains private members
	firstName, lastName, and *patronString.
	Homework 3 Part 2
	Completion time: 15 min

	author: Anton Neuhold
	version: 1.0
*/

#include <iostream>
#include <string>

using namespace std;

/*
	Represents a Patron in a theatre.
*/
class Patron {
private:
	char firstName[30];
	char lastName[30];
	char *patronString;

public:
	Patron();
	Patron(char *patronInfo);
	~Patron();
	char* getLastName();
	char* getFirstName();
	char* toString();
};