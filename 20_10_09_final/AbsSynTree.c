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
				
				break;
		case WE:
				leaf->RetType = VOID;
				leaf->NodeType = WE;
				
				break;
		case IF_THEN:
				leaf->RetType = VOID;
				leaf->NodeType = IF_THEN;
				
				break;
		case IF_THEN_ELSE:
				leaf->RetType = VOID;
				leaf->NodeType = IF_THEN_ELSE;
				
				break;
		case DO_WHILE:
				leaf->RetType = VOID;
				leaf->NodeType = DO_WHILE;
				
				break;
		case ARRAY:	
				leaf->NodeType = ARRAY;
				leaf->Gstptr = Glookup(str);
				leaf->RetType = leaf->Gstptr->type;
				
				break;
		case EQUAL:
				leaf->RetType = VOID;
				leaf->NodeType = EQUAL;
				
				break;
		case CONST:
				leaf->NodeType = CONST;
				leaf->RetType = INT;
				leaf->value = atoi(str);
				
				break;
		case VARIABLE:
				leaf->NodeType = VARIABLE;
				strcpy(leaf->name, str);
				
				break;
		case SEQ:
				leaf->NodeType = SEQ;
				
				break;
		case FUNC:	
				leaf->NodeType = FUNC;
				leaf->RetType = VOID;
				strcpy(leaf->name, str);
				
				break;

		case RET:	leaf->NodeType = RET;
				leaf->RetType = VOID; // By default it is set to void.
				
				break;
		case PLUS:
				leaf->NodeType = PLUS;
				
				break;
		case MINUS:
				leaf->NodeType = MINUS;
				
				break;
		case MUL:	
				leaf->NodeType = MUL;
				
				break;
		case DIV:
				leaf->RetType = INT;
				leaf->NodeType = DIV;
				
				break;
		case LT:
				leaf->NodeType = LT;
				leaf->RetType = BOOL;
				
				break;
		case GT:
				leaf->NodeType = GT;
				leaf->RetType = BOOL;
				
				break;
		case GTE:	leaf->NodeType = GTE;
				leaf->RetType = BOOL;
				
				break;
		case LTE:	leaf->NodeType = LTE;
				leaf->RetType = BOOL;
				
				break;
		case NE:	leaf->NodeType = NE;
				leaf->RetType = BOOL;
				
				break;
		case ISEQUAL:	leaf->NodeType = ISEQUAL;
				leaf->RetType = BOOL;
				
				break;
		case OR:	leaf->NodeType = OR;
				leaf->RetType = BOOL;
				
				break;
		case NOT:	leaf->NodeType = NOT;
				leaf->RetType = BOOL;
				
				break;
		case AND:	leaf->NodeType = AND;
				leaf->RetType = BOOL;
				
				break;
		case TRUE:	leaf->NodeType = TRUE;
				leaf->RetType = BOOL;
				
				leaf->value = 1;
				break;
		case FALSE:	leaf->NodeType = FALSE;
				leaf->RetType = BOOL;
				
				leaf->value = 0;
				break;

	}
	
	leaf->next = leaf->Lptr = leaf->Mptr = leaf->Rptr = NULL;
	leaf->Lstptr = NULL;
	return leaf;
}

NODPTR ConnectNodes(NODPTR a, NODPTR b, NODPTR c) 
{
	a->Lptr = b;
	a->Rptr = c;
	return a;
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
		case WE:
				printf("WE\n");
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
		case LT:
				printf("LT\n");
				break;
		case GT:
				printf("GT\n");
				break;
		case LTE:
				printf("LTE\n");
				break;
		case GTE:
				printf("GTE\n");
				break;
		case EQUAL:
				printf("EQUAL\n");
				break;
		case ISEQUAL:
				printf("ISEQUAL\n");
				break;
		case IF_THEN:
				printf("IF_THEN\n");
				break;
		case IF_THEN_ELSE:
				printf("IF_THEN_ELSE\n");
				break;
		case DO_WHILE:
				printf("DO_WHILE\n");
				break;
		case AND:
				printf("AND\n");
				break;
		case OR:
				printf("OR\n");
				break;
		case NOT:
				printf("NOT\n");
				break;
		case TRUE:
				printf("TRUE\n");
				break;
		case FALSE:
				printf("FALSE\n");
				break;
		case ARRAY:
				printf("ARRAY\n");
				break;
		case RET:	
				printf("RET\n");
				break;
		case FUNC:	
				printf("FUNC\n");
				break;

	}
}
/*
int Evaluate(NODPTR ptr) {
	if(!ptr)
		return 0;

	int value, arrayindex;
	// Base cases.
	switch(ptr->NodeType)
	{
		case CONST:	
				return ptr->value;
				break;
		case TRUE:
				return ptr->value;
				break;
		case FALSE:	
				return ptr->value;
				break;
		case VARIABLE:
				return ptr->Lstptr->binding;
				break;
		case RD:
				printf("\nEnter value : ");
				scanf("%d", &value);
				if(ptr->Lptr->Lstptr->size == -1)
				{
					if(ptr->Lptr->Lstptr->type == INT)
						ptr->Lptr->Lstptr->binding = value;
					else
					{
						if(value)
							ptr->Lptr->Lstptr->binding = 1;
						else
							ptr->Lptr->Lstptr->binding = 0;
					}
				}				
				else
				{
					arrayindex = Evaluate(ptr->Lptr->Rptr);
					Array[arrayindex + ptr->Lptr->Lstptr->binding] = value;
				}
				
				return 1;
				break;
		case ARRAY:
				value = Evaluate(ptr->Rptr);
				return (Array[ value + ptr->Lptr->Lstptr->binding]);
				break;
	}
	// Recursive cases.
	switch(ptr->NodeType)
	{
		case SEQ:	
				Evaluate(ptr->Lptr);
				if(ptr->Rptr)
					Evaluate(ptr->Rptr);
				return 1;
				break;

		case PLUS:
				return (Evaluate(ptr->Lptr) + Evaluate(ptr->Rptr));
				break;

		case MINUS:
				return (Evaluate(ptr->Lptr) - Evaluate(ptr->Rptr));
				break;

		case MUL:	
				return (Evaluate(ptr->Lptr) * Evaluate(ptr->Rptr));
				break;

		case DIV:	
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
				if(ptr->Lptr->Lstptr->type == BOOL)
				{
					if(value)
						value = 1;
				}
				if(ptr->Lptr->Lstptr->size == -1)
					ptr->Lptr->Lstptr->binding = value;					
				else
				{
					arrayindex = Evaluate(ptr->Lptr->Rptr);
					Array[arrayindex + ptr->Lptr->Lstptr->binding] = value;
				}
				return 1;
				break;
		case LT:	if( Evaluate(ptr->Lptr) < Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
				break;
				
		case GT:	if( Evaluate(ptr->Lptr) > Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
				break;
		case LTE:
				if( Evaluate(ptr->Lptr) <= Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
				break;
		case GTE:	
				if( Evaluate(ptr->Lptr) >= Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
				break;
		case ISEQUAL:	if( Evaluate(ptr->Lptr) == Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
		
				break;
		case NE:	if( Evaluate(ptr->Lptr) != Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
				break;
		case AND:	
				if( Evaluate(ptr->Lptr) && Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;
				
				break;
		case OR:
				if( Evaluate(ptr->Lptr) || Evaluate(ptr->Rptr))
					return 1;
				else
					return 0;

				break;
		case NOT:
				if(!Evaluate(ptr->Lptr))
					return 1;
				else
					return 0;

				break;
		case IF_THEN:	
				if(Evaluate(ptr->Lptr))
					Evaluate(ptr->Rptr);
				return 1;
				break;
		case IF_THEN_ELSE:
				if(Evaluate(ptr->Lptr))
					Evaluate(ptr->Mptr);
				else
					Evaluate(ptr->Rptr);
				return 1;
		
				break;						
		case DO_WHILE:	
				while(Evaluate(ptr->Lptr))
					Evaluate(ptr->Rptr);
				return 1;
				break;
	}	
	
}*
*/
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
		if(ptr->NodeType == IF_THEN_ELSE)
			Print(ptr->Mptr, t);
		if(ptr->Rptr)
			Print(ptr->Rptr, t);
	}

}



