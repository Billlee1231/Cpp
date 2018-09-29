#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Term.h"


class Variable : public Term {
	int index;
public:
	Variable() : index(0) {}
	Variable(int i) : index(i) {}
	virtual Term * duplicate() { return new Variable(index); }
	virtual std::string symbolicEval() {
		std::ostringstream oss;
		oss << "x" << index;
		return oss.str();
	}
	virtual double numericalEval(std::vector<double> data) {
		return data[index];
	}
	Term * clone() {
		return (Term *) new Variable();
	}
	void setChild(Term *, int position) {
		std::cerr << "Adding a child to Variable is an error" << std::endl;
		exit(1);
	}
	void addRandomKids(OpFactory & of, LeafFactory & lf, int maxDepth) {}

};

#endif