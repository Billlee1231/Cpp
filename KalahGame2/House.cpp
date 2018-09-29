# include <iostream>
# include "House.h"

House::House(int seeds){
	addSeed(seeds);
}

int House::sowSeeds(){
	if (numSeeds==0)
		std::cout<<"Cannot sow seeds in an empty house! Input another House number:"<<std::endl;
	return numSeeds;
}
