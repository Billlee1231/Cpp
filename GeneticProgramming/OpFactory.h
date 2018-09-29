#ifndef OPFACTORY_H
#define OPFACTORY_H

#include <vector>
#include <cstdlib>
#include "Term.h"

class OpFactory {
	std::vector<Term *> operators;
public:
	OpFactory() {}
	OpFactory(std::vector<Term *> ops) {
		operators = ops;
	}
	Term * getOperator()const {
		int index = rand() % int(operators.size());
		return (Term *)(operators[index]->clone());
	}
	int getNumOps() { return int(operators.size()); }
};

#endif