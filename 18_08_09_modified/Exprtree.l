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
begin					return BEG;
end					return END;
read					return READ;
write					return WRITE;
integer					return T_INT;
boolean					return T_BOOL;
decl					return DECL;
enddecl					return ENDDECL;
if					return IF;
then					return THEN;
else					return ELSE;
endif					return ENDIF;
==					return EQUALEQUAL;
>=					return LESSTHANOREQUAL;
<=					return GREATERTHANOREQUAL;
!=					return NOTEQUAL;
AND					return LOGICAL_AND;
OR					return LOGICAL_OR;
NOT					return LOGICAL_NOT;

{digit}+			{ printf("Number\n");
					yylval = MakeLeaf(CONST, yytext);
					return NUM; 	
				}
{letter}({letter}|{digit})*	{ printf("Identifier\n");
					if(yyleng >= MAXLEN)
						printf("Variable has more than %d characters\n",MAXLEN);

					if(lookup(yytext) == NULL)
						insert(yytext, -1);

					yylval = MakeLeaf(VARIABLE, yytext);
					return VAR;
				}

[-+*/=()><;,\[\]]		{ printf("Symbols %s\n", yytext);	return *yytext; }
[\n]				{ printf("NewLine\n"); lineno++; }			
[ \t]				
.				{ printf("Extra\n"); }

%%

