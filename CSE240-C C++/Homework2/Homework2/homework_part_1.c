/*	
	A C file for the first step of homework 2. It goes over a few basic static
	methods such as printing an integer array and selection sort.
	Homework 2 Part 1
	Completion time: 1 hour

	author: Anton Neuhold
	version: 1.0
*/
#include <stdio.h>

/*
	Initializes the array passed into the function with 0s in even positions
	and 1s in odd positions.
	int_array: a pointer to the array to be initialized
	size: the size of the array
*/
void initialize_array(int *int_array, int size) {
	for (int i = 0; i < size; i++) {
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
void print_array(int *int_array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", int_array[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("\n");
}

/*
	Sorts the integer array passed into the function with the selection sort
	algorithm from biggest to smallest values. 
	int_array: a pointer to the array to be sorted
	size: the size of the array
*/
void selection_sort(int *int_array, int size) {
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
int factorial(int n) {
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

/*
	Tests this file for bugs.
*/
main() {
	int a[10] = { 3, 5, 6, 8, 12, 13, 16, 17, 18, 20 };
	int b[6] = { 18, 16, 19, 3 ,14, 6 };
	int c[5] = { 5, 2, 4, 3, 1 };

	// testing initialize_array
	print_array(a, 10); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
	initialize_array(a, 10);
	print_array(a, 10); // print: 0, 1, 0, 1, 0, 1, 0, 1, 0, 1
	// testing initialize_array
	print_array(b, 6); // print: 18, 16, 19, 3 ,14, 6
	selection_sort(b, 6);
	print_array(b, 6); // print: 19, 18, 16, 14, 6, 3
	// testing factorial
	printf("Factorail of 5 - %d\n", factorial(5)); //print: 120
	c[0] = factorial(c[0]);
	c[1] = factorial(c[2]);
	print_array(c, 5); // print: 120, 24, 4, 3, 1
	return 0;
}