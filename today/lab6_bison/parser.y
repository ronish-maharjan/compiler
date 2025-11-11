%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%union {
    char* str;
}

%token <str> ID

%left '+' '-'

%%

expr:
      expr '+' expr  { printf("Reducing: expr + expr\n"); }
    | expr '-' expr  { printf("Reducing: expr - expr\n"); }
    | '(' expr ')'   { printf("Reducing: (expr)\n"); }
    | ID             { printf("Reducing: ID (%s)\n", $1); }
    ;

%%

void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
}

int main() {
    printf("Enter expression: ");
    yyparse();
    return 0;
}
