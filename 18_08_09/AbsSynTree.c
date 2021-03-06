#include "AbsSynTree.h"

NODPTR MakeLeaf(int type, char* str)
{
	NODPTR leaf; 
	leaf = malloc(sizeof(struct node));
	switch(type)
	{
		case RD:
				leaf->RetType = VOID;
				leaf->NodeType = RD;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case WE:
				leaf->RetType = VOID;
				leaf->NodeType = WE;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case EQUAL:
				leaf->RetType = BOOL;
				leaf->NodeType = EQUAL;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case CONST:
				leaf->NodeType = CONST;
				leaf->RetType = INT;			// Constants are integers by default.
				leaf->value = atoi(str);
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case VARIABLE:
				leaf->NodeType = VARIABLE;
				strcpy(leaf->name, str);
				leaf->stptr = lookup(str);
				leaf->RetType = leaf->stptr->type;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				break;
		case SEQ:
				leaf->NodeType = SEQ;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case PLUS:
				leaf->NodeType = PLUS;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case MINUS:
				leaf->NodeType = MINUS;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case MUL:
				leaf->NodeType = MUL;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
		case DIV:
				leaf->RetType = INT;
				leaf->NodeType = DIV;
				leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
				leaf->stptr = NULL;
				break;
	}
	return leaf;
}

NODPTR ConnectNodes(NODPTR a, NODPTR b, NODPTR c) 
{
	a->Lptr = b;
	a->Rptr = c;
	return a;
}

int Evaluate(NODPTR ptr) {
	if(!ptr)
		return 0;
	int value;
	// Base cases.
	switch(ptr->NodeType)
	{
		case CONST:	
				return ptr->value;
				break;
		case VARIABLE:
				return ptr->stptr->binding;
				break;
		case RD:
				printf("\nEnter value : ");
				scanf("%d", &value);
				if(ptr->Lptr->stptr->type == INT)
					ptr->Lptr->stptr->binding = value;
				else
				{
					if(value)
						ptr->Lptr->stptr->binding = 1;
					else
						ptr->Lptr->stptr->binding = 0;
				}
				return 1;
				break;
	}
	// Recursive cases.
	switch(ptr->NodeType)
	{
		case SEQ:	
				Evaluate(ptr->Lptr);
				Evaluate(ptr->Rptr);
				return 1;
				break;

		case PLUS:
				if(ptr->Lptr->RetType != ptr->Rptr->RetType)
					printf("Warning: Adding unmatched types\n");
				else 
				{void setRegZero();
					if(ptr->Lptr->RetType == BOOL)
						return (Evaluate(ptr->Lptr) | Evaluate(ptr->Rptr));
				}
				
				return (Evaluate(ptr->Lptr) + Evaluate(ptr->Rptr));
				break;

		case MINUS:
				if(ptr->Lptr->RetType != ptr->Rptr->RetType)
					printf("Warning: Subtracting unmatched types\n");
				else
				{
					if(ptr->Lptr->RetType == BOOL)
						return (Evaluate(ptr->Lptr) ^ Evaluate(ptr->Rptr));
				}

				return (Evaluate(ptr->Lptr) + Evaluate(ptr->Rptr));
				break;

		case MUL:	
				if(ptr->Lptr->RetType != ptr->Rptr->RetType)
					printf("Warning: Multiplying unmatched types\n");
				else
				{
					if(ptr->Lptr->RetType == BOOL)
						printf("Warning: Boolean multiplication\n");
				}

				return (Evaluate(ptr->Lptr) * Evaluate(ptr->Rptr));
				break;

		case DIV:	if(ptr->Lptr->RetType != ptr->Rptr->RetType)
					printf("Warning: Dividing unmatched types\n");
				else
				{
					if(ptr->Lptr->RetType == BOOL)
						printf("Warning: Boolean division\n");
				}
				value = Evaluate(ptr->Rptr);
				if(!value)
				{
					printf("Fatal!!Division by zero error\n");
					exit(0);
				}
				return (Evaluate(ptr->Lptr) / value);
				break;

		case WE:
				printf("%d\n", Evaluate(ptr->Lptr));
				return 1;
				break;

		case EQUAL:	value = Evaluate(ptr->Rptr);
				if(ptr->Lptr->stptr->type == BOOL)
				{
					if(value)
						value = 1;
				}
				ptr->Lptr->stptr->binding = value;					
				return 1;
				break;
	}	
}

void printType(int val, int t)
{
	while(t--)
		printf("\t");
	switch(val)
	{
		case CONST:	
				printf("CONST\n");
				break;
		case VARIABLE:
				printf("VAR\n");
				break;
		case RD:
				printf("RD\n");				
				break;
		case SEQ:	
				printf("SEQ\n");
				break;

		case PLUS:
				printf("PLUS\n");
				break;

		case MINUS:
				printf("MINUS\n");
				break;

		case MUL:	
				printf("MUL\n");
				break;

		case DIV:					
				printf("DIV\n");
				break;

		case WE:
				printf("WE\n");
				break;

		case EQUAL:
				printf("EQUAL\n");
				break;
	}
}

void Print(NODPTR ptr,int t)
{
	if(!ptr)
	{	printf("Got NULL value\n");	return;}
	
	if(ptr->Lptr == NULL && ptr->Rptr == NULL)
		printType(ptr->NodeType, t);
	else
	{
		printType(ptr->NodeType, t);
		t++;
		Print(ptr->Lptr, t);
		if(ptr->Rptr)
			Print(ptr->Rptr, t);
	}

}

