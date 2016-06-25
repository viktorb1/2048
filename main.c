#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
		printf("You started a new game\n");
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

/*char* generate_first_tile() {
}

char * generate_next_tile() {

}

void print_next_tiles() {

}*/