# include "Node.h"

node::node(Container * newC){
	cP = newC;
}

void node::next(node * newN){
	nextN = newN;
}

node * node::sowSeeds(){
	int tmpInt	=	cP->numseeds();
	node * curN	=	this;
	cP->sowSeeds();
	while(tmpInt>0)
	{
		curN = curN->nextN;
		curN->cP->addSeed(1);
		tmpInt--;
	}
	return curN;
}

int node::numSeeds(){
	return cP->numseeds();
}