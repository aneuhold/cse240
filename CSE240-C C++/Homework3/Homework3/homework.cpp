/*
	C++ class for the first step of homework 3. It goes over a few basic
	functions such as printing an integer array and selection sort. This
	is the section that implements the Homework class.
	Homework 3 Part 1
	Completion time: 1 hour

	author: Anton Neuhold
	version: 1.1
*/

#include "homework.h"

/*
	Initializes the array passed into the function with 0s in even positions
	and 1s in odd positions.
	int_array: a pointer to the array to be initialized
	array_size : the size of the array
*/
void Homework::initialize_array(int *int_array, int array_size) {
	for (int i = 0; i < array_size; i++) {
		if (i % 2 == 0) {
			int_array[i] = 0;
		}
		else {
			int_array[i] = 1;
		}
	}
}

/*
	Prints the array that is passed into the function by seperating it's
	values with commas.
	int_array: a pointer to the array to be printed
	size: the size of the array
*/
void Homework::print_array(int *int_array, int size) {
	for (int i = 0; i < size; i++) {
		cout << int_array[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

/*
	Sorts the integer array passed into the function with the selection sort
	algorithm from biggest to smallest values.
	int_array: a pointer to the array to be sorted
	size: the size of the array
*/
void Homework::selection_sort(int *int_array, int size) {
	int max, temp;
	for (int i = 0; i < size - 1; i++) {
		max = i;
		for (int scan = i + 1; scan < size; scan++) {
			if (int_array[scan] > int_array[max]) { max = scan; }
		}
		temp = int_array[max];
		int_array[max] = int_array[i];
		int_array[i] = temp;
	}
}

/*
	Returns the factorial of the integer passed to the function.
	n: the integer to calculate the factorial of
	returns: the integer representing the factorial
*/
int Homework::factorial(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}