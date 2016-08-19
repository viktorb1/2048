#include "generate_next_grid.h"
#include "generate_first_grid.h"

int** generateLeftGrid(int** grid) {
	int **nextGrid = generateBlankGrid();
	int i, j, column = 0;

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			nextGrid[i][j] = grid[i][j];
		}
	}

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (nextGrid[i][j] != 0) {
				nextGrid[i][column] = nextGrid[i][j];

				if (j != column) {
					nextGrid[i][j] = 0;
				}

			column++;
			}
			
		}
		column = 0;
	}

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < (GRID_SIZE-1); j++) {
			if (nextGrid[i][j] == nextGrid[i][j+1]) {
				nextGrid[i][j] = 2*nextGrid[i][j];
				nextGrid[i][j+1] = 0;
			}
		}
	}

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (nextGrid[i][j] != 0) {
				nextGrid[i][column] = nextGrid[i][j];

				if (j != column) {
					nextGrid[i][j] = 0;
				}

			column++;
			}
			
		}
		column = 0;
	}

	return nextGrid;
}

int** generateRightGrid(int** grid) {
	int **nextGrid = generateBlankGrid();

	int i, j, column = (GRID_SIZE-1);

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			nextGrid[i][j] = grid[i][j];
		}
	}

	for (i = (GRID_SIZE-1); i >= 0; i--) {
		for (j = (GRID_SIZE-1); j >= 0; j--) {
			if (nextGrid[i][j] != 0) {
				nextGrid[i][column] = nextGrid[i][j];

				if (j != column) {
					nextGrid[i][j] = 0;
				}

			column--;
			}
			
		}
		column = (GRID_SIZE-1);
	}

	for (i = (GRID_SIZE-1); i >= 0; i--) {
		for (j = (GRID_SIZE-1); j > 0; j--) {
			if (nextGrid[i][j] == nextGrid[i][j-1]) {
				nextGrid[i][j] = 2*nextGrid[i][j];
				nextGrid[i][j-1] = 0;
			}
		}
	}

	for (i = (GRID_SIZE-1); i >= 0; i--) {
		for (j = (GRID_SIZE-1); j >= 0; j--) {
			if (nextGrid[i][j] != 0) {
				nextGrid[i][column] = nextGrid[i][j];

				if (j != column) {
					nextGrid[i][j] = 0;
				}

			column--;
			}
			
		}
		column = (GRID_SIZE-1);
	}

	return nextGrid;
}

int** generateUpGrid(int** grid) {
	int **nextGrid = generateBlankGrid();

	int i, j, row = 0;

	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			nextGrid[i][j] = grid[i][j];
		}
	}


	for (j = 0; j < GRID_SIZE; j++) {
		for (i = 0; i < GRID_SIZE; i++) {
			if (nextGrid[i][j] != 0) {
				nextGrid[row][j] = nextGrid[i][j];

			if (i != row) {
				nextGrid[i][j] = 0;
			}

			row++;
			}
			
		}
		row = 0;
	}

	for (j = 0; j < GRID_SIZE; j++) {
		for (i = 0; i < (GRID_SIZE-1); i++) {
			if (nextGrid[i][j] == nextGrid[i+1][j]) {
				nextGrid[i][j] = 2*nextGrid[i][j];
				nextGrid[i+1][j] = 0;
			}
		}
	}

	for (j = 0; j < GRID_SIZE; j++) {
		for (i = 0; i < GRID_SIZE; i++) {
			if (nextGrid[i][j] != 0) {
				nextGrid[row][j] = nextGrid[i][j];

			if (i != row) {
				nextGrid[i][j] = 0;
			}

			row++;
			}
			
		}
		row = 0;
	}	

	return nextGrid;
}

int** generateDownGrid(int** grid) {
	int **nextGrid = generateBlankGrid();
	
	int i, j, row = (GRID_SIZE-1);
	
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			nextGrid[i][j] = grid[i][j];
		}
	}

	for (j = (GRID_SIZE-1); j >= 0; j--) {
		for (i = (GRID_SIZE-1); i >= 0; i--) {
			if (nextGrid[i][j] != 0) {
				nextGrid[row][j] = nextGrid[i][j];

			if (i != row) {
				nextGrid[i][j] = 0;
			}

			row--;
			}
			
		}
		row = (GRID_SIZE-1);
	}

	for (j = (GRID_SIZE-1); j >= 0; j--) {
		for (i = (GRID_SIZE-1); i > 0; i--) {
			if (nextGrid[i][j] == nextGrid[i-1][j]) {
				nextGrid[i][j] = 2*nextGrid[i][j];
				nextGrid[i-1][j] = 0;
			}
		}
	}

	for (j = (GRID_SIZE-1); j >= 0; j--) {
		for (i = (GRID_SIZE-1); i >= 0; i--) {
			if (nextGrid[i][j] != 0) {
				nextGrid[row][j] = nextGrid[i][j];

			if (i != row) {
				nextGrid[i][j] = 0;
			}

			row--;
			}
			
		}
		row = (GRID_SIZE-1);
	}

	return nextGrid;
}

int** addNewTwoOrFour(int** grid) {
	coordinate coordinate = randomColumnAndRow();

	while (grid[coordinate.y][coordinate.x] != 0) {
		coordinate = randomColumnAndRow();
	}

	grid[coordinate.y][coordinate.x] = twoOrFour();

	return grid;
}