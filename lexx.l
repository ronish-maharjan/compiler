%{
#include "expr.tab.h"
%}

%%
[a-zA-Z]      { return ID; }
[+\-]         { return yytext[0]; }
"("           { return '('; }
")"           { return ')'; }
[ \t\n]       { /* ignore whitespace */ }
.             { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
