%{
	#include "globals.h"
	#include "SymbTab.h"
	#include "AbsSynTree.h"
	#include "Exprtree.tab.h"
	
	#define YYSTYPE NODPTR
%}

%option noyywrap
digit	[0-9]
letter	[a-zA-Z]

%%
main				return MAIN;
return 				return RETURN;
begin				return BEG;
end				return END;
read				return READ;
write				return WRITE;
integer				return T_INT;
boolean				return T_BOOL;
decl				return DECL;
enddecl				return ENDDECL;
if				return IF;
then				return THEN;
else				return ELSE;
endif				return ENDIF;
do				return DO;
while				return WHILE;
endwhile			return ENDWHILE;
"=="				return EQUALEQUAL;
"<="				return LESSTHANOREQUAL;
">="				return GREATERTHANOREQUAL;
"!="				return NOTEQUAL;
AND				return LOGICAL_AND;
OR				return LOGICAL_OR;
NOT				return LOGICAL_NOT;
true				return T; 	
false				return F; 	

{digit}+			{ 	
					yylval = MakeLeaf(CONST, yytext);
					return NUM; 	
				}

{letter}({letter}|{digit})*	{ 	
					if(yyleng >= MAXLEN)
						printf("Variable has more than %d characters\n",MAXLEN);
					
					yylval = MakeLeaf(VARIABLE, yytext);
					return VAR;
				}

[-+*/=()><;,\{\}\[\]]		{ return *yytext; }
[\n]				{ Lineno++; }			
[ \t]				
.

%%

