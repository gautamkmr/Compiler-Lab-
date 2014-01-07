#ifndef ABSTREE_H
#define ABSTREE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NODPTR struct node*

struct node  {
	struct node* Lptr;
	struct node* Rptr;
	char val[10];
};

NODPTR MakeLeafNode (char* );
NODPTR ConnectNodes ( NODPTR ,NODPTR , NODPTR );
void PrintTree(NODPTR ptr, int pos);
void PrintMax();
int EvaluateTree(NODPTR);

#endif
