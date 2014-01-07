#!/bin/bash

bison calcu.y
flex calcu.l
cc -lm lex.yy.c calcu.tab.c -o program
./program
