clear
bison -d Exprtree.y
flex Exprtree.l

cc -g lex.yy.c Exprtree.tab.c SymbTab.c AbsSynTree.c codegen.c -o Eval
./Eval inp x.sim



