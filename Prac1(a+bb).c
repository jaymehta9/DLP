/* For RE - a*bb */

#include <stdio.h>
#include <string.h>

int isValid(const char *str) {
    int i = 0;

    /* for RE - (a+bb) add below code*/
    if(str[i] == 'a'){
        return 1;
    }
    else{
        return 0;
    }
    
    while (str[i] == 'a') {
        i++;
    }
    

    if (str[i] == 'b' && str[i + 1] == 'b') {
        i += 2;
    } else {
        return 0;
    }

    if (str[i] == '\0') {
        return 1; 
    }
    return 0;
}

int main() {
    char input[10];

    printf("Enter a string to check is valid: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("Valid String\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}

/*
testcases : ^  bbbbb  aaa  baaabb aaabbb baaabb aaaab abbabb abb aaaaabb
*/