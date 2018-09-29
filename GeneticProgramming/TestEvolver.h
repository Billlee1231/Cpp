// File:	TestEvolver.h
// TestEvolver class: test Evolver class
// Author: Yichu Li, Date: Dec/5/2013
// Email:  yichuli@tepper.cmu.edu

# include <string>
# include "OpFactory.h"
# include "LeafFactory.h"
# include "Evolver.h"

class TestEvolver{
	DataSet ds;
	Generation g;
public:
	TestEvolver(OpFactory & opFac, LeafFactory & leafFac, string filename):ds(filename),g(500, opFac, leafFac, 4){}
	void testEvolver (){		
		g.evalAll(ds);
		
		// test the Evolver thing
		Evolver e(g, ds);
		cout << "This is Evolver's old generation's best tree " << endl;
		e.displayBestOldTree(cout);
		cout << endl << endl;
	
		for (int i = 0; i < 5; i++) {
			e.makeNewGeneration();
			cout << "This is Evolver's "<<i<<"th generation's best tree:" << endl;
			e.displayBestNewTree(cout);
			cout << endl << endl;
		}
	}
};