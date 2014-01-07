
#include "globals.h"
#include "SymbTab.h"

GSymbolTable* insert(char* sym_name, int sym_type)
{
	if(Ghead == NULL)
	{
		Ghead = malloc( sizeof(SymbolTable) );
		strcpy(Ghead->name, sym_name);

		Ghead->type = sym_type;
		Ghead->binding = Count++;
		Ghead->size = -1;
		Ghead->next = NULL;

		return Ghead;
	}
	else
	{
		SymbolTable* ptr;
		ptr = malloc( sizeof(SymbolTable) );
		strcpy(ptr->name, sym_name);
		
		ptr->type = sym_type;
		ptr->binding = Count++;
		ptr->size = -1;0.
		ptr->next = Ghead;

		Ghead = ptr;
		return ptr;
	}
}

GSymbolTable* lookup(char* sym_name)
{
	GSymbolTable* ptr;
	for(ptr = Ghead; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->name, sym_name) == 0)
			return ptr;
	}
	return NULL;
}

GSymbolTable* GInsert(char* s, int type, int rtype, int sz, int argc, ArgStruct* list)
{
}
Argstruct* createList(char* s, int t)
{}
