/*
	Contains the implementation for the members of the Patron class.
	Homework 3 Part 2
	Completion time: 3 hours

	author: Anton Neuhold
	version: 1.0
*/

#include "patron.h"

/*
	Initializes this patron object with "***" for the first name, and "***"
	for the last name.
*/
Patron::Patron() {
	strcpy(this->firstName, "***");
	strcpy(this->lastName, "***");
	patronString = NULL;
};

/*
	Initializes this patron object with the first and last name held in the
	info string seperated by a '/'.
	char *patrongInfo: the pointer to the string that contains the first 
	and last name delimited by a '/'
*/
Patron::Patron(char *patronInfo) {
	strcpy(this->firstName, strtok(patronInfo, "/"));
	strcpy(this->lastName, strtok(NULL, "/"));
}

/*
	Deconstructs this patron object by deleting the patronString.
*/
Patron::~Patron() {
	delete[] this->patronString;
}

/*
	Returns the lastName of this Patron object.
*/
char* Patron::getLastName() {
	return this->lastName;
}

/*
	Returns the firstName of this Patron object.
*/
char* Patron::getFirstName() {
	return this->firstName;
}

/*
	Returns a memory safe character array of the first initial and last initial 
	of this Patron object. For example if the first name is "Mickey" 
	and the last name is "Mouse" then it will return "M.M."
*/
char* Patron::toString() {
	char initials[] = { this->firstName[0], '.', this->lastName[0], '.', '\0' };
	delete[] patronString;
	patronString = new char[5];
	strcpy(patronString, initials);
	return patronString;
}