#ifndef GENERATION_H
#define GENERATION_H

#include <iostream>
#include <algorithm>
#include "GPTree.h"

class Generation {
		// GPTrees are held by value, so be sure
		// that they are erased when done with a Generation
	std::vector<GPTree> trees;
	double sumOfFitnessValues;
	int indexOfFittestTree;
public:
		// this constructor is used to randomly
		// create the zeroeth Generation
	Generation(int n, OpFactory o, LeafFactory l, int mDepth) {
			// reserve the necessary space, for efficiency
		trees.reserve(n);
		for (int i = 0; i < n; i++) {
			trees.push_back(GPTree(o, l, mDepth));
		}
		sumOfFitnessValues = 0.0;
	}

	Generation(int n) {trees.reserve(n); }
	Generation() {}

		// Copy constructor; this insists that operator=
		// is properly defined for GPTree
	Generation (const Generation & g) {
		trees = g.trees;
		sumOfFitnessValues = g.sumOfFitnessValues;
	}
	const Generation & operator=(const Generation & rhs) {
		trees = rhs.trees;
		sumOfFitnessValues = rhs.sumOfFitnessValues;
		indexOfFittestTree = rhs.indexOfFittestTree;
		return *this;
	}

		//This is called after crossover to
		// prevent memory leaks
	void erase() {
		trees.erase(trees.begin(), trees.end());
		sumOfFitnessValues = 0.0;
	}
	void reserve(int i) { trees.reserve(i); }
	GPTree operator[](int i) {
		return trees[i];
	}
	void push_back(GPTree  t) { trees.push_back(t); }
	void display() {	// replace with copy
		std::vector<GPTree>::iterator i;
		for (i = trees.begin(); i != trees.end(); i++)
			std::cout << (*i).getFitness() << " = " << (*i).symbolicEval() << std::endl;
	}
	void displayFitnesses() {
		for (int i = 0; i < int(trees.size()); i ++)
			std::cout << i << ": " << trees[i].getFitness() << std::endl;
		std::cout << "The sum of fitness values is " << sumOfFitnessValues << std::endl;
	}
		// This seems never to be used; just as well...
	void sort() { std::sort(trees.begin(), trees.end()); }

	void evalAll(DataSet & ds) {
		indexOfFittestTree = 0;
		sumOfFitnessValues = 0.0;
		double currentFitness = 0, bestFitness = 0;
		for (int i = 0; i < int(trees.size()); i++) {
			currentFitness = trees[i].numericalEval(ds);
			if (currentFitness < 0.0)
				std::cout << "Error: negative fitness value" << std::endl;
			sumOfFitnessValues += currentFitness;
			if (currentFitness > bestFitness) {
				bestFitness = currentFitness;
				indexOfFittestTree = i;
			}
		}
	}

	int getSize() { return int(trees.size()); }

	void printBestTree(std::ostream & out) {
		out << trees[indexOfFittestTree].getFitness() 
			<< " = " 
			<< trees[indexOfFittestTree].symbolicEval();
	}
};

#endif

