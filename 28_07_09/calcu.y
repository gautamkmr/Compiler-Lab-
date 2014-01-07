 /* DECLARATIONS */
%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    void yyerror(char *);
    int yylex(void);

%}
		/* Declaring the token and precedence rules */
%token CHAR
%left '+'
%left '-'
%left '*' '/'
%left '^'

%%
 /* RULES */
program:
        program statement '\n'
        |
        ;

statement:
        expression               { printf("%d\n", $1); }
        ;

expression:
        CHAR
        | expression '+' expression     { 
					char temp1[100];
					
/*					strcpy(temp1, yytext);
					strcpy($$, temp1);
					printf("%s", temp1);	*/
					}
        | expression '-' expression     { printf("-%d%d \nSub\n", $1, $3); }
        | expression '*' expression     { printf("*%d%d \n", $1, $3); }
        | expression '/' expression     { printf("/%d%d \n", $1, $3); }
        | expression '^' expression     { printf("^%d%d \n", $1, $3); }
        ;

%%

/* 'C' CODE */
void yyerror(char *s) 
{
	fprintf(stderr, "%s\n", s);
}

int main(void)
{
    yyparse();
}
