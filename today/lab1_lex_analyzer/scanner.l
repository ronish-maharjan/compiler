%{
#include <stdio.h>
%}

%%
"int"           { printf("KEYWORD: %s\n", yytext); }
"return"        { printf("KEYWORD: %s\n", yytext); }
"printf"        { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+          { printf("NUMBER: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER: %s\n", yytext); }
"="             { printf("ASSIGN: %s\n", yytext); }
";"             { printf("SEMICOLON: %s\n", yytext); }
","             { printf("COMMA: %s\n", yytext); }
"("             { printf("LPAREN: %s\n", yytext); }
")"             { printf("RPAREN: %s\n", yytext); }
"{"             { printf("LBRACE: %s\n", yytext); }
"}"             { printf("RBRACE: %s\n", yytext); }
"+"             { printf("PLUS: %s\n", yytext); }
"*"             { printf("MULTIPLY: %s\n", yytext); }
"\""            { printf("QUOTE: %s\n", yytext); }
[ \t\n]+        { /* ignore whitespace */ }
.               { printf("OTHER: %s\n", yytext); }
%%

int yywrap(void) {
    return 1;
}
