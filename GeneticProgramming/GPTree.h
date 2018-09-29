#ifndef GPTREE_H
#define GPTREE_H

#include "Term.h"
#include "DataSet.h"
#include <cmath>

/*
GPTree is just a wrapper class for a pointer to the
root of a tree, the Term * called root. For convenience,
it also holds the fitness of the tree for the current data set.
*/

class GPTree {
	Term * root;
	double fitness;
public:
    GPTree() { root = 0; fitness = -1; }

		// This constructor is used to generate a random tree.
    GPTree(OpFactory & o, LeafFactory & t, int maxDepth) {
        root = o.getOperator();
        root->addRandomKids(o, t, maxDepth);
		fitness = -1;
    }

		// This copy constructor is used when GPTrees are
		// pushed into vectors of GPTrees.
	GPTree(const GPTree & g) {
		fitness = g.fitness;
		root = (g.root)->duplicate();
	}

		// Here is where the importance of 
		// virtual destructors is demonstrated.
	~GPTree() { delete root; }

		// The duplicate() method is used to make a deep copy.
	GPTree & operator=(const GPTree & g) {
		fitness = g.fitness;
		if (root != 0)
			delete root;
		root = (g.root)->duplicate();
		return *this;
	}

	int mySize() { return root->mySize(); }
	double getFitness() { return fitness; }
    std::string symbolicEval() { return root->symbolicEval(); }

    double numericalEval(std::vector<double> data) {
		return (root->numericalEval(data));
	}
	double numericalEval(DataSet & ds) {
		double eval;
		double sumOfSquareDeviation = 0;
		for (int i = 0; i < ds.getNumRows(); i++) {
			eval = numericalEval(ds.getRow(i).getX());
			sumOfSquareDeviation += pow(eval - ds.getRow(i).getY(), 2);
		}
		fitness = 1/sumOfSquareDeviation;
		return fitness;
	}

		// This may be an anachronism?
	bool operator<(const GPTree & rhs) { return fitness < rhs.fitness; }

};

#endif
