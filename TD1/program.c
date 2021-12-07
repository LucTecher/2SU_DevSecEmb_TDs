#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_valid(const char* password) {
	if (strcmp(password, "mypassword") == 0){
		return 1;
	} else {
		return 0;
	}
}

int main() {
	char * input = NULL;
	input = malloc(256);
	printf("Please input a word: ");
	scanf("%256s", input);

	if(is_valid(input)) {
		printf("That's correct!\n");
	} else {
		printf("That's not correct!\n");
	}

	free(input);
	return 0;
}
