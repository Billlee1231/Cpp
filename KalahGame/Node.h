#ifndef NODE_H
#define NODE_H

# include "Container.h"

class node{
	Container * cP;
	node * nextN;
public:
	node(Container *);
	void next(node *);
	node * sowSeeds(); // return the pointer to last container being sowed
	int numSeeds(); // return the number of seeds in the container of the node
};
# endif