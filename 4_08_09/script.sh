bison expressiontree.y
flex expressiontree.l
cc lex.yy.c expressiontree.tab.c AbsSynTree.c -o prog
./prog
