#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Select an option and press enter:\n");
	printf("1. Start a New Same\n2. View High Score\n3. Quit Game\n");
	
	char input[20] = "";
	int option = atoi(input);

	while((option != 1 && option != 2 && option != 3)) {
		fgets(input, 20, stdin);
		option = atoi(input);
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