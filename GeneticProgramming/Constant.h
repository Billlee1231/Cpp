#ifndef CONSTANT_H
#define CONSTANT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Term.h"


/*
Const is a subclass of Term.
Const knows how to perform duplicate(), symbolicEval(),
numericalEval(), and clone().
Immediate (known) subclasses of BinaryOp: none.
*/
class Constant : public Term {
	double value;
public:

		// Constant's default constructor produces a value in [0, 1).
	Constant() { value = double(rand()) / double(RAND_MAX); }
	Constant(double v) { value = v; }

		// This virtual destructor doesn't need to do anything,
		// since Constant is a leaf node.
	virtual ~Constant() {}

		// This duplicate() method is simple, since Constant is a leaf node.
	virtual Term * duplicate() { return new Constant(value); }

		// Return a string holding the decimal representation of value.
	virtual std::string symbolicEval() {
		std::ostringstream oss;
		oss << value;
		return oss.str();
	}

		// Return the double held by this Constant.
	virtual double numericalEval(std::vector<double> data) {
		return value;
	}

		// Return a new Constant object with a random value.
	Term * clone() {
		return (Term *) new Constant();
	}
	void setChild(Term * t, int position) {
		std::cerr << "Adding a child to Constant is an error" << std::endl;
		exit(1);
	}
	void addRandomKids(OpFactory & of, LeafFactory & lf, int maxDepth) {}

};

#endif