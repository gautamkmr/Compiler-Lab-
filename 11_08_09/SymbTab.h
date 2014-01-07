
#ifndef SYMBTAB_H
#define SYMBTAB_H
#include "globals.h"

struct Symbol_table
{
	char name[MAXLEN];
	int type;	/* Can be of type INT or BOOL 		*/
	int binding;
	int size;	/* To define size fields of arrays.	*/
	struct Symbol_table* next;
} *head;

typedef struct Symbol_table SymbolTable ;

SymbolTable* insert(char*, int);
SymbolTable* lookup(char*);

#endif
