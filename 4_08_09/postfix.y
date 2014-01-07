%{
   #include <stdio.h>
   #include <string.h>
   
   #define YYSTYPE char *
   int yylex(void);
   char *temp, *temp1;
%}

%token CHARPASS
%left '+' '-'
%left '*'
%left '/'

%%
program : program statement '\n' | /* NULL */
	;
statement : expression	{ printf("%s\n",$1); }
	  ;
expression : CHARPASS { $$ = $1; }
	   | expression '+' expression { temp = strcat($1,$3);  $$ = strcat(temp,"+"); }
	   | expression '-' expression { temp = strcat($1,$3);  $$ = strcat(temp,"-"); }
	   | expression '*' expression { temp = strcat($1,$3);  $$ = strcat(temp,"*"); }
	   | expression '/' expression { temp = strcat($1,$3);  $$ = strcat(temp,"/"); }
	   ;

%%

void yyerror(char* s) {
	fprintf(stderr,"Error : %s\n",s);
}

int main (void) {
	yyparse();
}
