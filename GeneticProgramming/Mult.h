#ifndef MULT_H
#define MULT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Term.h"

/*
Mult is a subclass of BinaryOp.
Mult knows how to perform duplicate(), symbolicEval(),
numericalEval(), and clone().
Immediate (known) subclasses of Mult: none.
*/
class Mult : public BinaryOp {
public:
	Mult() : BinaryOp() {}
	Mult(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Mult() {}
	virtual Term * duplicate() {
		Mult * t = new Mult();
		t->lChild = lChild->duplicate();
		t->rChild = rChild->duplicate();
		return t;
	}
	virtual std::string symbolicEval() {
		std::ostringstream oss;
		oss << "(" << lChild->symbolicEval();
		oss << " * ";
		oss << rChild->symbolicEval() << ")";
		return oss.str();
	}
	virtual double numericalEval(std::vector<double> data) {
		return (lChild->numericalEval(data) 
			  * rChild->numericalEval(data));
	}
	virtual Term * clone() {
		return (Term *) new Mult();
	}
};

#endif