bison -d postfix.y
flex postfix.l
clear
cc lex.yy.c postfix.tab.c -o prog
./prog
