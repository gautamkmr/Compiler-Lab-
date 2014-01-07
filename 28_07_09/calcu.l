 /* DECLARATIONS */
%{
    #include "calcu.tab.h"

    #include <math.h>
    void yyerror(char *);
%}
		/* Option to exclude yywrap()*/
%option noyywrap


%%
 /* RULES */
[a-z]+	{
           yylval = malloc(sizeof(char));
	   strcpy(yylval, yytext);	/* Converts string to integer */
           return CHAR;		/* Returns the token */
        }

[-+/*\n^]     { return *yytext; }	/* Simply returns the operator/text */

[ \t]+   ;	/* Ignore whitespaces & tabs */

.               yyerror("Unknown character");	/* If the character is not recognized by any of the above */
%%

/* 'C' CODE */

/*int yywrap(void) 
{
    return 0;
}*/
