#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool validateString(const char *str) {
	int len = strlen(str);


	if (str[len - 1] != 'b' || str[len - 2] != 'b') {
		return false;
	}


	for (int i = 0; i < len - 2; i++) {
		if (str[i] != 'a') {
			return false;
		}
	}

	return true;
}

int main() {
	char input[7];

	printf("Enter a string : ");
	fgets(input, sizeof(input), stdin);


	size_t length = strlen(input);
	if (length > 0 && input[length - 1] == '\n') {
		input[length - 1] = '\0';
	}

	if (validateString(input)) {
		printf("The string is VALID according to the pattern 'a*bb'.\n");
	} else {
		printf("The string is INVALID according to the pattern 'a*bb'.\n");
	}

	return 0;
}