#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

void printGrid(int** tile);
int** generateFirstGrid();
int** generateLeftGrid(int** tile);
int** generateRightGrid(int** tile);
int** generateUpGrid(int** tile);
int** generateDownGrid(int** tile);
int showMainMenu();
int** addNewTwoOrFour(int** tile);
int intComp(int** currentTile, int** nextTile);
int** addFirstTwoOrFourtoTile(int** firstTile);
void checkIf2048(int** tile);
void checkAndStoreHighScore(int** tile);

int main() {

	int option = showMainMenu();
	if (option == 1) {
		system("cls");
		srand(time(NULL));
		int** currentTile = generateFirstGrid();
		addFirstTwoOrFourtoTile(currentTile);
		int** nextTile = generateFirstGrid();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				nextTile[i][j] = currentTile[i][j];
			}
		}

		printGrid(currentTile);

		printf("\n You started a new game!\n");
		printf(" Press 'q' to quit.\n w/a/s/d to move grid\n");
		
		int move;
		while ((move = getchar()) != 'q') {
			if (move == 'a') {
				system("cls");
				nextTile = generateLeftGrid(currentTile);
				int x = intComp(nextTile, currentTile);
				if (x == 1) {
					currentTile = nextTile;
					currentTile = addNewTwoOrFour(currentTile);
				}
				printGrid(currentTile);
				checkAndStoreHighScore(currentTile);
				checkIf2048(currentTile);
			} else if (move == 'd') {
				system("cls");
				nextTile = generateRightGrid(currentTile);
				int x = intComp(nextTile, currentTile);
				if (x == 1) {
					currentTile = nextTile;
					currentTile = addNewTwoOrFour(currentTile);
				}
				printGrid(currentTile);
				checkAndStoreHighScore(currentTile);
				checkIf2048(currentTile);
			} else if (move == 'w') {
				system("cls");
				nextTile = generateUpGrid(currentTile);
				int x = intComp(nextTile, currentTile);
				if (x == 1) {
					currentTile = nextTile;
					currentTile = addNewTwoOrFour(currentTile);
				}
				printGrid(currentTile);
				checkAndStoreHighScore(currentTile);
				checkIf2048(currentTile);
			} else if (move == 's') {
				system("cls");
				nextTile = generateDownGrid(currentTile);
				int x = intComp(nextTile, currentTile);
				if (x == 1) {
					currentTile = nextTile;
					currentTile = addNewTwoOrFour(currentTile);
				}
				printGrid(currentTile);
				checkAndStoreHighScore(currentTile);
				checkIf2048(currentTile);
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

	return 0;
} 

typedef struct coordinate {
	int x, y;
} coordinate;

coordinate randomColumnAndRow() {
	coordinate initcoord;
	initcoord.x = rand() % 4;
	initcoord.y = rand() % 4;
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

int** generateFirstGrid() {
	int** firstTile;
	firstTile = calloc(4, sizeof(int*));
	int i;
	for (i = 0; i < 4; i++) {
		firstTile[i] = calloc(4, sizeof(int));
	}

	return firstTile;
}

int** addFirstTwoOrFourtoTile(int** firstTile) {
	int a = twoOrFour();
	int b = twoOrFour();
	coordinate coordOne = randomColumnAndRow();
	coordinate coordTwo = randomColumnAndRow();
	while (coordOne.x == coordTwo.x && coordOne.y == coordTwo.y) {
		coordTwo = randomColumnAndRow();
	}
	
	firstTile[coordOne.x][coordOne.y] = a;
	firstTile[coordTwo.x][coordTwo.y] = b;
	return firstTile;
}


int** generateLeftGrid(int** tile) {
	int **newGrid = generateFirstGrid();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newGrid[i][j] = tile[i][j];
		}
	}

	int i, j, new = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (newGrid[i][j] != 0) {
				newGrid[i][new] = newGrid[i][j];

			if (j != new) {
				newGrid[i][j] = 0;
			}

			new++;
			}
			
		}
		new = 0;
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			if (newGrid[i][j] == newGrid[i][j+1]) {
				newGrid[i][j] = 2*newGrid[i][j];
				newGrid[i][j+1] = 0;
			}
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (newGrid[i][j] != 0) {
				newGrid[i][new] = newGrid[i][j];

			if (j != new) {
				newGrid[i][j] = 0;
			}

			new++;
			}
			
		}
		new = 0;
	}

	return newGrid;
}

int** generateRightGrid(int** tile) {
	int **newGrid = generateFirstGrid();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newGrid[i][j] = tile[i][j];
		}
	}

	int i, j, new = 3;

	for (i = 3; i >= 0; i--) {
		for (j = 3; j >= 0; j--) {
			if (newGrid[i][j] != 0) {
				newGrid[i][new] = newGrid[i][j];

			if (j != new) {
				newGrid[i][j] = 0;
			}

			new--;
			}
			
		}
		new = 3;
	}

	for (i = 3; i >= 0; i--) {
		for (j = 3; j > 0; j--) {
			if (newGrid[i][j] == newGrid[i][j-1]) {
				newGrid[i][j] = 2*newGrid[i][j];
				newGrid[i][j-1] = 0;
			}
		}
	}

	for (i = 3; i >= 0; i--) {
		for (j = 3; j >= 0; j--) {
			if (newGrid[i][j] != 0) {
				newGrid[i][new] = newGrid[i][j];

			if (j != new) {
				newGrid[i][j] = 0;
			}

			new--;
			}
			
		}
		new = 3;
	}

	return newGrid;
}

int** generateUpGrid(int** tile) {
	int **newGrid = generateFirstGrid();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newGrid[i][j] = tile[i][j];
		}
	}

	int i, j, new = 0;

	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			if (newGrid[i][j] != 0) {
				newGrid[new][j] = newGrid[i][j];

			if (i != new) {
				newGrid[i][j] = 0;
			}

			new++;
			}
			
		}
		new = 0;
	}

	for (j = 0; j < 4; j++) {
		for (i = 0; i < 3; i++) {
			if (newGrid[i][j] == newGrid[i+1][j]) {
				newGrid[i][j] = 2*newGrid[i][j];
				newGrid[i+1][j] = 0;
			}
		}
	}

	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			if (newGrid[i][j] != 0) {
				newGrid[new][j] = newGrid[i][j];

			if (i != new) {
				newGrid[i][j] = 0;
			}

			new++;
			}
			
		}
		new = 0;
	}	

	return newGrid;
}

int** generateDownGrid(int** tile) {
	int **newGrid = generateFirstGrid();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newGrid[i][j] = tile[i][j];
		}
	}

	int i, j, new = 3;

	for (j = 3; j >= 0; j--) {
		for (i = 3; i >= 0; i--) {
			if (newGrid[i][j] != 0) {
				newGrid[new][j] = newGrid[i][j];

			if (i != new) {
				newGrid[i][j] = 0;
			}

			new--;
			}
			
		}
		new = 3;
	}

	for (j = 3; j >= 0; j--) {
		for (i = 3; i > 0; i--) {
			if (newGrid[i][j] == newGrid[i-1][j]) {
				newGrid[i][j] = 2*newGrid[i][j];
				newGrid[i-1][j] = 0;
			}
		}
	}

	for (j = 3; j >= 0; j--) {
		for (i = 3; i >= 0; i--) {
			if (newGrid[i][j] != 0) {
				newGrid[new][j] = newGrid[i][j];

			if (i != new) {
				newGrid[i][j] = 0;
			}

			new--;
			}
			
		}
		new = 3;
	}

	return tile;
}

void printGrid(int** tile) {
	int i,j;
	for (i = 0; i < 4; i++) {
		printf(" | ");
		for (j = 0; j < 4; j++) {
			if (tile[i][j] == 0) {
				printf("     ");
			} else {
				printf("%4d ",tile[i][j]);
			}
		}
		printf("  |\n");
	}
}

int showMainMenu() {
	printf("Select an option and press enter:\n");
	printf("1. Start a New Same\n2. View High Score\n3. Quit Game\n");
	
	char input[20] = "";
	char* end;
	int option = atoi(input);
	
	while((option != 1 && option != 2 && option != 3)) {
		fgets(input, 20, stdin);
		option = strtol(input, &end, 10);
		
		if (end[0] != '\n') {
			option = atoi(end);
		} 
		if (option != 1 && option != 2 && option != 3) {
			printf("This option is not valid, please try again\n");
		}
	}
	return option;
}

int** addNewTwoOrFour(int** tile) {
	coordinate coordinate = randomColumnAndRow();

	while (tile[coordinate.y][coordinate.x] != 0) {
		coordinate = randomColumnAndRow();
	}

	tile[coordinate.y][coordinate.x] = twoOrFour();

	return tile;
}

int intComp(int** currentTile, int** nextTile) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (currentTile[i][j] != nextTile[i][j]) {
				return 1;
			}
		}
	}

	return 0;
}

void checkAndStoreHighScore(int** tile) {
	FILE *fp = fopen("highscore.txt", "r");

	char scorestr[4];
	fgets(scorestr, 4, fp);

	int score = atoi(scorestr);

	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (tile[i][j] > score) {
				char newscore[4]; 
				sprintf(newscore, "%d\n", tile[i][j]);
				fp = fopen("highscore.txt","w");
				fprintf(fp, newscore);
			}
		}
	}
	fclose(fp);
}
void checkIf2048(int** tile) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (tile[i][j] == 2048) {
				printf("Congrats! You won the game!");
				exit(EXIT_SUCCESS);
			}
		}
	}
}