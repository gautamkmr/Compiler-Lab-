%{
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include "AbsSynTree.h"

   #define YYSTYPE NODPTR

   void yyerror (char* s) {
	fprintf (stderr,"%s\n", s);
   }

   int yylex(void);
   NODPTR temp;
   char* value;
%}

%token NUM
%left '+'
%left '-'
%left '*'
%left '/'

%%

program : program statement '\n' | /* NULL */
	;
statement : expression	{ PrintTree($1,0); PrintMax(); printf("\nValue is %d\n",EvaluateTree($1)); }
	  ;
expression : NUM	{ $$ = $1; } 
	   | expression '+' expression	{ printf("Plus\n"); $$ = ConnectNodes(MakeLeafNode("+"),$1,$3); }
	   | expression '-' expression  { printf("Minus\n"); $$ = ConnectNodes(MakeLeafNode("-"),$1,$3); }
	   | expression '*' expression  { printf("Multiply\n"); $$ = ConnectNodes(MakeLeafNode("*"),$1,$3); }
	   | expression '/' expression  { printf("Divide\n"); $$ = ConnectNodes(MakeLeafNode("/"),$1,$3); }
	   ;

%%

main() {
	yyparse();
}
