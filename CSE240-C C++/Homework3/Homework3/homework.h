/*
	A class declaration for the Homework class which contains a 2d array of
	Patron objects, *theatreString, numRows, and numCols.
	Homework 3 Part 1
	Completion time: 10 min

	author: Anton Neuhold
	version: 1.0
*/

#include <iostream>
using namespace std;

/*
	Represents a small suite of functions including selection sort, printing
	an array, factorial, and initializing an array.
*/
class Homework {
public:
	void initialize_array(int *int_array, int array_size);
	void print_array(int *int_array, int size);
	void selection_sort(int *int_array, int size);
	int factorial(int n);
};