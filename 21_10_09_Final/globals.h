#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT		100
#define BOOL		101
#define VOID		102
#define MAIN_CALL	103

#define SEQ		110
#define RD		111
#define WE		112
#define IF_THEN		113
#define IF_THEN_ELSE	114
#define DO_WHILE	115
#define FUNC		116
#define RET		117
#define FUNC_DEF	118

#define EQUAL		120
#define PLUS		121
#define MINUS		122
#define MUL		123
#define DIV		124
#define MOD		125

#define LT		130
#define GT		131
#define NE		132
#define LTE		133
#define GTE		134
#define ISEQUAL		135
#define PARAM		136
#define L_VAR		137

#define CONST		140
#define VARIABLE	141
#define ARRAY		142

#define AND		143
#define OR		144
#define NOT		145
#define TRUE		146
#define FALSE		147

#define MAXLEN		30
#define MSGLEN		60

/*
 * Stores the line no: of the currently executed line during 
 * abstract syntax tree generation.
 */
int 	Lineno;


/*
 * Keeps count of the binding values allocated to variables. 
 */
int	GCount;			// For associating binding count in static area (for global variables)
int	LCount;			// For associating binding count in stack area
int	L_arg_count;		// For associating binding count of arguments


/*
 * Stores the label value for branching constructs.
 */
int	Branching_Label;

/*
 * Stores the label value for functions.
 */

int	Function_Label;

char function_name[MAXLEN];

FILE* 	Fp;
int 	Array[500];

#endif
