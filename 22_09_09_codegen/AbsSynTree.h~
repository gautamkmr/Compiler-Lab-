
#ifndef ABSTREE_H
#define ABSTREE_H

#include "SymbTab.h"
#include "globals.h"

#define NODPTR struct node*
struct node
{
	SymbolTable* stptr;	/* Symbol table entry corresponding to the node */
	char name[MAXLEN];	/* Contains name in case of variables		*/

	int RetType;		/* Integer, Boolean, Void type 			*/
	int NodeType;		/* To define the type of Node.			*/
	
	int value;		/* For storing values of constants.		*/
	NODPTR Lptr;
	NODPTR Mptr;
	NODPTR Rptr;
};

/*
 * Connects nodes in the following manner.
 * 	Node1->Lptr = Node2
 * 	Node1->Rptr = Node3
 * Arguments:
 *	Node1 := ARG1
 *	Node2 := ARG2
 *	Node3 := ARG3
 * Precondition	:	None of the arguments should be NULL
 * Postcondition:	Nodes will be connected as explained
 */
NODPTR ConnectNodes(NODPTR, NODPTR, NODPTR);

/*
 * Makes new nodes of specified type.
 * Arguments:
 *	ARG1 : Specifies the type of node to be created.
 *	ARG2 : Name of the node.( Needs to specified only for variables
 *
 * Precondition	:	'type' must be previously specified in globals.h
 *			ARG2 can also be NULL
 * Postcondition:	A new node of specified type will be returned
 * Comments	:
 */
NODPTR MakeLeaf(int type, char* str);

/*
 * Evaluates (simulates) the abstract syntax tree.
 * Arguments:
 *	ARG1 : Specifies the root of the AST.
 *
 * Precondition	:	NONE
 * Postcondition:	The AST will be evaluated.
 * Comments	:	Semantic errors etc. will be reported.
 */
int Evaluate(NODPTR);

/*
 * Prints the AST (Recursively).
 * Arguments:
 *	ARG1 : Specifies the root of the AST.
 *	ARG2 : Specifies the shift.
 * Precondition	:	NONE
 * Postcondition:	The AST will be printed.
 * Comments	:	ARG2 is specified as 0, i.e, tree is printed at 0 shift.
 *			ARG2 has to do only to do with recursion.
 */
void Print(NODPTR, int);

/*
 * Prints the type of the node.
 * Arguments:
 *	ARG1 : Specifies the type of node.
 *	ARG2 : Specifies the shift.
 * Precondition	:	NONE
 * Postcondition:	The node type will be printed.
 * Comments	:	ARG2 has to do only to do with recursion.
 */
void printType(int, int);
#endif
