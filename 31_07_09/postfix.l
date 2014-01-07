%{
   #include <stdio.h>
   #include "postfix.tab.h"
%}

%%

[0-9]+	 	{ yylval = strdup(yytext); return CHARPASS; }
[-+*/\n]	 return *yytext; 
.	;
[ \t]+	;

%%

int yywrap() {
	return 1;
}