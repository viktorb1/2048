#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printGrid(int** tile);
int** generateFirstGrid();
int** generateLeftGrid(int** tile);
int** generateRightGrid(int** tile);
int** generateUpGrid(int** tile);
int** generateDownGrid(int** tile);

int main() {
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

	if (option == 1) {
		system("cls");
		srand(time(NULL));
		int** currentTile = generateFirstGrid();
		printGrid(currentTile);

		printf("\n You started a new game!\n");
		printf(" Press 'q' to quit.\n w/a/s/d to move grid\n");
		
		int move;

		
		while ((move = getchar()) != 'q') {
			if (move == 'a') {
				system("cls");
				currentTile = generateLeftGrid(currentTile);
				printGrid(currentTile);
			} else if (move == 'd') {
				system("cls");
				currentTile = generateRightGrid(currentTile);
				printGrid(currentTile);
			} else if (move == 'w') {
				system("cls");
				currentTile = generateUpGrid(currentTile);
				printGrid(currentTile);
			} else if (move == 's') {
				system("cls");
				currentTile = generateDownGrid(currentTile);
				printGrid(currentTile);
			} else {
				if (move != '\n') {
					printf("Invalid move\n");
				}
			}
		}

	} else if (option == 2) {
		printf("The high score is:\n");
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
	return tile;
}

int** generateRightGrid(int** tile) {
	return tile;
}

int** generateUpGrid(int** tile) {
	return tile;
}

int** generateDownGrid(int** tile) {
	return tile;
}

void printGrid(int** tile) {
	int i,j;
	for (i = 0; i < 4; i++) {
		printf(" | ");
		for (j = 0; j < 4; j++) {
			printf("%4d ",tile[i][j]);
		}
		printf("|\n");
	}
}
