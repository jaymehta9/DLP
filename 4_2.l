%{
#include <stdio.h>
%}
%option noyywrap
%%
(c|C)(h|H)(a|A)(r|R)(u|U)(s|S)(a|A)(t|T) {printf("University");}
%%
void main() {
	yylex();
}


