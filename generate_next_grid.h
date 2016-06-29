#ifndef _GENERATE_NEXT_GRID_H
#define _GENERATE_NEXT_GRID_H

/*Generates grid when user presses Left key*/
int** generateLeftGrid(int** grid);

/*Generates grid when user presses Right key*/
int** generateRightGrid(int** grid);

/*Generates grid when user presses Up key*/
int** generateUpGrid(int** grid);

/*Generates grid when user presses Down key*/
int** generateDownGrid(int** grid);

/*Adds a new block to the grid after each sucessful move*/
int** addNewTwoOrFour(int** grid);

#endif