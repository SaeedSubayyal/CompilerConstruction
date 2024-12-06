%{
#include "ssc.tab.h"  // Include the Bison-generated header
%}

%%

[0-9]+              { yylval.iVal = atoi(yytext); return INTEGER; }
[a-zA-Z_][a-zA-Z0-9_]*   { yylval.sVal = new std::string(yytext); return IDENTIFIER; }
"="                 { return '='; }
"+"                 { return PLUS; }  // Define PLUS token
"-"                 { return MINUS; }  // Define MINUS token
"*"                 { return STAR; }  // Define STAR token
"/"                 { return SLASH; }  // Define SLASH token
[ \t\n]+            { /* Ignore whitespace */ }
.                   { return yytext[0]; }

%%

