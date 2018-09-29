#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Term.h"
#include "OpFactory.h"
#include "Constant.h"
#include "Variable.h"
#include "LeafFactory.h"
#include "BinaryOp.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Divide.h"
#include "GPTree.h"
#include "Generation.h"
#include "DataRow.h"
#include "DataSet.h"
//#include "Evolver.h"
using namespace std;

void main() {
	srand((unsigned int)time(NULL));

	vector<Term *> ops; 
	ops.push_back(new Plus());
	ops.push_back(new Minus());
	ops.push_back(new Mult());
	ops.push_back(new Divide());
	OpFactory opFac(ops);
	DataSet ds("data2.dat");
	cout << "Our data set is" << endl << endl;
	ds.print(cout);
	LeafFactory leafFac(ds.getNumIndepVars());

	int maxDepth = 4;
	int numGenerations = 10;
	int generationSize = 500;
	Generation g(generationSize, opFac, leafFac, maxDepth);

	g.evalAll(ds);
	g.printBestTree(cout);
	cout << endl;
	char c;
	cout << "enter a char to end: ";
	cin >>c;
/*
	Evolver e(g, ds);
	cout << "This is Evolver's old generation's best tree " << endl;
	e.displayBestOldTree(cout);
	cout << endl << endl;
	for (int i = 0; i < numGenerations; i++) {
		e.makeNewGeneration();
		cout << "This is Evolver's new generation's best tree " << endl;
		e.displayBestNewTree(cout);
		cout << endl << endl;
	}
	*/
}
