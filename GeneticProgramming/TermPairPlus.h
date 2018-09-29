#ifndef TERMPAIRPLUS_H
#define TERMPAIRPLUS_H

#include "Term.h"
class Term;

class TermPairPlus {
public:
	Term * parent;
	Term * child;
	int counter;
	TermPairPlus() : parent(0), child(0), counter(0) {}
};

#endif
