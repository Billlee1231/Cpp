# include "House.h"

//using namespace std;

House::House(int seeds){
	addSeed(seeds);
}

void House::sowSeeds(){
	if (numSeeds==0)
		cout<<"Cannot sow seeds in an empty house!"<<endl;
	else
		numSeeds=0;
}

/*
Container * House::sowSeed(){
	if (numSeeds>0)
	{
		int tmp = 1;
		Container * curC=this;
		while (numSeeds>0)
		{
			curC = curC->nextC;
			curC->addSeed(tmp);
			numSeeds--;
		}
		return curC;
	} else
	{
		cout<<"There's no seed in the current house! Choose another house!"<<endl;
		return 0;
	}
}*/