%{
#include <stdio.h>
#include <string.h>
int has_lower = 0, has_upper = 0, has_digit = 0, has_symbol = 0, length = 0;
%}

%%
[a-z] { has_lower = 1; length += yyleng; }
[A-Z] { has_upper = 1; length += yyleng; }
[0-9] { has_digit = 1; length += yyleng; }
[*;#$@] { has_symbol = 1; length += yyleng; }
[^\n] { length += yyleng; }
\n {
    if (length >= 9 && length <= 15 && has_lower && has_upper && has_digit && has_symbol)
        printf("Valid password\n");
    else
        printf("Invalid password\n");
    has_lower = has_upper = has_digit = has_symbol = length = 0;
}
%%

int main() {
    yylex();
    return 0;
}



