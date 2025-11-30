%{
#include <stdio.h>
%}

%%
(if|else|while)         { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier: %s\n", yytext); }
[0-9]+                   { printf("Number: %s\n", yytext); }
"+"|"-"|"*"|"/"          { printf("Operator: %s\n", yytext); }
[ \t\n]+                 { /* ignore whitespace */ }
.                        { printf("Unknown character: %s\n", yytext); }
%%

int main(int argc, char **argv) {
    yylex(); // Start lexical analysis
    return 0;
}

int yywrap() {
    return 1;
}
