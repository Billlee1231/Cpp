#ifndef HOUSE_H
#define HOUSE_H

# include "Container.h"

class House:public Container{
public:
	House(int);
	virtual int sowSeeds();
};
# endif