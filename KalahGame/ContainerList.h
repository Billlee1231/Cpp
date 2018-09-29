# ifndef CONTAINERLIST_H
# define CONTAINERLIST_H

# include "Node.h"

class containerList{
	node * beginN;
	node * endN;
	int numNodes;
public:
	containerList();
	void push_back(node *); // constructor
	int size();
	node * begin(); // return the beginN
	node * end(); // return the endN
};

# endif