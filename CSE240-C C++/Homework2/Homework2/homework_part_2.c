/*
	A command line program that takes patrons information and creates a 
	seating chart for them in a theatre.
	Homework 2 Part 2
	Completion time: 5 hours

	author: Anton Neuhold
	version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Holds the information for a patron.
*/
struct patron {
	char last_name[30];
	char first_name[30];
};

/*
	Holds the 2d seating array where each location has a patron structure in it.
*/
struct theatre_seating {
	struct patron **seating;
	int num_rows;
	int num_cols;
};

/*
	Initializes the patron structure with "***" for the first name, and "***" 
	for the last name.
	struct patron *p: a pointer to the patron structure that will be initialized 
	with the default values
*/
void patron_init_default(struct patron *p) {
	strcpy(p->first_name, "***");
	strcpy(p->last_name, "***");
}

/*
	Initializes the patron structure with the first and last name held in the
	info string
	struct patron *p: a pointer the patron structure that will be assigned the
	first and last name from info
	char *info: the pointer to the string that contains the first and last name
	delimited by a '/'
*/
void patron_init(struct patron *p, char *info) {
	char *token;
	token = strtok(info, "/");
	strcpy(p->first_name, token);
	token = strtok(NULL, "/");
	strcpy(p->last_name, token);
}

/*
	Prints the first initial and last initial of the patron structure that is
	passed to it. For example if the first name is "Mickey" and the last name
	is "Mouse" then it will print "M.M."
	struct patron *p: a pointer the patron structure that will have its first
	and last initials printed
*/
void patron_to_string(struct patron *p) {
	char initials[] = { p->first_name[0], '.', p->last_name[0], '.', '\0'};
	printf("%s", initials);
}

/*
	Initializes a theater seating structure with the designated rows and cols.
	Each location in the theater seating 2 dimensional array will be
	filled with the default patron.
	int rowNum: the number of rows to use for the theater seating
	int columnNum: the number of columns to use for the theater seating
	struct theatre_seating *t: a pointer to the theater seating structure that
	should be initialized
*/
void theatre_seating_init(int rowNum, int columnNum, 
	struct theatre_seating *t) {
	t->num_rows = rowNum;
	t->num_cols = columnNum;
	t->seating = (struct patron **) malloc(rowNum * sizeof(struct patron *));
	for (int row = 0; row < rowNum; row++) {
		t->seating[row] = (struct patron **) malloc(
			columnNum * sizeof(struct patron));
		for (int col = 0; col < columnNum; col++) {
			struct patron temp_patron;
			patron_init_default(&temp_patron);
			t->seating[row][col] = temp_patron;
		}
	}
}

/*
	Checks the given row and column number to see if it breaks the boundaries
	of the given theater seating structure.
	int row: the row number
	int col: the column number
	struct theatre_seating *t: the theater seating structure to use when testing
	the valid boundary
	returns: true if the seating location is valid, and false otherwise.
*/
int check_boundaries(int row, int col, struct theatre_seating *t) {
	if (row >= 0 &&
		row < t->num_rows &&
		col >= 0 &&
		col < t->num_cols) {
		return 1;
	}
	else {
		return 0;
	}
}

/*
	Attempts to assign a patron to the given row and column location. It will
	successfully assign a patron if there are no other patrons located there.
	int row: the row to assign the patron
	int col: the col to assign the patron
	struct theatre_seating *t: the theater seating structure to use when
	assigning the patron
	struct patron* p: the patron to assign to the given row and column
*/
int assign_patron_at(int row, int col, struct theatre_seating *t, 
	struct patron* p) {
	if (check_boundaries(row, col, t) &&
		!strcmp(t->seating[row][col].first_name, "***") &&
		!strcmp(t->seating[row][col].last_name, "***")) {
		t->seating[row][col] = *p;
		return 1;
	}
	else {
		return 0;
	}
}

/*
	Prints each patron in the theater seating structure in a 2d grid using
	the print function of the patron structure. 
	struct theatre_seating *t: the theater seating grid to print
*/
void theatre_seating_to_string(struct theatre_seating *t) {
	for (int row = 0; row < t->num_rows; row++) {
		for (int col = 0; col < t->num_cols; col++) {
			patron_to_string(&t->seating[row][col]);
			printf(" ");
		}
		printf("\n");
	}
}

/*
	Tests this file and handles the user input and interaction.
*/
void main() {
	struct theatre_seating theatre_seating;
	struct patron temp_patron;

	int row, col, rowNum, columnNum;

	char patron_info[30];
	// Ask a user to enter a number of rows for a theatre seating
	printf("Please enter a number of rows for a theatre seating.\n");
	scanf("%d", &rowNum);

	// Ask a user to enter a number of columns for a theatre seating
	printf("Please enter a number of columns for a theatre seating.\n");
	scanf("%d", &columnNum);
	// theatre_seating
	theatre_seating_init(rowNum, columnNum, &theatre_seating);

	printf("Please enter a patron information or enter \"Q\" to quit.\n");
	/*** reading a patron's information ***/
	scanf("%s", patron_info);
	/* we will read line by line **/
	while (strcmp(patron_info, "q")) {
		printf("A patron information is read.\n");
		// printing information.
		printf("%s", patron_info);
		// patron
		patron_init(&temp_patron, patron_info);
		// Ask a user to decide where to seat a patron by asking
		// for row and column of a seat
		printf("Please enter a row number where the patron wants to sit.\n");
		scanf("%d", &row);
		printf("Please enter a column number where the patron wants to sit.\n");
		scanf("%d", &col);
		// Checking if the row number and column number are valid
		// (exist in the theatre that we created.)
		if (check_boundaries(row, col, &theatre_seating) == 0) {
			printf("row or column number is not valid.\n");
			printf("A patron %s %s is not assigned a seat.", 
				temp_patron.first_name, temp_patron.last_name);
		}
		else {
			// Assigning a seat for a patron
			if (assign_patron_at(row, col, &theatre_seating, &temp_patron) == 1) {
				printf("\nThe seat at row %d and column %d is assigned to the patron ", row, col);
				patron_to_string(&temp_patron);
				printf("\n");
				theatre_seating_to_string(&theatre_seating);
			}
			else {
				printf("\nThe seat at row %d and column %d is taken.", row, col);
			}
		}
		// Read the next patronInfo
		printf("Please enter a patron information or enter \"Q\" to quit.\n");
		/*** reading a patron's information ***/
		scanf("%s", patron_info);
	}
}