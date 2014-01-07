
#ifndef SYMBTAB_H
#define SYMBTAB_H
#include "globals.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * 
*				Argument list structure						*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct argstruct
{
	char name[MAXLEN];	// Variable name 
	int type;		// Type of variable - INT, BOOL, NUM, ARRAY
	struct argstruct* next;
} * list_head;			// This is used as the head of linked list to collect parameters and arguments.


typedef struct argstruct Argstruct;
/*
 * Creates argument list by inserting arguments passed.
 * Arguments:
 *	ARG1 : Specifies the name of the symbol to be looked up.
 *	ARG2 : Type of the symbol (INT or BOOL)
 *    
 * Precondition	:	ARG1 can be NULL
 *			
 * Postcondition:	The argument will be added to the list's beginning.
 *
 * Comments	:	Arguments are collected in the reverse order.
 			Avoid passing a NULL for argument 1
 */
void createList(char*, int);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *  *
 *				Global symbol table structure					*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct GSymbol_table
{
	char name[MAXLEN];	/* Variable name or Function name. 		*/
	int type;		/* Can be of type INT, BOOL, FUNC		*/
	int binding;		/* Stores 
				   -> binding (Address) associated with the variable
			  	   -> function label no: for functions		*/

	int size;		/* To define size field of arrays.
				   -> For arrays size of arrays
				   -> For others -1				*/

	Argstruct* arglist;	/* Structure for storing the arguments 
				   -> Stores argument list for functions
				   -> NULL for others				*/

	int FuncRetType;	/* Stores 
				   -> For functions INT, BOOL 
				   -> For others -1				*/
	int isFuncDefined;	/* Aim
				    ->	To catch re-definitions and non-definitions of functions.
				   Stores (Only for functions)
				   -> For undefined functions  -- 0
				   -> For defined functions    -- 1		*/
				   
	int argcount;		/* Stores argument count.
				   -> For functions set to argument count.
				   -> For others set to -1			*/
	struct GSymbol_table* next;
}*Ghead;
typedef struct GSymbol_table GSymbolTable ;
/*
 * Inserts an entry into the global symbol table.
 * Arguments:
 *	ARG1 : Specifies the name of the symbol.
 *	ARG2 : Specifies the variable type i,e. INT, BOOL, FUNC.
 *	ARG3 : Specifies the return type for functions.
 *	ARG4 : Specifies the size for arrays.
 *	ARG5 : Specifies the argument list for functions.
 *	      
 * Precondition	:	ARG1 cannot be NULL
 *			ARG2 can be of type INT, BOOL (No explicit check for this is done)
 * Postcondition:	A new entry will be added to the symbol table and
			pointer to it is returned.
 * Comments	:	
 */
GSymbolTable* Ginsert(char* name, int type, int rtype, int size, Argstruct* list);

/*
 * Looks up a symbol from the symbol table.
 *
 * Arguments:
 *	ARG1 : Specifies the name of the symbol to be looked up.
 *	      
 * Precondition	:	ARG1 cannot be NULL
 * Postcondition:	Pointer to the symboltable entry will be returned if found
 *			else NULL will be returned. 
 * Comments	:	
 */
GSymbolTable* Glookup(char*);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * *  *
 *				Local symbol table structure					*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct LSymbol_table
{
	char name[MAXLEN];
	int type;		// INT / BOOL
	int binding;
	struct LSymbol_table* next;
}* Lhead;

typedef struct LSymbol_table LSymbolTable ;

/*
 * Inserts a symbol into the symbol table.
 * Arguments:
 *	ARG1 : Specifies the name of the symbol.
 *	ARG2 : Specifies the variable type i,e.INT or BOOL
 *	      
 * Precondition	:	ARG1 cannot be NULL
 *			ARG2 can be of type INT, BOOL (No explicit check for this is done)
 * Postcondition:	A new entry will be added to the symbol table and 
			pointer to it is returned.
 * Comments	:	
 */
LSymbolTable* Linsert(char*, int);

/*
 * Looks up a symbol from the symbol table.
 * Arguments:
 *	ARG1 : Specifies the name of the symbol to be looked up.
 *	      
 * Precondition	:	ARG1 cannot be NULL
 * Postcondition:	Pointer to the symboltable entry will be returned if found
 *			else NULL will be returned. 
 * Comments	:	
 */
LSymbolTable* Llookup(char*);

void PrintSymTable ();
void PrintLSymTable ();
#endif
