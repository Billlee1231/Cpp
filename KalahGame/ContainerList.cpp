# include "ContainerList.h"

containerList::containerList(){
	beginN		=	0;
	endN		=	0;
	numNodes	=	0;
}

int containerList::size(){
	return numNodes;
}

void containerList::push_back(node * newN){
	if (numNodes!=0) // already have sth
	{
		endN->next(newN);
		endN = newN;
		numNodes++;
	}
	else // don't have anything
	{
		beginN = newN;
		endN = newN;
		numNodes++;
	}
}

node * containerList::begin(){
	return beginN;
}

node * containerList::end(){
	return endN;
}
