#ifndef LEAFFACTORY_H
#define LEAFFACTORY_H

#include "Term.h"
/*
Produce Variables or Constants in equal proportions
*/

class LeafFactory {
	int numVariables;
public:
	LeafFactory(int numVars) : numVariables(numVars) {}
	Term * getLeaf() {
		Term * leaf;
		int i = rand() % (numVariables + 1);
		if (i < numVariables)
			leaf = new Variable(i);
		else
			leaf = new Constant();
		return leaf;
	}
	int getNumIndepVars() { return numVariables; }
};

#endif