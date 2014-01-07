#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT		100
#define BOOL		101
#define VOID		102

#define SEQ		110
#define RD		111
#define WE		112
#define IF_THEN		113
#define IF_THEN_ELSE	114
#define DO_WHILE	115

#define EQUAL		120
#define PLUS		121
#define MINUS		122
#define MUL		123
#define DIV		124

#define LT		130
#define GT		131
#define NE		132
#define LTE		133
#define GTE		134
#define ISEQUAL		135

#define CONST		140
#define VARIABLE	141
#define ARRAY		142

#define AND		143
#define OR		144
#define NOT		145
#define TRUE		146
#define FALSE		147

#define MAXLEN		30

/*
 * Stores the line no: of the currently executed line during 
 * abstract syntax tree generation.
 */
int 	Lineno;


/*
 * Keeps count of the binding values allocated to variables. 
 */
int	Count;


/*
 * Stores the label value for branching constructs.
 */
int	Label;


FILE* 	Fp;
int 	Array[500];

#endif
