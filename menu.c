#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

