#include "codegen.h"

void setRegZero()
{
	int i;
	for(i = 0; i < 8; i++)
		reg[i] = 0;
}

int getFreeReg()
{
	int i;
	for(i = 0; (i < 8) && reg[i] ; i++) 
	;
	if(i > 7)
		printf("Registers exhausted\n");
	reg[i] = 1;
	return i;
}
		
int CodeGen(NODPTR ptr)
{
	int t1, t2, t;	
	switch(ptr->NodeType)
	{
		case CONST:
					t = getFreeReg();
					fprintf(fp, "MOV R%d %d\n", t, ptr->value);
					return t;
					break;
		case VARIABLE:
					t = getFreeReg();
					fprintf(fp, "MOV R%d [%d]\n", t, ptr->stptr->binding);
					return t;
					break;
		case RD:
					t = getFreeReg();
					fprintf(fp,"IN R%d\n", t);
					fprintf(fp, "MOV [%d] R%d\n", ptr->Lptr->stptr->binding, t);
					reg[t] = 0;
					return 0;
					break;
		//Recursive cases.
		case WE:
					t2 = CodeGen(ptr->Lptr);
					t1 = getFreeReg();
					fprintf(fp, "MOV R%d R%d \n", t1, t2);
					fprintf(fp,"OUT R%d\n", t1);
					reg[t1] = 0;
					reg[t2] = 0;
					return 0;
					break;
		case PLUS:
					t1 = CodeGen(ptr->Rptr);
					t2 = CodeGen(ptr->Lptr);
					fprintf(fp, "ADD R%d R%d\n", t2, t1);
					reg[t1] = 0;
					return t2;
					break;
		case MINUS:
					t1 = CodeGen(ptr->Rptr);
					t2 = CodeGen(ptr->Lptr);
					fprintf(fp, "SUB R%d R%d\n", t2, t1);
					reg[t1] = 0;
					return t2;
					break;
		case MUL:
					t1 = CodeGen(ptr->Rptr);
					t2 = CodeGen(ptr->Lptr);
					fprintf(fp, "MUL R%d R%d\n", t2, t1);
					reg[t1] = 0;
					return t2;
					break;
		case DIV:
					t1 = CodeGen(ptr->Rptr);
					t2 = CodeGen(ptr->Lptr);
					fprintf(fp, "DIV R%d R%d\n", t2, t1);
					reg[t1] = 0;
					return t2;
					break;
		case SEQ:
					CodeGen(ptr->Lptr);
					if(ptr->Rptr)
						CodeGen(ptr->Rptr);
					return 0;
					break;
		case EQUAL:
					t1 = CodeGen(ptr->Rptr);
					fprintf(fp, "MOV [%d] R%d\n", ptr->Lptr->stptr->binding, t1);
					return 0;
					break;
	}
}
