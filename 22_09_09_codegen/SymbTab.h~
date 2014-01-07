
#ifndef SYMBTAB_H
#define SYMBTAB_H
#include "globals.h"

struct Symbol_table
{
	char name[MAXLEN];
	int type;	/* Can be of type INT, BOOL					*/
	int binding;	/* Stores the binding (Address associated with the variable)	*/
	int size;	/* To define size fields of arrays. By default size is set to -1*/
	struct Symbol_table* next;
} *head;

typedef struct Symbol_table SymbolTable ;

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
SymbolTable* insert(char*, int);

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
SymbolTable* lookup(char*);

#endif
