%{
   #include <stdio.h>
   #include <stdlib.h>
   #include "AbsSynTree.h"
   #include "expressiontree.tab.h"
   void yyerror(char *);
%}
%option noyywrap

%%
[0-9]+		{ yylval = MakeLeafNode(yytext); return NUM; }
[-+*/\n]	{ return *yytext; }
[ \t]		;	/* Ignore Whitespace */
.		;	

%%
