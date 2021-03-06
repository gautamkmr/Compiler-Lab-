%{	
	#include <stdio.h>
	#include "AbsSynTree.h"
	#include "globals.h"
	#include "SymbTab.h"
	#include "codegen.h"
	FILE* yyin;
	#define YYSTYPE NODPTR

	int yylex();
	void yyerror( char* );
	int flag = 0, temp = 0;
	void SemError(char*);
%}

%token BEG END
%token T_INT T_BOOL
%token READ WRITE
%token DECL ENDDECL
%token VAR NUM
%token IF THEN ELSE ENDIF
%token LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL

%right '='
%left  '+' '-'
%left  '*' '/'
%left  '<' '>'

%%

	input:	
		|	BEG decl_sec stmt_sec END
		;

	stmt_sec:	stmt_list		{ Print($1,0); }//CodeGen($1);  }
		;

	stmt_list:	
		|	statement stmt_list	{ 
						  if($2->NodeType == SEQ)
							$$ = ConnectNodes(MakeLeaf(SEQ, NULL), $1, $2);
						  else
							$$ = ConnectNodes(MakeLeaf(SEQ, NULL), $1, NULL);
						}
		|	error ';' 		{ yyerrok ; }
		;

	statement:	assign_stmt 		{ $$ = $1; }
		|	read_stmt 		{ $$ = $1; }
		|	write_stmt 		{ $$ = $1; }
		|	cond_stmt 		{ $$ = $1; }
		;

	read_stmt:	READ '(' VAR ')' ';'	{ $$ = ConnectNodes(MakeLeaf(RD, NULL), $3, NULL); }
		;

	write_stmt:	WRITE '(' expr ')' ';'	{ $$ = ConnectNodes(MakeLeaf(WE, NULL), $3, NULL); }
		;

	assign_stmt:	VAR '=' expr ';'	{ 
						  if($1->stptr->type == -1)
							SemError("Variable undeclared");
						  if($1->RetType != $3->RetType)
							SemError("Assigning unmatched types");
				 
						  $$ = ConnectNodes(MakeLeaf(EQUAL, NULL), $1, $3);
						}
		;
	cond_stmt:	IF cond THEN statement ENDIF
						{
						  $$ = ConnectNodes(MakeLeaf(IF_THEN, NULL), $2, $4);
						}		  
		|	IF cond THEN statement ELSE statement ENDIF
						{
						  $$ = ConnectNodes(MakeLeaf(IF_THEN_ELSE, NULL), $2, $6);
						  $$->Mptr = $4;
						}
		;
	expr: 		NUM 			{ $$ = $1;	}
		|	VAR			{ 
						  if($1->stptr->type == -1)
							SemError("Variable undeclared");
						  else if($1->stptr->size != -1) //That is, the variable is an array
							yyerror("Variable declared as array but used as non-array type");

						  $$ = $1;
						}
		|	VAR '[' expr ']'	{
						  if($1->stptr->type == -1)
							SemError("Variable undeclared");
						  else if($1->stptr->size == -1) //That is, the variable is not an array
							yyerror("Variable declared as non-array but used as array type");

						  $$ = ConnectNodes(MakeLeaf(ARRAY, NULL), $1, $3);
						}
		|	expr '+' expr 		{
						  if($1->RetType != $3->RetType)
							SemError("Adding unmatched types");
					  	  if($1->RetType == BOOL)
							SemError("Adding not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(PLUS, NULL) , $1, $3); 
						  $$->RetType = $1->RetType; 	
						}
		|	expr '-' expr	 	{ 
						  if($1->RetType != $3->RetType)
							SemError("Warning: Subtracting unmatched types");
						  if($1->RetType == BOOL)
							SemError("Subtraction not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(MINUS, NULL) , $1, $3); 
						  $$->RetType = $1->RetType; 	
						}
		|	expr '*' expr 		{ 			
						  if($1->RetType != $3->RetType)
							SemError("Multiplying unmatched types");
						  if($1->RetType == BOOL)
							SemError("Multipliation not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(MUL, NULL) , $1, $3); 
						  $$->RetType = $1->RetType; 	
						}
		|	expr '/' expr 		{ 
						  if($1->RetType != $3->RetType)
							SemError("Dividing unmatched types");
						  if($1->RetType == BOOL)
							SemError("Division not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(DIV, NULL) , $1, $3); 
						  $$->RetType = $1->RetType; 	
						}
		|	'(' expr ')'		{ $$ = $2; }
		|	cond			{ $$ = $1; }
		;

	cond	:	expr '<' expr		{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(LT, NULL), $1, $3);
						  $$->RetType = BOOL;	 
						}
		|	expr '>' expr		{ 
			$$->RetType = BOOL;			  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(GT, NULL), $1, $3);
						  $$->RetType = BOOL;	 
						}
		|	expr GREATERTHANOREQUAL expr
						{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(GTE, NULL), $1, $3);
						  $$->RetType = BOOL;	 
						}
		|	expr LESSTHANOREQUAL expr
						{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(LTE, NULL), $1, $3);
						  $$->RetType = BOOL;	 
						}
		|	expr NOTEQUAL expr
						{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(NE, NULL), $1, $3);
						  $$->RetType = BOOL;	 
						}

		|	expr EQUALEQUAL expr	{
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(ISEQUAL, NULL), $1, $3);
						  $$->RetType = BOOL;
						}
		|	'(' cond ')'		{ $$ = $2; }
		|	LOGICAL_NOT cond	{ $$ = ConnectNodes(MakeLeaf(NOT, NULL) , $2, NULL); }
		|	cond LOGICAL_AND cond	{ $$ = ConnectNodes(MakeLeaf(AND, NULL) , $1, $3); }
		|	cond LOGICAL_OR cond	{ $$ = ConnectNodes(MakeLeaf(OR, NULL) , $1, $3); }
		;

	decl_sec:	DECL decl_list ENDDECL
		;

	decl_list:	decl	
		|	decl decl_list
		;

	decl	:	type idlist ';'
		;

	type	:	T_INT			{ flag = 1; }
		|	T_BOOL			{ flag = 0; }
		;

	idlist	:	id
		|	id ',' idlist
		;

	id:		VAR '[' NUM ']'		{
							$1->stptr->size = $3->value;
							count += $3->value;

							if( flag ) 
								$1->stptr->type = INT;
							else
								$1->stptr->type = BOOL;
						}
		|	VAR			{ 
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

void SemError(char* err)
{
	yyerror(err);
	exit(0);
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Usage Eval <Input filename> <Output filename>\n");
		return 0;
	}

	yyin = fopen(argv[1], "r");
	if(!yyin)
	{
		printf("\nFile %s not found\n", argv[1]);
		return 0;
	}

	fp = fopen(argv[2], "w");
	if(!fp){
		printf("File cannot be created\n");
		exit(0);
	}

	lineno = 1;
	count = 0;	// For binding field.

	fprintf(fp, "START\n");
	yyparse();
	fprintf(fp, "HALT");
	fclose(fp);
	fclose(yyin);
	return 0;
}
