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

#define MAXLEN		30

int 	lineno;
int	count;
FILE* fp;

#endif
