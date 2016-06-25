#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printTile(int** tile);
int** generateFirstTile();

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
		printf("You started a new game!\n");
		int** firstTile = generateFirstTile();
		printTile(firstTile);

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
	srand(time(NULL));
	coordinate initcoord;
		initcoord.x = rand() % 4;
		initcoord.y = rand() % 4;
	return initcoord;
}

int twoOrFour() {
	srand(time(NULL));
	int x = rand() % 10;
	
	if (x == 0) {
		x = 4;
	} else {
		x = 2;
	}

	return x;
}

int** generateFirstTile() {
	int** firstTile;
	firstTile = calloc(4, sizeof(int*));
	for (int i = 0; i < 4; i++) {
		firstTile[i] = calloc(4, sizeof(int));
	}

	return firstTile;
}

/*char* generateLeftKey() {

}

char* generateRightKey() {

}

char* generateUpKey() {

}

char* generateDownKey() {

}*/

void printTile(int** tile) {
	int i,j;
	for (i = 0; i < 4; i++) {
		printf(" | ");
		for (j = 0; j < 4; j++) {
			printf("%4d ",tile[i][j]);
		}
		printf("|\n");
	}
}