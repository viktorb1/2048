#include <stdio.h>
#include <stdlib.h>

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
/*
typedef struct coordinates {
	//a coordinate
} coordinates;

struct randomize_column_and_row() {
	return coordinates;
	//generates random coordinates
}

int two_or_four() {
	return either a 2 or 4 randomly to start the game
}

char* generate_first_tile() {
}

char * generate_next_tile() {

}

void print_next_tiles() {

}*/