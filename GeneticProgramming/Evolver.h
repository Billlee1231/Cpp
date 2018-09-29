// File:	Evolver.h
// Evolver class: generate new generation and display it
// Author: Yichu Li, Date: Dec/5/2013
// Email:  yichuli@tepper.cmu.edu

# ifndef EVOLVER_H
# define EVOLVER_H
# include"Generation.h"
# include"DataSet.h"

using namespace std;

class Evolver{
Generation	oldGen, newGen;
DataSet		dataset;
public:
	Evolver(const Generation &g, const DataSet &ds):dataset(ds)
	{
		oldGen=g;
		newGen=0;
	}
	~Evolver(){
		oldGen.erase();
		newGen.erase();
	}
	void makeNewGeneration(){
		// make new generation to be old generation
		if (newGen.getSize()>0) // new generation is not empty
			oldGen	=	newGen;
		newGen.erase();
		GPTree	t1,t2;
		// a "for" loop to randomly choose two trees to do crossover
		for (int i = 0; i < int(oldGen.getSize()/2); i++)
		{
			t1	=	oldGen.chooseTreeProportionalToFitness();
			t2	=	oldGen.chooseTreeProportionalToFitness();
			oldGen.crossover(t1, t2); // old generation crossover
			newGen.push_back(t1); // put new trees in new generation
			newGen.push_back(t2); // put new trees in new generation
		}
		newGen.evalAll(dataset);		
	}
	
	void displayBestNewTree(ostream & out){newGen.printBestTree(out);}
	
	void displayBestOldTree(ostream & out){oldGen.printBestTree(out);}
};
# endif