#include "generate_first_grid.h"
#include <stdio.h>
#include <stdlib.h>

int** generateBlankGrid() {
	int** firstGrid;
	firstGrid = calloc(GRID_SIZE, sizeof(int*));
	int i;
	for (i = 0; i < GRID_SIZE; i++) {
		firstGrid[i] = calloc(GRID_SIZE, sizeof(int));
	}
	return firstGrid;
}

coordinate randomColumnAndRow() {
	coordinate initcoord;
	initcoord.x = rand() % GRID_SIZE;
	initcoord.y = rand() % GRID_SIZE;
	return initcoord;
}

int twoOrFour() {
	int x = rand() % 10;

	if (x == 0) {
		x = 4;
	} else {
		x = 2;
	}

	return x;
}

int** addFirstTwoOrFourtoGrid(int** blankGrid) {
	int a = twoOrFour();
	int b = twoOrFour();
	coordinate coordOne = randomColumnAndRow();
	coordinate coordTwo = randomColumnAndRow();
	while (coordOne.x == coordTwo.x && coordOne.y == coordTwo.y) {
		coordTwo = randomColumnAndRow();
	}
	
	blankGrid[coordOne.x][coordOne.y] = a;
	blankGrid[coordTwo.x][coordTwo.y] = b;
	return blankGrid;
}

void printGrid(int** grid) {
	int i,j;
	for (i = 0; i < 4; i++) {
		printf(" | ");
		for (j = 0; j < 4; j++) {
			if (grid[i][j] == 0) {
				printf("     ");
			} else {
				printf("%4d ",grid[i][j]);
			}
		}
		printf("  |\n");
	}
}