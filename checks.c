#include "generate_first_grid.h"
#include "checks.h"
#include <stdio.h>
#include <stdlib.h>

void checkIf2048(int** grid) {
	int i, j;
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (grid[i][j] == 2048) {
				printf("Congrats! You won the game!");
				exit(EXIT_SUCCESS);
			}
		}
	}
}

void checkifGameOver(int** grid) {
	int i, j, count = 0;
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (grid[i][j] == 0) {
				count++;
			}
		}
	}

	int k = 0;
	if (count == 0) {
		for (i = 0; i < GRID_SIZE; i++) {
			for (j = 0; j < GRID_SIZE; j++) {
				if (i < (GRID_SIZE-1) && j < (GRID_SIZE-1)) {
					if ((grid[i][j] == grid[i][j+1]) || (grid[i][j] == grid[i+1][j])) {
					k++;
				}
			}

				if (i == (GRID_SIZE-1) && j < (GRID_SIZE-1)) {
					if ((grid[i][j] == grid[i][j+1])) {
						k++;
					}
				}

				if (j == (GRID_SIZE-1) && i < (GRID_SIZE-1)) {
					if ((grid[i][j] == grid[i+1][j])) {
						k++;
					}
				}
			}
		}
		if (k == 0) {
			printf("\n Game Over!\n");
			exit(EXIT_SUCCESS);
		}
	}
}

void checkAndStoreHighScore(int** grid) {
	FILE *fp = fopen("highscore.txt", "r");


	int score = 0;
	if (fp == NULL) {
		fp = fopen("highscore.txt", "w");
	} else {
		char scorestr[4];
		int num, len = 0;

	 	while((num = fgetc(fp)) != EOF && num != '\n'){
	        scorestr[len++] = num;
		}

		score = atoi(scorestr);
	}
	

	int i, j;
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (grid[i][j] > score) {
				char newscore[4]; 
				sprintf(newscore, "%d\n", grid[i][j]);
				fp = fopen("highscore.txt","w");
				fprintf(fp, newscore);
			}
		}
	}
	fclose(fp);
}

int checkIfGridsAreTheSame(int** currentgrid, int** nextgrid) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (currentgrid[i][j] != nextgrid[i][j]) {
				return 1;
			}
		}
	}

	return 0;
}
