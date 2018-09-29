#ifndef HOUSE_H
#define HOUSE_H

# include "Container.h"

class House:public Container{
int idH;
House * oppoH;
public:
	House(int);
	virtual void sowSeeds();
};
# endif