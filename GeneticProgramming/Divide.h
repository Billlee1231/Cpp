#ifndef DIVIDE_H
#define DIVIDE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include "Term.h"

/*
Divide is a subclass of BinaryOp.
Divide knows how to perform duplicate(), symbolicEval(),
numericalEval(), and clone().
Immediate (known) subclasses of Divide: none.
*/
class Divide : public BinaryOp {
public:
	Divide() : BinaryOp() {}
	Divide(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Divide() {}
	virtual Term * duplicate() {
		Divide * t = new Divide();
		t->lChild = lChild->duplicate();
		t->rChild = rChild->duplicate();
		return t;
	}
	virtual std::string symbolicEval() {
		std::ostringstream oss;
		oss << "(" << lChild->symbolicEval();
		oss << " / ";
		oss << rChild->symbolicEval() << ")";
		return oss.str();
	}
	virtual double numericalEval(std::vector<double> data) {
		double denom = rChild->numericalEval(data);
		if (fabs(denom) < 0.0001)
			return 1.0;
		else
			return (lChild->numericalEval(data) / denom);
	}
	virtual Term * clone() {
		return (Term *) new Divide();
	}
};

#endif