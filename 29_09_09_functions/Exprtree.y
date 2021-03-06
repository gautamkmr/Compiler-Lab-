%{	
	#include <stdio.h>
	#include "AbsSynTree.h"
	#include "globals.h"
	#include "SymbTab.h"
	#include "codegen.h"
	FILE* yyin;
	
	#define YYSTYPE NODPTR
	char msg[60];
	int yylex();
	void yyerror( char* );
	int argc = 0;
	int ret_flag, arg_flag ;
	int flag = 0;
	int errflag = 0;
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
%token WHILE DO ENDWHILE
%token T F 
%token MAIN RETURN

%left '<' '>'
%left EQUALEQUAL LESSTHANOREQUAL GREATERTHANOREQUAL NOTEQUAL
%left '+' '-'
%left '*' '/'
%left LOGICAL_AND LOGICAL_OR
%left LOGICAL_NOT
%%

	Prog	:	Gdecl_sec Fdef_sec MainBlock
		;
		
	Gdecl_sec:	DECL Gdecl_list ENDDECL
		;
		
	Gdecl_list: 
		| 	Gdecl Gdecl_list
		;
		
	Gdecl 	:	ret_type Glist ';'
		;
		
	ret_type:	T_INT		{ ret_flag = INT;  }
		|	T_BOOL 		{ ret_flag = BOOL; }
		;
		
	Glist 	:	Gid
		| 	func 
		|	Gid ',' Glist 
		|	func ',' Glist
		;
	
	Gid	:	VAR		{ 
					   Ginsert($1->name, ret_type, -1, -1, -1, NULL);
					}
		|	VAR '[' NUM ']'	
					{
					   //Count += ($3->value - 1);
		                      	   Ginsert($1->name, ret_type, -1, $3->value, -1, NULL);
					}
		;
		
	func 	:	VAR '(' arg_list ')'
					{ 
					   Ginsert($1->name, FUNC, ret_flag, -1, argc, list_head);
					   list_head = NULL;
					   argc = 0;
					}
		;
			
	arg_list :	
		|	arg_list1
		;
		
	arg_list1:	arg_list1 ';' arg 
		|	arg
		;
		
	arg 	:	arg_type var_list 
		;
		
	arg_type:	T_INT		{ arg_flag = INT;  }
		|	T_BOOL 		{ arg_flag = BOOL; }
		;

	var_list : 	VAR 		{
  					  createList($1->name, arg_flag);
  					  argc++;
					}
		|	VAR ',' var_list{
					  createList($1->name, arg_flag);
  					  argc++;
  					}
		;
		
	Fdef_sec :	
		|	Fdef_sec Fdef
		;
		
	Fdef	:	ret_type VAR '(' FargList ')' '{' Ldecl_sec stmt_sec '}'
					{	/* Main part */
					}
		;
	
	FargList:	arglist		{ /* check on arg count etc while puting things in the local symbol table
					     */ }
		;
		
	MainBlock: 	T_INT MAIN '('')''{' Ldecl_sec stmt_sec '}'
					{
					
					}
		;	
	
	Ldecl_sec:	DECL Ldecl_list ENDDECL
		;

	Ldecl_list:		
		|	Ldecl Ldecl_list
		;

	Ldecl	:	type Lid_list ';'		
		;

	type	:	T_INT			{ flag = 1; }
		|	T_BOOL			{ flag = 0; }
		;

	Lid_list:	Lid
		|	Lid ',' Lid_list
		;
		
	Lid	:	VAR	{ 
				  if(Llookup($1->name))
				  {
				 	sprintf(msg,"Variable '%s' redeclared",$1->name);
					SemError(msg);
				  } 
			
				  Linsert($1->name,-1);
				  $1->stptr=lookup($1->name);
				  $1->RetType = $1->stptr->type;
				  if( flag )
					  Linsert($1->name, INT);
				  else
					  Linsert($1->name, BOOL);
				}
		;

	stmt_sec:	BEG stmt_list END	{ $$ = $2; }
		;

	stmt_list:	
		|	statement stmt_list	{ 
						  if($2->NodeType == SEQ)
							$$ = ConnectNodes(MakeLeaf(SEQ, NULL), $1, $2);
						  else
							$$ = ConnectNodes(MakeLeaf(SEQ, NULL), $1, NULL);
						}
		|	error ';' 		{ errflag = 1; yyerrok ; }
		;

	statement:	assign_stmt 		{ $$ = $1; }
		|	read_stmt 		{ $$ = $1; }
		|	write_stmt 		{ $$ = $1; }
		|	cond_stmt 		{ $$ = $1; }
		|	ret_stmt		{ $$ = $1; }
		|	func_stmt		{ $$ = $1; }
		;

	func_stmt:	VAR '(' param_list ')' ';' { $$ = $1; /* Create a new node to */}
		;
		
	param_list:	
		|	param_list1
		;
		
	param_list1:	para
		|	param_list1 ',' para
		;
		
	para	:	NUM			{  createList($1->name, arg_flag);}
		|	VAR			{}
		;
		
	read_stmt:	READ '(' var_expr ')' ';'{
	 					  if($3->RetType == BOOL)
	 					  	SemError("Cannot read to a boolean variable");
						  $$ = ConnectNodes(MakeLeaf(RD, NULL), $3, NULL); 
						 }
		;

	write_stmt:	WRITE '(' expr ')' ';'	{ $$ = ConnectNodes(MakeLeaf(WE, NULL), $3, NULL); }
		;
	ret_stmt:	RETURN expr ';'		{}

	assign_stmt:	var_expr '=' expr ';'	{ 
						  if($1->RetType != $3->RetType)
							SemError("Assigning unmatched types");
				 
						  $$ = ConnectNodes(MakeLeaf(EQUAL, NULL), $1, $3);
						}
		;

	cond_stmt:	IF expr THEN stmt_list ENDIF ';'
						{ 
						  if($2->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  $$ = ConnectNodes(MakeLeaf(IF_THEN, NULL), $2, $4);	
						}
		|	IF expr THEN stmt_list ELSE stmt_list ENDIF ';'
						{
						  if($2->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  $$ = ConnectNodes(MakeLeaf(IF_THEN_ELSE, NULL), $2, $6);
						  $$->Mptr = $4;
						}
		|	WHILE expr DO stmt_list ENDWHILE ';'
						{
						  if($2->RetType != BOOL)
						  	SemError("Condition not a boolean type");
						  $$ = ConnectNodes(MakeLeaf(DO_WHILE, NULL), $2, $4);
						}
		;

	expr	:	NUM 			{ $$ = $1;			}
		|	'-' NUM			{ 
						  $2->value = -1 * $2->value;	
						  $$ = $2;
						}
		|	var_expr		{ $$ = $1;			}
		|	T			{ $$ = MakeLeaf(TRUE, NULL);	}
		|	F			{ $$ = MakeLeaf(FALSE, NULL);	}
		|	'(' expr ')'		{ $$ = $2; 			}

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
		|	expr '<' expr		{
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");
						  if($1->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(LT, NULL), $1, $3);
						}
		|	expr '>' expr		{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");
						  if($1->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(GT, NULL), $1, $3);
						}
		|	expr GREATERTHANOREQUAL expr
						{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");
						  if($1->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(GTE, NULL), $1, $3);
						}
		|	expr LESSTHANOREQUAL expr
						{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");
						  if($1->RetType == BOOL)
							SemError("Comparison not defined on boolean types");

						  $$ = ConnectNodes(MakeLeaf(LTE, NULL), $1, $3);
						}
		|	expr NOTEQUAL expr
						{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(NE, NULL), $1, $3);
						}
		|	expr EQUALEQUAL expr	{
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");

						  $$ = ConnectNodes(MakeLeaf(ISEQUAL, NULL), $1, $3);
						}
		|	LOGICAL_NOT expr	{
						   if($2->RetType != BOOL)
							SemError("Expression not of boolean type");

						  $$ = ConnectNodes(MakeLeaf(NOT, NULL) , $2, NULL); 	
						}
		|	expr LOGICAL_AND expr	{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");
						  if($1->RetType != BOOL)
							SemError("AND not defined on integer type");

						  $$ = ConnectNodes(MakeLeaf(AND, NULL) , $1, $3);	
						}
		|	expr LOGICAL_OR expr	{ 
						  if($1->RetType != $3->RetType)
							SemError("Comparison between unmatched types");
						  if($1->RetType != BOOL)
							SemError("OR not defined on integer type");

						  $$ = ConnectNodes(MakeLeaf(OR, NULL) , $1, $3); 	
						}

		;
		
	var_expr:	VAR	{ 
				  $1->stptr = lookup($1->name);
				  if($1->stptr == NULL)
				  {
					sprintf(msg, "Variable '%s' undeclared", $1->name);
					yyerror(msg);
				  }
				  else
				  {
				   $1->RetType = $1->stptr->type;
				  
				   if($1->stptr->size != -1) //That is, the variable is an array
				   {
					sprintf(msg, "Array variable '%s' accessed without index", 
					$1->stptr->name);
					yyerror(msg);
				   }
				  }
				   $$ = $1;
				}
		|	VAR '[' expr ']'
				{
				  $1->stptr = lookup($1->name);
				  if($1->stptr == NULL)
				  {
					sprintf(msg, "Variable '%s' undeclared", $1->name);
					SemError(msg);
				  }
				  $1->RetType = $1->stptr->type;
				  
				  if($3->RetType == BOOL)
				  	SemError("Array index cannot be boolean");
				  else if($1->stptr->size == -1) //That is, the variable is not an array
				  {
					sprintf(msg, "Variable '%s' not an array", $1->stptr->name);
					SemError(msg);
				  }
				  $$ = ConnectNodes(MakeLeaf(ARRAY, $1->name), $1, $3);
				  $$->RetType = $1->RetType;
				}
		;
%%

void yyerror(char* err)
{
	printf("%s at line number: %d\n", err, Lineno);
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

	Fp = fopen(argv[2], "w");
	if(!Fp){
		printf("File cannot be created\n");
		exit(0);
	}

	list_head = NULL;
	Lineno	= 1;	// Line no: starts from 1.
	Count   = 0;	// For binding field in Symbol table.
	ArrFlag = 1;	// So that array contents will be loaded instead of just the binding.
	Label	= 0;	// Label count starts from 0
	fprintf(Fp, "START\n");
	yyparse();
	fprintf(Fp, "HALT");
	fclose(Fp);
	fclose(yyin);
	return 0;
		/*input:	
		|	BEG decl_sec stmt_sec END { if(!errflag) {Print($3,0); CodeGen($3);} }
		;*/
}
