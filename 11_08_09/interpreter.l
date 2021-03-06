%{
	#include <stdio.h>
	#include "globals.h"
	#include "SymbTab.h"
	#include "interpreter.tab.h"
	
%}
%option noyywrap
digit	[0-9]
letter	[a-zA-z]


%%
{digit}+			{ yylval.val = atoi( yytext );	return NUM; }
{letter}({letter}|{digit})*	{ printf("Hello, %s", yytext);
					if( strcmp(yytext, "read") == 0)		return READ;
					else if( strcmp(yytext, "write") == 0)		return WRITE;
					else if( strcmp(yytext, "integer") == 0)	return T_INT;
					else if( strcmp(yytext, "boolean") == 0)	return T_BOOL;
					else if( strcmp(yytext, "decl") == 0)		return DECL;
					else if( strcmp(yytext, "enddecl") == 0)	return ENDDECL;
					
					if(lookup(yytext) == NULL)
						insert(yytext, -1);

					yylval.tptr = lookup(yytext);
					return VAR;
				}
[-+/*=()]		{ return *yytext; }
[\n]			{ lineno++; return *yytext;  }
[;,]			{ return *yytext; }
[ \t]			;	/* Ignore Whitespace */
.			{ printf("\nUnexpected character\n"); }

%%

