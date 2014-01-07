
#ifndef SYMBTAB_H
#define SYMBTAB_H
#include "globals.h"

// To manage arguments during function declartion, definition and function call.
struct argstruct
{
	char name[MAXLEN];
	int type;
	struct argstruct* next;
};

typedef struct argstruct ArgStruct;
Argstruct* list_head;
Argstruct* createList(char* s, int t);

struct GSymbol_table
{
	char name[MAXLEN];	// Variable name or Function name.
	int type;	/* Can be of type INT, BOOL, FUNC CANNOT BE ARRAY			*/
	int binding;	/* Stores the binding (Address associated with the variable)
			   Function label no: for functions	*/
	int size;	/* To define size fields of arrays. By default size is set to -1*/

	ArgStruct* arglist;
	int FuncRetType; // 	INT, BOOL. for functions and -1 for others.
	int argcount;	// ARG count. Set to -1 by 
	struct GSymbol_table* next;
}*Ghead;

GSymbolTable* GInsert(char* s, int type, int FuncRetType, int size, int argcount, ArgStruct* arglist);

typedef struct GSymbol_table GSymbolTable ;

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


/*
 * Looks up a symbol into the symbol table.
 * Arguments:
 *	ARG1 : Specifies the name of the symbol to be looked up.
 *	      
 * Precondition	:	ARG1 cannot be NULL
 * Postcondition:	Pointer to the symboltable entry will be returned if found
 *			else NULL will be returned. 
 * Comments	:	
 */
GSymbolTable* Glookup(char*);


struct LSymbol_table
{
	char name[MAXSIZE];	// Local variable name (can have function)
	int type;		// INT/ BOOL / FUNCT
	int binding;		// For functions set -1
	struct LSymbol_table* next;
};

typedef struct LSymbol_table LSymbolTable ;

LSymbolTable* Linsert(char*, int);
LSymbolTable* Llookup(char*);

#endif
