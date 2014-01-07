%{
	#include "globals.h"
	#include "SymbTab.h"
	#include "AbsSynTree.h"
	#include "Exprtree.tab.h"
	
	#define YYSTYPE NODPTR
%}

%option noyywrap
digit	[0-9]
letter	[a-zA-z]


%%
Beg					return BEG;
End					return END;
read					return READ;
write					return WRITE;
integer					return T_INT;
boolean					return T_BOOL;
decl					return DECL;
enddecl					return ENDDECL;

{digit}+			{	
					yylval = MakeLeaf(CONST, yytext);
					return NUM; 	
				}
{letter}({letter}|{digit})*	{
					if(yyleng >= MAXLEN)
						printf("Variable has more than %d characters\n",MAXLEN);

					if(lookup(yytext) == NULL)
						insert(yytext, -1);

					yylval = MakeLeaf(VARIABLE, yytext);
					return VAR;
				}
[-+*/=()]			{ return *yytext; }
[;,]				{ return *yytext; }
[\n]				{ lineno++; }
[ \t]				;
.				{ printf("\nUnexpected character\n"); }

%%

