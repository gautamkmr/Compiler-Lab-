%{
   #include <stdio.h>
   #include "postfix.tab.h"
   void yyerror(char *);
%}


%%

[a-z]+	{ yylval = strdup(yytext); return CHARPASS;}
[-+*/\n]	{ return *yytext; }
.	;
[ \t]+	;

%%

int yywrap() {
	return 1;
}

