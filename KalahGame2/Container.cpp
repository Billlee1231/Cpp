# include "Container.h"

Container::Container(){
	numSeeds = 0;
}

void Container::addSeed(int addN){
	numSeeds += addN;
}

int Container::numseeds(){
	return numSeeds;
}