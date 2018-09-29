#ifndef CONTAINER_H
#define CONTAINER_H
// Container is the parent class of House and Store
class Container{
protected:
	int numSeeds;
public:
	Container(); // default constructor
	void addSeed(int);
	int numseeds(); // return the numseeds of the container
	virtual void sowSeeds()=0; // virtual function
};
#endif