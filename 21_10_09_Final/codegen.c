#include "codegen.h"
		
int CodeGen(NODPTR ptr)
{
	int t1, t2, t, b, count;
	LSymbolTable* func_Lhead;
	GSymbolTable* func_stptr, *t_head;
	if(!ptr)
	{
		printf("NULL SEEN\n");
		exit(0);
	}
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
					t2 = regcount++;	// Need a register for storing base pointer.
				
					fprintf(Fp, "MOV R%d BP\t//\tMoving base pointer to a register.\n", t2);
					fprintf(Fp, "MOV R%d %d\t//\tStoring the relative address of the variable.\n",
							 t1, b);
					fprintf(Fp, "ADD R%d R%d\t//\tComputing absolute address...\n",
							  t1, t2);
					fprintf(Fp, "MOV R%d [R%d]\t//\tMoving variable contents to register.\n",
							 t1, t1);
					regcount--;
				}
				else
				{
					b = ptr->Gstptr->binding;
					fprintf(Fp, "MOV R%d [%d]\t//\tMoving variable contents to register.\n",
							 t1, b);
				}
				return t1;
				break;

		//Recursive cases.
		case ARRAY:	 	
				t1 = CodeGen(ptr->Rptr);	// Evaluating the expression in index field.
				t = regcount++;			// Need a register to store the offset.
				b = ptr->Lptr->Gstptr->binding;
				
				fprintf(Fp, "MOV R%d %d\t//\tMoving binding field...\n", t, b);
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
				
				if(ptr->Lptr->Lstptr)
				{
					b = ptr->Lptr->Lstptr->binding;
					
					t1 = regcount++;	// Need a register for storing relative address.
					t2 = regcount++;	// Need a register for storing base pointer.
				
					fprintf(Fp, "MOV R%d BP\t//\tMoving base pointer to a register.\n", t2);
					fprintf(Fp, "MOV R%d %d\t//\tStoring the relative address of the variable.\n",
							 t1, b);
					fprintf(Fp, "ADD R%d R%d\t//\tComputing absolute address...\n",
							  t1, t2);
					fprintf(Fp, "MOV [R%d] R%d\t//\tMoving the read content to variable.\n",
			 	                  	t1, t);
			 	        regcount -= 2;
				}
				else
				{
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
		case MOD:
				t1 = CodeGen(ptr->Lptr);
				t2 = CodeGen(ptr->Rptr);
				fprintf(Fp, "MOD R%d R%d\t//\tMOD\n", t1, t2);
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
				if(ptr->Lptr)
					CodeGen(ptr->Lptr);
				if(ptr->Rptr)
					CodeGen(ptr->Rptr);
				return 0;
				break;
		case FUNC:
                                fprintf(Fp, "PUSH R0\t\t// Pushing dummy variable for storing return value.\n");
                                for(t = 0; t < 8; t++)
					fprintf(Fp, "PUSH R%d\n", t);
				fprintf(Fp, "PUSH BP\t\t// Storing caller's BP.\n");
				
				NODPTR tmp = ptr->list;
				while(tmp)
				{
					t = CodeGen(tmp);
					fprintf(Fp, "PUSH R%d\t\t// Pushing the parameter.\n", t);
					regcount--;	// Since the register is no longer needed.
					tmp = tmp->next;
				}
				
				fprintf(Fp, "CALL F%d\t\t// Making the function call.\n", ptr->Lptr->Gstptr->binding);
				
				// After function call.
				tmp = ptr->list;
				
				while(tmp) 
				{
					fprintf(Fp, "POP R0\t\t// Poping the parameters.\n");
					tmp = tmp->next;
				}
				
				fprintf(Fp, "POP BP\t\t// Restoring caller's BP.\n");

				for(t = 7; t >= 0; t--)
					fprintf(Fp, "POP R%d\n", t);
				t = regcount++;
				
				// Now, get the value returned by the function.
				fprintf(Fp, "POP R%d\t\t// Copying back the return value.\n", t); 
				return t;
				break;
		case FUNC_DEF:
				func_stptr = Glookup(ptr->name);
				
				/* 
				   'regcount' must be set to 0, since the new function's registers 
				    will not, otherwise, start with R0.
				*/
				regcount = 0;		
				
				fprintf(Fp, "F%d:\t\t// Function definition for '%s'\n",
						 func_stptr->binding, func_stptr->name);
				fprintf(Fp, "MOV BP SP\t// Moving current SP to BP\n");
				
				/* 
				   Computing the no: of local variables in the function.
				   (Since the parameters are also pushed as 'local' variables.)
				*/
				func_Lhead = Lhead;
				count = 0;
				while(func_Lhead)
				{
					count++;
					func_Lhead = func_Lhead->next;
				}
				// Now, count = no: of local variables + no: of parameters
				count = count - func_stptr->argcount;
				
				// Now, count = the no: of local variables
				t = count;
				// Pushing local variables.
				while(t)
				{
					fprintf(Fp, "PUSH R0\n");
					t--;
				}
				CodeGen(ptr->Lptr);
				CodeGen(ptr->Rptr);
				
				// Function definition is over. Hence pop the local variables.
				t = count;
				while(t)		// Poping the local variables.
				{
					fprintf(Fp, "POP R0\n");
					t--;
				}
				fprintf(Fp, "RET\n\n");
				break;
		case MAIN_CALL:
				fprintf(Fp, "START\n");	
				
				/* 
				   'regcount' must be set to 0, since the new function's registers 
				    will not, otherwise, start with R0.
				*/
				regcount = 0;			
				t_head = Ghead;
				while(t_head)
				{
					if(t_head->type != FUNC)
					{
						if(t_head->size == -1) // i.e, we have a global variable.
							fprintf(Fp, "PUSH R0\t// Pushing for global variable.\n");
						else		       // i.e, we have a global array.
						{
							for(t = 0; t < t_head->size; t++)
								fprintf(Fp, "PUSH R0\n");
						}
					}
					t_head = t_head->next;
				}
				fprintf(Fp, "MOV BP SP\t// Moving current SP to BP\n");
				
				LSymbolTable* head1 = Lhead;
				count = 0;
				while(head1)
				{
					count++;
					head1 = head1->next;
				}
				
				t = count;
				while(t)		// Pushing the local variables.
				{
					fprintf(Fp, "PUSH R0\n");
					t--;
				}
				CodeGen(ptr->Lptr);
				/*t = count;		Here, we need to pop local and global variables.
				while(t)		// Poping the local variables.
				{
					fprintf(Fp, "POP R0\n");
					t--;
				}*/
				fprintf(Fp, "HALT\n");
				break;				
		case RET:	
				t = CodeGen(ptr->Lptr);
				
				if(strcmp(function_name, "main") != 0)
				{
					func_stptr = Glookup(function_name);
					b = func_stptr->argcount + 10;
					
					t1 = regcount++;
					t2 = regcount++;
					
					fprintf(Fp, "MOV R%d BP\n", t1);
					fprintf(Fp, "MOV R%d %d\n", t2, b);
					fprintf(Fp, "SUB R%d R%d\n", t1, t2);

					regcount--;	// Since use of t2 is over.
					fprintf(Fp, "MOV [R%d] R%d\n", t1, t);
					regcount--;	// Since use of t1 is over.
					
				}
				regcount--;		// Since use of t is over.
				break;
				
		case EQUAL:		
				t = CodeGen(ptr->Rptr);
				if(ptr->Lptr->Lstptr)	// Lptr is a local variable
				{
					b = ptr->Lptr->Lstptr->binding;
					
					t1 = regcount++;
					t2 = regcount++;

					fprintf(Fp, "MOV R%d BP\t//\tMoving base pointer to a register.\n",t1);
					fprintf(Fp, "MOV R%d %d\t//\tMoving relative address of variable\n", t2, b);
					fprintf(Fp, "ADD R%d R%d\t//\tComputing absolute address...\n", t1, t2);
					fprintf(Fp, "MOV [R%d] R%d\t//\tAssigning register contents to variable\n",
							 t1, t);

					regcount--;
					regcount--;
				}
				else			// Lptr is a global variable
				{
					if(ptr->Lptr->NodeType == VARIABLE)
					{
						b = ptr->Lptr->Gstptr->binding;
						fprintf(Fp, "MOV [%d] R%d\t//\tMoving register contents to variable\n",
								b, t);
					}	
					else
					{
						// Done inorder to generate code to obtain array binding field.
						ArrFlag = 0;
						t1 = CodeGen(ptr->Lptr);
						ArrFlag = 1;
						fprintf(Fp, "MOV [R%d] R%d\t//\tAssigning register contents to array\n",
								 t1, t);
						regcount--;
					}
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
