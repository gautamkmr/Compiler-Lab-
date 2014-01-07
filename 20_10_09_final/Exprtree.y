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
	
	char msg[MSGLEN];
	
	Argstruct* original_list;
	NODPTR expr_head;
	GSymbolTable* tmp;

	int errflag;		/* To mark the occurance of any compilation error. 		*/
	int type_flag;		/* To store type of variables and arrays 			*/
	int arg_flag;		/* To store argument types of arguments in function definition.	*/
	int func_type_flag ;	/* To store the return type of functions in function definition */
	
	void SemError(char*);
	char* print_name(int);


	/* 
		Match arguments of the two passed argument list and reports error
	 * Arguments:
	 *	ARG1, ARG2 : Specifies the argument lists to be matched.
	 *    
	 * Precondition	:	---
	 *			
	 * Postcondition:	Arguments are checked for name and type equivalence.
	 *			Any errors will be reported as semantic errors.
	 * Comments	:	---
	 */
        void match_arguments(Argstruct*, Argstruct*);


	/*
		Match parameters of the two passed parameter list and reports error 
	 * Arguments:
	 *	ARG1, ARG2 : Specifies the parameter lists to be matched.
	 *    
	 * Precondition	:	---
	 *			
	 * Postcondition:	Any errors will be reported as semantic errors.
	 *
	 * Comments	:	Parameters are checked only for type equivalence.
	 */
        void match_parameters(Argstruct*, Argstruct*);
	
	/*
		Initiates the program by initialising global variables
	 * Precondition	:	---
	 *			
	 * Postcondition:	---
	 *
	 * Comments	:	---
	 */	
        void initiate();

	/*
		Dealloactes all dynamically allocated memory and closes all open files.
	 * Precondition	:	---
	 *			
	 * Postcondition:	---
	 *
	 * Comments	:	---
	 */	
        void terminate();
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
		
	ret_type:	T_INT		{ type_flag = INT;  }
		|	T_BOOL 		{ type_flag = BOOL; }
		;
		
	Glist 	:	Gid
		| 	func 
		|	Gid ',' Glist 
		|	func ',' Glist
		;
	
	Gid	:	VAR		{
					   tmp = Glookup($1->name);
					   if(tmp)
					   {
					     if(tmp->type == FUNC)
					     {
					     	sprintf(msg, "A function with the name '%s' already exists",
					     		  tmp->name);
					     	SemError(msg);
					     }
					     else
					     {
					        sprintf(msg, "Variable '%s' redeclared",$1->name);
  					        SemError(msg);
  					     }
					   }
					   else
					     Ginsert($1->name, type_flag, -1, -1, NULL); 
					}
		|	VAR '[' NUM ']'	{   
					    tmp = Glookup($1->name);
					    if(tmp)
					    {
					      if(tmp->type == FUNC)
					      {
					     	sprintf(msg, "A function with the name '%s' already exists",
					     		  tmp->name);
					     	SemError(msg);
					      }
					      else
					      {
  					        sprintf(msg,"Array '%s' redeclared",$1->name);
					        SemError(msg);
					      }
					    }
					    else if($3->value == 0)
					    {
					      sprintf(msg, "Array '%s' declared with index zero", $1->name);
					      SemError(msg);
					    }	
		                      	    else
		                      	    {
		                      	      GCount += ($3->value - 1);
		                      	      Ginsert($1->name, type_flag, -1, $3->value, NULL);
		                      	    }
					}
		;
		
	func 	:	VAR '(' arg_list ')'
					{
					    tmp = Glookup($1->name);
					    if(tmp)
					    {
					      if(tmp->type == FUNC)
					      {
					        sprintf(msg,"Function '%s' redeclared",$1->name);
					        SemError(msg);
					      }
					      else
					      {
					        sprintf(msg,"A variable with name '%s' already exists",$1->name);
					        SemError(msg);
					      }
					    }
					    else
					    {
					      Ginsert($1->name, FUNC, type_flag, -1, list_head);
					      list_head = NULL;
					    }
					}
		;
			
	arg_list:	
		|	arg_list1
		;
		
	arg_list1:	arg_list1 ';' arg
		|	arg
		;
		
	arg 	:	arg_type var_list	
		;
		
	arg_type:	T_INT		 { arg_flag = INT;  }
		|	T_BOOL 		 { arg_flag = BOOL; }
		;

	var_list:	VAR 		 { createList($1->name, arg_flag);	}
		|	VAR ',' var_list { createList($1->name, arg_flag);	}
		;
		
	Fdef_sec:	
		|	Fdef_sec Fdef
		;
		
	Fdef	:	func_ret_type func_name '(' FargList ')' '{' Ldecl_sec BEG stmt_list ret_stmt END '}'
					{	
					  /*if(!errflag)
					    Call ----  CodeGen() appropriately.*/
					  
					  free(Lhead);
					  LCount = 0;
					  Lhead = NULL;
					  Print($9, 0);
					}
		;
		
	func_ret_type:	T_INT		{ func_type_flag = INT;  }
		|	T_BOOL		{ func_type_flag = BOOL;  }
		;
			
	func_name:	VAR		{
					  $$->Gstptr = Glookup($1->name);
					  if(!$$->Gstptr)
					  {
					     sprintf(msg,"Function '%s' is not declared", $1->name);
					     SemError(msg);
					  }
					  else if($$->Gstptr->type != FUNC)
					  {
					     sprintf(msg,"'%s' is declared but not a function",$1->name);
					     SemError(msg);
					  }
					  else if($$->Gstptr->isFuncDefined)
					  {
					     sprintf(msg,"Function '%s' is re-defined", $1->name);
					     SemError(msg);
					  }	
					  else if($$->Gstptr->FuncRetType != func_type_flag)
					  {
					     sprintf(msg,"Return type of function '%s' is not matching",$1->name);
					     SemError(msg);
					  }
					  else
					  {
					     $$->Gstptr->isFuncDefined = 1; // To mark that the function is defined.
					     original_list = $$->Gstptr->arglist;
					  }
					  $$ = $1;
					}
		;
		
	FargList:	arg_list	{ 
					  match_arguments(original_list, list_head);
					  while(original_list)
					  {
				  	    if(Llookup(original_list->name))
					    {
					      sprintf(msg,"Argument '%s' is redeclared", original_list->name);
				    	      SemError(msg);
				  	    }
					    else
					      Linsert(original_list->name, original_list->type);
				  	    original_list = original_list->next;
					  }
					  // Thus 'original_list' will be NULL.
					  // Cannot de-allocate list_head here.
					  list_head = NULL;
					}
		;

	ret_stmt:	RETURN expr ';'	{ 
					  if($2->RetType != func_type_flag)
					  	SemError("Return type mismatch");
					  else
						$$ = ConnectNodes(MakeLeaf(RET, NULL), $2, NULL);
					}
		;
			
	MainBlock: 	func_ret_type main '('')''{' Ldecl_sec BEG stmt_list ret_stmt END  '}'
					{
				  	  tmp = Ghead;
				  	  while(tmp)
				  	  {
				  	  	if(tmp->type == FUNC && !tmp->isFuncDefined)
				  	  	{
				  	  		printf("Function '%s' is declared but not defined\n", tmp->name);
				  	  		errflag = 1;
				  	  	}
				  	  	tmp = tmp->next;
				  	  }
				  	  
				  	  //fprintf(Fp, "START\n");
					  //fprintf(Fp, "HALT");

				  	  Print($8, 0);
				  	  
				  	  LCount = 0;
				  	  free(Lhead);		// Free the local symbol table.
				  	  Lhead = NULL;
					}
		;
		
	main	:	MAIN		{ 
					  if(func_type_flag != INT)
					  	SemError("Main should have return type as integer");
					}
		;
		
	Ldecl_sec:	DECL Ldecl_list ENDDECL
		;

	Ldecl_list:		
		|	Ldecl Ldecl_list
		;

	Ldecl	:	type Lid_list ';'		
		;

	type	:	T_INT			{ type_flag = INT; }
		|	T_BOOL			{ type_flag = BOOL; }
		;

	Lid_list:	Lid
		|	Lid ',' Lid_list
		;
		
	Lid	:	VAR			{
						  if(Llookup($1->name))
						  {
						 	sprintf(msg,"Variable '%s' redeclared",$1->name);
							SemError(msg);
						  } 
						  else
						  	Linsert($1->name,type_flag);
						}
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
		|	func_stmt		{ $$ = $1; }
		;

	read_stmt:	READ '(' var_expr ')' ';'{
	 					  if($3->RetType == BOOL)
	 					  	SemError("Cannot read to a boolean variable");
						  $$ = ConnectNodes(MakeLeaf(RD, NULL), $3, NULL); 
						 }
		;

	write_stmt:	WRITE '(' expr ')' ';'	{ $$ = ConnectNodes(MakeLeaf(WE, NULL), $3, NULL); }
		;
	
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
	
	func_stmt:	func_call ';'		{ $$ = $1; }
		;
		
	func_call:	VAR '(' param_list ')' 
						{
						   $1->Gstptr = Glookup($1->name);
						   
						   if(!$1->Gstptr)
						   {
						     sprintf(msg,"Function '%s' is not declared", $1->name);
						     SemError(msg);
						   }
						   else if($1->Gstptr->type != FUNC)
						   {
						     sprintf(msg,"'%s' is declared but not a function",$1->name);
						     SemError(msg);
						   }
						   else
						   {
						     match_parameters($1->Gstptr->arglist, list_head);
						     $1->list = expr_head;
						     $$->list = expr_head;
						     $$ = ConnectNodes(MakeLeaf(FUNC, $1->name), $1, NULL);
						     $$->RetType = $1->Gstptr->FuncRetType;
						   }
						   expr_head = NULL;
						   list_head = NULL;
						}
		;
		
	param_list:				
		|	param_list1		
		;
		
	param_list1:	para			
		|	para ',' param_list1	
		;

	para	:	expr			{ 
						  /* We need to pass the return types of each parameter
						     for checking type equivalence.			
						  */ 
						  createList("\0", $1->RetType);	
						  
						  /* This is to obtain the ASTs corresponding to the induvidual
						     parameters.We need them for code generation.
						  */
						  if(expr_head == NULL)
						  {
						  	expr_head = $1;
						  	expr_head->next = NULL;
						  }
						  else
						  {
						  	$$->next = expr_head;
						  	expr_head = $$;
						  }
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
		|	func_call		{ $$ = $1; }

		;
		
	var_expr:	VAR	{ 
				  $1->Lstptr = Llookup($1->name);
				  if($1->Lstptr == NULL)
				  {
					$1->Gstptr = Glookup($1->name);
					if($1->Gstptr == NULL)
					{
					   sprintf(msg, "Variable '%s' undeclared", $1->name);
					   SemError(msg);
				        }
				        else if($1->Gstptr->type == FUNC)
				        {
			        	   sprintf(msg, "Cannot use function name '%s'", $1->name);
					   SemError(msg);
					}
					else if($1->Gstptr->size != -1)	// That is the variable is actually an array.
				 	{
				  	   sprintf(msg, "Array '%s' accessed without index", $1->name);
					   SemError(msg);
					}
					$1->RetType = $1->Gstptr->type;
				  }
				  else
					$1->RetType = $1->Lstptr->type;
				  $$ = $1;
				}
		|	VAR '[' expr ']'
				{
				  $1->Gstptr = Glookup($1->name);
				  if($1->Gstptr == NULL)
				  {
					sprintf(msg, "Array '%s' undeclared", $1->name);
					SemError(msg);
				  }
				  else if($1->Gstptr->type == FUNC)
			          {
				       	sprintf(msg, "Cannot use function name '%s'", $1->name);
					SemError(msg);
				  }
				  else if($1->Gstptr->size == -1) //That is, the variable is not an array
				  {
					sprintf(msg, "'%s' is not an array", $1->Lstptr->name);
					SemError(msg);
				  }
				  else if($3->RetType == BOOL)
				  	SemError("Array index cannot be boolean");
				  
				  $1->RetType = $1->Gstptr->type;
				  
				  $$ = ConnectNodes(MakeLeaf(ARRAY, $1->name), $1, $3);
				  $$->RetType = $1->RetType;
				}
		;
%%
/*
  NOTE:
  	Parameters => the variables that are passed on a function call.
  	Arguments  => the variables in a function definition.
  	
  	Function declartion => The part written inside decl ... enddecl block.
*/
  	
void match_parameters(Argstruct* orig_list, Argstruct *passed_list)
{
	Argstruct *tmp1 = passed_list, *tmp2 = orig_list;
	
	/* Checking the argument count */
	while(tmp1 && tmp2)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	
	if(tmp1 == NULL && tmp2 != NULL)
		SemError("Too few parameters passed");
	else if(tmp1 != NULL && tmp2 == NULL)
		SemError("Too many parameters passed");
	
	/* Checking the name equivalence */
	while(passed_list && orig_list)
	{
		if(passed_list->type != orig_list->type)		// Checking for type equivalence
		{
			sprintf(msg, "Type mismatch. Expecting type '%s' ", print_name(orig_list->type));
			SemError(msg);
		}
		passed_list = passed_list->next;
		original_list = orig_list->next;
	}
}

void match_arguments(Argstruct* orig_list, Argstruct *passed_list)
{
	Argstruct *tmp1 = passed_list, *tmp2 = orig_list;
	
	/* Checking the argument count */
	while(tmp1 && tmp2)
	{
		//printf("PASSED :: %s\t", tmp1->name);
		//printf("ORIGINAL :: %s\n", tmp2->name);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	
	if(tmp1 == NULL && tmp2 != NULL)
		SemError("Too few arguments in function definition");
	else if(tmp1 != NULL && tmp2 == NULL)
		SemError("Too many arguments in function definition");
		
	/* Checking the name and type equivalence */
	while(passed_list && orig_list)
	{
		if(passed_list->type != orig_list->type)		// Checking for type equivalence
		{
			sprintf(msg, "Type mismatch for argument '%s' ", passed_list->name);
			SemError(msg);
		}
		else if(strcmp(passed_list->name ,orig_list->name) != 0)	// Checking for name equivalence
		{
			sprintf(msg, "Name '%s' is expected for '%s'", orig_list->name, passed_list->name);
			SemError(msg);
		}
		passed_list = passed_list->next;
		orig_list = orig_list->next;
	}
}           

char* print_name(int type)
{
	if(type == INT)
		return "Integer";
	else if(type == BOOL)
		return "Boolean";
}

void yyerror(char* err)
{
	printf("At line number %d :- %s.\n", Lineno, err);
}

void SemError(char* err)
{
	yyerror(err);
	exit(0);
}

void initiate()
{
	expr_head = NULL;
	list_head = NULL;
	Branching_Label = 0;
	Function_Label  = 0;
	ArrFlag         = 1;	// So that array contents will be loaded instead of just the binding.
	errflag         = 0;
	Lineno	        = 1;	// Line no: starts from 1.
	GCount          = 0;	// For binding field in global Symbol table.
	LCount          = 0;	// For binding field in local Symbol table.
	
	
}

void terminate()
{
	if(Lhead)
		free(Lhead);
	if(Ghead)
		free(Ghead);
	
	fclose(Fp);
	fclose(yyin);
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
		printf("File %s not found\n", argv[1]);
		return 0;
	}

	Fp = fopen(argv[2], "w");
	if(!Fp){
		printf("Output file cannot be created\n");
		exit(0);
	}
	
	initiate();
	yyparse();
	terminate();

	return 0;
}
