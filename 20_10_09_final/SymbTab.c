#include "globals.h"
#include "SymbTab.h"

void PrintSymTable() 
{
	GSymbolTable* tempGhead = Ghead;
	while(tempGhead) {
		printf("\ntName : %s ; Type : %d ; FuncReturn Type : %d ; Size : %d ; Arg count : %d ; Binding : %d" ,
			tempGhead->name, tempGhead->type, tempGhead->FuncRetType, tempGhead->size, tempGhead->argcount,
			tempGhead->binding);
		tempGhead = tempGhead->next;	
	}
}

void PrintLSymTable() 
{
	LSymbolTable* tempLhead = Lhead;
	while(tempLhead) {
		printf("\nName : %s ; Type : %d ; Binding : %d",
			tempLhead->name, tempLhead->type, tempLhead->binding);
		tempLhead = tempLhead->next;	
	}
}

void createList(char* name, int type)
{
	if(list_head == NULL)
	{ 
		list_head = malloc(sizeof(Argstruct));
		
		strcpy(list_head->name,name);
		list_head->type  = type;
		list_head->next  = NULL;
   	}
	else
	{
		Argstruct* ptr;
		ptr = malloc(sizeof(Argstruct));
		
		strcpy(ptr->name,name);
		ptr->type  = type;
		ptr->next  = list_head;
		list_head  = ptr;
	}
}

GSymbolTable* Ginsert(char* name, int type, int rtype, int size, Argstruct* list)
{
	int argc = 0;
	Argstruct* tmp = list;
	while(tmp)
	{
		argc++;
		tmp = tmp->next;
	}

	if(Ghead == NULL)
	{
		Ghead = malloc(sizeof(GSymbolTable));
		
		strcpy(Ghead->name, name);
		Ghead->type        = type;
		Ghead->FuncRetType = rtype;
		Ghead->size        = size;
		Ghead->argcount    = argc;
		Ghead->arglist     = list;
		Ghead->isFuncDefined = 0;
		if(type != FUNC) 
			Ghead->binding = GCount++;
		else
			Ghead->binding = Function_Label++;
		Ghead->next = NULL;
		
		return Ghead;
	}
	else
	{
		GSymbolTable *ptr;
		ptr = malloc(sizeof(GSymbolTable));
		
		strcpy(ptr->name, name);
		ptr->type        = type;
		ptr->FuncRetType = rtype;
		ptr->size        = size;
		ptr->argcount    = argc;
		ptr->arglist     = list; 
		ptr->isFuncDefined = 0;
		if(type != FUNC)
			ptr->binding = GCount++;
		else
			ptr->binding = Function_Label++;
		ptr->next = Ghead;
		Ghead     = ptr;
		
		return ptr;
	}
}

GSymbolTable* Glookup(char* sym_name)
{
	GSymbolTable* ptr;
	for(ptr = Ghead; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->name, sym_name) == 0)
			return ptr;
	}
	return NULL;
}

LSymbolTable* Llookup(char* sym_name)
{
	LSymbolTable* ptr;
	for(ptr = Lhead; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->name, sym_name) == 0)
			return ptr;
	}
	return NULL;
}

LSymbolTable* Linsert(char* sym_name, int sym_type)
{
	if(Lhead == NULL)
	{
		Lhead = malloc( sizeof(LSymbolTable) );
		strcpy(Lhead->name, sym_name);

		Lhead->type = sym_type;
		Lhead->binding = LCount++;
		Lhead->next = NULL;

		return Lhead;
	}
	else
	{
		LSymbolTable* ptr;
		ptr = malloc( sizeof(LSymbolTable) );
		strcpy(ptr->name, sym_name);
		
		ptr->type = sym_type;
		ptr->binding = LCount++;
		ptr->next = Lhead;

		Lhead = ptr;
		return ptr;
	}
}

