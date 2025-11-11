%{
#include "parser.tab.h"  // Include Bison-generated header
%}

%%

[a-z]       { yylval.str = strdup(yytext); return ID; }
[+\-]       { return yytext[0]; }
"("         { return '('; }
")"         { return ')'; }
[ \t\n]+    { /* ignore whitespace */ }
.           { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
