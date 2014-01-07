#include "AbsSynTree.h"

int main()
{
	NODPTR a = MakeLeaf(SEQ,NULL);
	NODPTR b = MakeLeaf(RD,NULL);
	NODPTR c = MakeLeaf(SEQ,NULL);
	ConnectNodes(a,b,c);
	Print(a);
	return 0;
}
