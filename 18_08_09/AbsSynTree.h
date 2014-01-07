
#ifndef ABSTREE_H
#define ABSTREE_H

#include "SymbTab.h"
#include "globals.h"

#define NODPTR struct node*
struct node
{
	SymbolTable* stptr;	/* Symbol table entry corresponding to the node */
	char name[MAXLEN];

	int RetType;		/* Integer, Boolean, Void type 			*/
	int NodeType;		/* To define the type of Node.			*/
	
	int value;		/* For storing values of constants.		*/
	NODPTR Lptr;
	NODPTR Mptr;
	NODPTR Rptr;
};

int reg[8];
NODPTR MakeLeaf(int type, char* str);
NODPTR ConnectNodes(NODPTR, NODPTR, NODPTR);
int Evaluate(NODPTR);

void Print(NODPTR, int);
void printType(int, int);
#endif
