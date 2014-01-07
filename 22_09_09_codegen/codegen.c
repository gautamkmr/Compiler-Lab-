#include "codegen.h"
		
int CodeGen(NODPTR ptr)
{
	int t1, t2, t, b;	
	switch(ptr->NodeType)
	{
		case CONST:
				t = regcount++;
				fprintf(Fp, "MOV R%d %d\t//\tMoving constant to a register.\n",
							 t, ptr->value);
				return t;
				break;
		case TRUE:
				t = regcount++;
				fprintf(Fp, "MOV R%d %d\t//\tMoving true(1) to a register.\n",
							 t, ptr->value);
				return t;
				break;
		case FALSE:
				t = regcount++;
				fprintf(Fp, "MOV R%d %d\t//\tMoving false(0) to a register.\n",
							 t, ptr->value);
				return t;
				break;
		case VARIABLE:		
				t = regcount++;
				fprintf(Fp, "MOV R%d [%d]\t//\tMoving variable to a register.\n",
							 t, ptr->stptr->binding);
				return t;
				break;

		//Recursive cases.
		case ARRAY:	 	
				t1 = CodeGen(ptr->Rptr);
				t = regcount++;
				b = ptr->Lptr->stptr->binding;
				fprintf(Fp, "MOV R%d %d\t//\tMoving binding field.\n", t, b);
				fprintf(Fp, "ADD R%d R%d\t//\tAdding binding with the offset.\n", t1, t);
				if(ArrFlag == 1)
					fprintf(Fp, "MOV R%d [R%d]\t//\t...and loading it onto a register.\n",
							t1,t1);
				regcount--;
				return t1;
				break;
		case RD:
				t = regcount++;
				fprintf(Fp,"IN R%d\t\t//\tReading from input.\n", t);
				if(ptr->Lptr->NodeType == VARIABLE)
				   fprintf(Fp, "MOV [%d] R%d\t//\tMoving the read content to variable.\n",
			 	                  ptr->Lptr->stptr->binding, t);
				else
				{
					// Done inorder to generate code to obtain array binding field.
					ArrFlag = 0;
					t1 = CodeGen(ptr->Lptr);
					ArrFlag = 1;
					fprintf(Fp, "MOV [R%d] R%d\t//\tMoving the read content to an array.\n",
								t1, t);
					regcount--;
				}
				regcount--;
				break;
		case WE:
				t = CodeGen(ptr->Lptr);
				fprintf(Fp,"OUT R%d\t\t//\tOutput the register content\n", t);
				regcount--;
				return 0;
				break;
		case PLUS:
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "ADD R%d R%d\t//\tPLUS\n", t1, t2);
				regcount--;
				return t1;
				break;
		case MINUS:
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "SUB R%d R%d\t//\tMINUS\n", t1, t2);
				regcount--;
				return t1;
				break;
		case MUL:
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "MUL R%d R%d\t//\tMUL\n", t1, t2);
				regcount--;
				return t1;
				break;
		case DIV:
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "DIV R%d R%d\t//\tDIV\n", t1, t2);
				regcount--;
				return t1;
				break;
		case SEQ:
				CodeGen(ptr->Lptr);
				if(ptr->Rptr)
					CodeGen(ptr->Rptr);
				return 0;
				break;
		case EQUAL:		
				t1 = CodeGen(ptr->Rptr);
				if(ptr->Lptr->NodeType == VARIABLE)
					fprintf(Fp, "MOV [%d] R%d\t//\tAssigning register contents to variable\n",
						 ptr->Lptr->stptr->binding, t1);
				else
				{
					// Done inorder to generate code to obtain array binding field.
					ArrFlag = 0;
					t2 = CodeGen(ptr->Lptr);
					ArrFlag = 1;
					fprintf(Fp, "MOV [R%d] R%d\t//\tAssigning register contents to array\n",
							 t2, t1);
					regcount--;
				}
				regcount--;
				return 0;
				break;

		case GT:
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "GT R%d R%d\t//\tGreater than.\n", t1, t2);
				regcount--;
				return t1;
				break;
		case LT:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "LT R%d R%d\t//\tLesser than.\n", t1, t2);
				regcount--;
				return t1;
				break;
		case GTE:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "GE R%d R%d\t//\tGreater than or equal.\n", t1, t2);
				regcount--;
				return t1;
				break;

		case LTE:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "LE R%d R%d\t//\tLesser than or equal.\n", t1, t2);
				regcount--;
				return t1;
				break;
					
		case ISEQUAL:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "EQ R%d R%d\t//\tIs equal.\n", t1, t2);
				regcount--;
				return t1;
				break;

		case NE:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "NE R%d R%d\t//\tIs not equal.\n", t1, t2);
				regcount--;
				return t1;
				break;

		case AND:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "MUL R%d R%d\t//\tAND operation.\n", t1, t2);
				regcount--;
				return t1;
				break;
					
		case OR:		
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "ADD R%d R%d\t//\tOR operation.\n", t1, t2);
				fprintf(Fp, "MOV R%d %d\t//\tOR operation.\n", t2, 0);
				fprintf(Fp, "NE R%d R%d\t//\tOR operation.\n", t1, t2);
				regcount--;
				return t1;
				break;
					
		case NOT:		
				t = regcount++;
				t1 = CodeGen(ptr->Lptr);
				fprintf(Fp, "MOV R%d %d\t//\tNOT operation.\n", t, 1);
				fprintf(Fp, "SUB R%d R%d\t//\tNOT operation.\n", t, t1);
				regcount--;
				return t;
				break;

		case IF_THEN:	
				t1 = Label++;
				t = CodeGen(ptr->Lptr);
				fprintf(Fp, "JZ R%d L%d\t// If then\n", t, t1);
				regcount--;		// Freeing the register.
				CodeGen(ptr->Rptr);
				fprintf(Fp, "L%d:\t\t// Endif\n",t1);
				return 0;
				break;
		case IF_THEN_ELSE:
				t = CodeGen(ptr->Lptr);
				// Two labels are needed for if else
				t1 = Label++;
				t2 = Label++;
				fprintf(Fp, "JZ R%d L%d\t// If then else\n", t, t1);
				regcount--;		// Freeing the register.
				CodeGen(ptr->Mptr);
				fprintf(Fp, "JMP L%d\n", t2);
				fprintf(Fp, "L%d:\t\t// ...else\n", t1);
				CodeGen(ptr->Rptr);
				fprintf(Fp, "L%d:\t\t// End if else\n",t2);
				return 0;
				break;
		case DO_WHILE:
				// Two labels are needed for while do
				t1 = Label++;
				t2 = Label++;
				fprintf(Fp, "L%d:\n",t1);
				t = CodeGen(ptr->Lptr);
				fprintf(Fp, "JZ R%d L%d\t// While do\n", t, t2);
				regcount--;		// Freeing the register.
				CodeGen(ptr->Rptr);
				fprintf(Fp, "JMP L%d\t\t// Endwhile\n", t1);
				fprintf(Fp, "L%d:\n",t2);
				return 0;					
				break;
	}
}
