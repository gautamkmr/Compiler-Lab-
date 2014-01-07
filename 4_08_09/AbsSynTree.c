#include "AbsSynTree.h"
#include <stdlib.h>

static int height = 0;

struct node* MakeLeafNode (char* value) {
	NODPTR leaf; 
	leaf = malloc(sizeof(struct node));
	strcpy(leaf->val, value);
	leaf->Lptr = NULL;
	leaf->Rptr = NULL;
	return(leaf);
}

struct node* MakeLeafNodeInt (int value) {
	NODPTR leaf; 
	char* charval;
	leaf = malloc(sizeof(struct node));
	charval = malloc(sizeof(char)*10);
	sprintf(charval, "%d", value);
	strcpy(leaf->val, charval);
	leaf->Lptr = NULL;
	leaf->Rptr = NULL;
	return(leaf);
}


struct node* ConnectNodes ( NODPTR a,NODPTR b, NODPTR c) {
	a->Lptr = b;
	a->Rptr = c;
	return a;
}

void RecursivePrint(NODPTR ptr) {
	if (ptr->Lptr == NULL && ptr->Rptr == NULL) {
		printf(" %s ",ptr->val);
	}
	else {
		RecursivePrint(ptr->Lptr);
		printf(" %s ",ptr->val);
		RecursivePrint(ptr->Rptr);
	}
}

void PrintMax() {
	printf("\nMaximum height of the tree is %d\n", height);
	height=0;
}

void PrintTree(NODPTR ptr, int pos) {
	if (ptr->Lptr == NULL && ptr->Rptr == NULL) {
		if(pos > height) height = pos;
		printf("%*s\n",pos*5,ptr->val);
	}
	else {
		printf("%*s\n",pos*5,ptr->val);
		pos++;
		PrintTree(ptr->Lptr,pos);
		PrintTree(ptr->Rptr,pos);
	}
}

int EvaluateTree(NODPTR ptr) {
	if (ptr->Lptr == NULL && ptr->Rptr == NULL) {
		return atoi(ptr->val);
	}
	else {
		if(strcmp((ptr->val),"+")==0) {
			return ((EvaluateTree(ptr->Lptr))+(EvaluateTree(ptr->Rptr)));
		}
		if(strcmp((ptr->val),"-")==0) {
			return ((EvaluateTree(ptr->Lptr))-(EvaluateTree(ptr->Rptr)));
		}
		if(strcmp((ptr->val),"*")==0) {
			return ((EvaluateTree(ptr->Lptr))*(EvaluateTree(ptr->Rptr)));
		}
		if(strcmp((ptr->val),"/")==0) {
			return ((EvaluateTree(ptr->Lptr))/(EvaluateTree(ptr->Rptr)));
		}
	}
}