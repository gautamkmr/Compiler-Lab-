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
				
				t1 = regcount++;
				if(ptr->Lstptr)
				{
					b = ptr->Lstptr->binding;
					t2 = regcount++;	// Need another register for storing base pointer.
				
					fprintf(Fp, "MOV R%d BP\t//\tMoving base pointer to a register.\n", t2);
					fprintf(Fp, "MOV R%d %d\t//\tStoring the relative address of the variable.\n",
							 t1, b);
					fprintf(Fp, "ADD R%d R%d\t//\tAdding it with base pointer for absol. address\n",
							  t1, t2);
					fprintf(Fp, "MOV R%d [R%d]\t//\tMoving variable contents to register.\n",
							 t1, t1);
					regcount--;
				}
				else
				{
					b = ptr->Gstptr->binding;
					fprintf(Fp, "MOV R%d %d\t//\tThe variable is global,so absolute address is used",
							 t1, b);
					fprintf(Fp, "MOV R%d [R%d]\t//\tMoving variable contents to register.\n",
							 t1, t1);
				}

				return t1;
				break;

		//Recursive cases.
		case ARRAY:	 	
				t1 = CodeGen(ptr->Rptr);
				t = regcount++;
				b = ptr->Lptr->Gstptr->binding;
				fprintf(Fp, "MOV R%d %d\t//\tMoving binding field.\n", t, b);
				fprintf(Fp, "ADD R%d R%d\t//\tAdding binding with the offset.\n", t1, t);
				if(ArrFlag == 1)
					fprintf(Fp, "MOV R%d [R%d]\t//\t...and loading it onto a register.\n",
							t1,t1);
				regcount--;
				/*If ArrayFlag == 1 
					t1 will contain the value
				  otherwise
				  	t1 will contain the absolute address */ 
				return t1;
				break;
		case RD:
				t = regcount++;
				fprintf(Fp,"IN R%d\t\t//\tReading from input.\n", t);
				
				if(ptr->Lptr->Lstptr)
					b = ptr->Lptr->Lstptr->binding;
				else
					b = ptr->Lptr->Gstptr->binding;
					
				if(ptr->Lptr->NodeType == VARIABLE)
				   fprintf(Fp, "MOV [%d] R%d\t//\tMoving the read content to variable.\n",
			 	                  b, t);
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
		case FUNC:
                                fprintf(Fp, "PUSH R0\n");        // 1. Push dummy value for storing return value.
			        for(t = 0; t < 8; t++)
				  fprintf(Fp, "PUSH R%d\n", t);  // 2.Pushing machine status. 
				
				fprintf(Fp, "PUSH BP\n");	// 3. Storing caller's BP
				
				NODPTR tmp = ptr->list;
				while(tmp)
				{
					t = CodeGen(tmp);	// 4.Pushing the parameters.
					fprintf(Fp, "PUSH R%d\n", t);
					tmp = tmp->next;
				}
				fprintf("CALL F%d\n", ptr->Lptr->Gstptr->binding); // 5.Calling the function.
				// After function call.
				tmp = ptr->list;
				while(tmp) // 1. poping parameters
				{
					fprintf(Fp, "POP R0\n");
					tmp = tmp->next;
				}
				
				fprintf(Fp, "POP BP\n"); //2 .Restoring BP
				for(t = 7; t >= 0; t--)
				  fprintf(Fp, "POP R%d\n", t);  // 2.Restoring machine status.
				t1 = regcount++;
				
				fprintf("MOV R%d [SP]\n", t1);//3. Copying back the return value.
				return t1;
				  
				break;
		case EQUAL:		
				t1 = CodeGen(ptr->Rptr);
				if(ptr->Lptr->Lstptr)
					b = ptr->Lptr->Lstptr->binding;
				else
					b = ptr->Lptr->Gstptr->binding;
					
				if(ptr->Lptr->NodeType == VARIABLE)
					fprintf(Fp, "MOV [%d] R%d\t//\tAssigning register contents to variable\n",
						 b, t1);
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
				t1 = Branching_Label++;
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
				t1 = Branching_Label++;
				t2 = Branching_Label++;
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
				t1 = Branching_Label++;
				t2 = Branching_Label++;
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
