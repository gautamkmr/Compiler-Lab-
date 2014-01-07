%{
	#include <stdio.h>
	#include <string.h>
	
	#define YYSTYPE char *
	int yylex(void);
	char *temp;
%}

%token CHARPASS

%left '+' '-'
%left '*'
%left '/'

%%
program : program statement '\n' | /* NULL */
	;
statement : expression	{ printf("%s \n",$1); }
	  ;
expression : CHARPASS { $$ = $1; }
	   | expression '+' expression { 
	 		temp = malloc(sizeof(char) * 10);
			strcpy(temp," + "); 
			strcat(temp,$1);
			strcat(temp, " "); 
			$$ = strcat(temp,$3);
		}
	   | expression '-' expression { 
	 		temp = malloc(sizeof(char) * 10);
			strcpy(temp," - "); 
			strcat(temp,$1); 
			strcat(temp, " "); 
			$$ = strcat(temp,$3);
		}
	   | expression '*' expression { 
	 		temp = malloc(sizeof(char) * 10);
			strcpy(temp," * "); 
			strcat(temp,$1); 
			strcat(temp, " "); 
			$$ = strcat(temp,$3);
		}
	   | expression '/' expression { 
	 		temp = malloc(sizeof(char) * 10);
			strcpy(temp," / "); 
			strcat(temp,$1); 
			strcat(temp, " "); 
			$$ = strcat(temp,$3);
		}
	   ;

%%

void yyerror(char* s) {
	fprintf(stderr,"Error : %s\n",s);
}

int main (void) {
	yyparse();
}

