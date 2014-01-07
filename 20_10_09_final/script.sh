clear
bison Exprtree.y
flex Exprtree.l

gcc -g lex.yy.c Exprtree.tab.c SymbTab.c AbsSynTree.c codegen.c -o Eval
./Eval inp x.sim

