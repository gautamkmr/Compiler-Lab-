%{	
	#include <stdio.h>
	#include "AbsSynTree.h"
	#include "globals.h"
	#include "SymbTab.h"
	FILE* yyin;
	#define YYSTYPE NODPTR

	int yylex();
	void yyerror( char* );
	int flag = 0;	
%}

%token BEG END
%token T_INT T_BOOL
%token READ WRITE
%token DECL ENDDECL
%token VAR NUM

%right '='
%left  '+' '-'
%left  '*' '/'

%%

	input:	
		|	BEG decl_sec stmt_sec END
		;

	stmt_sec:	stmt_list		{ Print($1,0);/*Evaluate($1);*/ }
		;

	stmt_list:
		|	statement stmt_list	{ 
						  if($2->NodeType == SEQ)
							$$ = ConnectNodes(MakeLeaf(SEQ, NULL), $1, $2);
						  else
							$$ = ConnectNodes(MakeLeaf(SEQ, NULL), $1, NULL);
						}
		|	error 	 		{ yyerrok ; }
		;

	statement:	assign_stmt 		{ $$ = $1; }
		|	read_stmt 		{ $$ = $1; }
		|	write_stmt 		{ $$ = $1; }
		;

	read_stmt:	READ '(' VAR ')' ';'	{ $$ = ConnectNodes(MakeLeaf(RD, NULL), $3, NULL); }
		;

	write_stmt:	WRITE '(' expr ')' ';'	{ $$ = ConnectNodes(MakeLeaf(WE, NULL), $3, NULL); }
		;

	assign_stmt:	VAR '=' expr ';'	{ 
						  if($1->stptr->type == -1)
							yyerror("Variable undeclared");				 
						  $$ = ConnectNodes(MakeLeaf(EQUAL, NULL), $1, $3);
						}
		;

	expr: 		NUM 			{ $$ = $1;	}
		|	VAR			{ 
						  if($1->stptr->type == -1)
							yyerror("Variable undeclared");
						  $$ = $1;	
						}
		|	expr '+' expr 		{ $$ = ConnectNodes(MakeLeaf(PLUS, NULL) , $1, $3); }
		|	expr '-' expr	 	{ $$ = ConnectNodes(MakeLeaf(MINUS, NULL), $1, $3); }
		|	expr '*' expr 		{ $$ = ConnectNodes(MakeLeaf(MUL, NULL)  , $1, $3); }
		|	expr '/' expr 		{ $$ = ConnectNodes(MakeLeaf(DIV, NULL)  , $1, $3); }
		;

	decl_sec:	DECL decl_list ENDDECL
		;
	decl_list:	decl
		|	decl decl_list
		;
	decl	:	type idlist ';'
		;
	type:		T_INT			{ flag = 1; }
		|	T_BOOL			{ flag = 0; }
		;
	idlist	:	id			
		|	id ',' idlist
		;
	id:		VAR			{ 
							if( flag ) 
								$1->stptr->type = INT;
							else
								$1->stptr->type = BOOL;
						}
						  
		;
%%

void yyerror(char* err)
{
	printf("%s at line number: %d\n", err, lineno);
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage Eval <Input filename>\n");
		return 0;
	}

	yyin = fopen(argv[1], "r");
	if(!yyin)
	{
		printf("\nFile %s not found\n", argv[1]);
		return 0;
	}

	lineno = 0;	
	yyparse();
	return 0;
}
