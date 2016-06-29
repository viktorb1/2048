#include "checks.h"
#include "generate_first_grid.h"
#include "generate_next_grid.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int showMainMenu();
int** addNewTwoOrFour(int** grid);

int main() {
	int option = showMainMenu();
	if (option == 1) {
		system("clear");
		srand(time(NULL));
		int** currentgrid = generateBlankGrid();
		addFirstTwoOrFourtoGrid(currentgrid);
		int** nextgrid = generateBlankGrid();

		for (int i = 0; i < (GRID_SIZE); i++) {
			for (int j = 0; j < (GRID_SIZE); j++) {
				nextgrid[i][j] = currentgrid[i][j];
			}
		}

		printGrid(currentgrid);

		printf("\n You started a new game!\n");
		printf(" Press 'q' to quit.\n w/a/s/d to move grid\n");
		
		int move;
		while ((move = getchar()) != 'q') {
			if (move == 'a') {
				system("clear");
				nextgrid = generateLeftGrid(currentgrid);
				int x = checkIfGridsAreTheSame(nextgrid, currentgrid);
				if (x == 1) {
					currentgrid = nextgrid;
					currentgrid = addNewTwoOrFour(currentgrid);
				}
				printGrid(currentgrid);
				checkAndStoreHighScore(currentgrid);
				checkIf2048(currentgrid);
				checkifGameOver(currentgrid);
			} else if (move == 'd') {
				system("clear");
				nextgrid = generateRightGrid(currentgrid);
				int x = checkIfGridsAreTheSame(nextgrid, currentgrid);
				if (x == 1) {
					currentgrid = nextgrid;
					currentgrid = addNewTwoOrFour(currentgrid);
				}
				printGrid(currentgrid);
				checkAndStoreHighScore(currentgrid);
				checkIf2048(currentgrid);
				checkifGameOver(currentgrid);
			} else if (move == 'w') {
				system("clear");
				nextgrid = generateUpGrid(currentgrid);
				int x = checkIfGridsAreTheSame(nextgrid, currentgrid);
				if (x == 1) {
					currentgrid = nextgrid;
					currentgrid = addNewTwoOrFour(currentgrid);
				}
				printGrid(currentgrid);
				checkAndStoreHighScore(currentgrid);
				checkIf2048(currentgrid);
				checkifGameOver(currentgrid);
			} else if (move == 's') {
				system("clear");
				nextgrid = generateDownGrid(currentgrid);
				int x = checkIfGridsAreTheSame(nextgrid, currentgrid);
				if (x == 1) {
					currentgrid = nextgrid;
					currentgrid = addNewTwoOrFour(currentgrid);
				}
				printGrid(currentgrid);
				checkAndStoreHighScore(currentgrid);
				checkIf2048(currentgrid);
				checkifGameOver(currentgrid);
			} else {
				if (move != '\n') {
					printf("Invalid move\n");
				}
			}
		}

	} else if (option == 2) {
		FILE *fp = fopen("highscore.txt","r");
		char scorestr[4];
		fgets(scorestr, 4, fp);

		printf("The high score is: %s\n",scorestr);



	} else {
		printf("Bye!\n");
	}

	return EXIT_SUCCESS;
} 

