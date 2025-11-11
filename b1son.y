%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token ID

%%
E : E '+' E   { printf("Rule: E → E + E\n"); }
  | E '-' E   { printf("Rule: E → E - E\n"); }
  | '(' E ')' { printf("Rule: E → (E)\n"); }
  | ID        { printf("Rule: E → id\n"); }
  ;
%%

void yyerror(const char *s) {
    printf("Invalid Expression: %s\n", s);
}

int main() {
    printf("Enter an expression (e.g., (a+b)-c): ");
    if (yyparse() == 0)
        printf("Expression is Valid!\n");
    return 0;
}
