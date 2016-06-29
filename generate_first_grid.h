#ifndef _GENERATE_FIRST_GRID_H_
#define _GENERATE_FIRST_GRID_H_

#define GRID_SIZE 4

typedef struct coordinate {
	int x, y;
} coordinate;

/*Returns a blank grid at start of game*/
int** generateBlankGrid();

/*Returns a random coordinate*/
coordinate randomColumnAndRow();

/*Returns a 2 (90% chance) or a 4 (10% chance)*/
int twoOrFour();

/*Modifies and returns an array with two non-zero values*/
int** addFirstTwoOrFourtoGrid(int** blankGrid);

/*Prints Grid to screen*/
void printGrid(int** grid);

#endif