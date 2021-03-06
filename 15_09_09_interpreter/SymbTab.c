
#include "globals.h"
#include "SymbTab.h"

SymbolTable* insert(char* sym_name, int sym_type)
{
	if(head == NULL)
	{
		head = malloc( sizeof(SymbolTable) );
		strcpy(head->name, sym_name);

		head->type = sym_type;
		head->binding = count++;
		head->size = -1;
		head->next = NULL;

		return head;
	}
	else
	{
		SymbolTable* ptr;
		ptr = malloc( sizeof(SymbolTable) );
		strcpy(ptr->name, sym_name);
		
		ptr->type = sym_type;
		ptr->binding = count++;
		ptr->size = -1;
		ptr->next = head;

		head = ptr;
		return ptr;
	}
}

SymbolTable* lookup(char* sym_name)
{
	SymbolTable* ptr;
	for(ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->name, sym_name) == 0)
			return ptr;
	}
	return NULL;
}
