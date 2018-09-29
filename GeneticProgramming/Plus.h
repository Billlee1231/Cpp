#ifndef PLUS_H
#define PLUS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Term.h"

/*
Plus is a subclass of BinaryOp.
Plus knows how to perform duplicate(), symbolicEval(),
numericalEval(), and clone().
Immediate (known) subclasses of Plus: none.
*/
class Plus : public BinaryOp {
public:
	Plus() : BinaryOp() {}
	Plus(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Plus() {}
	virtual Term * duplicate() {
		Plus * t = new Plus();
		t->lChild = lChild->duplicate();
		t->rChild = rChild->duplicate();
		return t;
	}

	virtual std::string symbolicEval() {
		std::ostringstream oss;
		oss << "(" << lChild->symbolicEval();
		oss << " + ";
		oss << rChild->symbolicEval() << ")";
		return oss.str();
	}
	virtual double numericalEval(std::vector<double> data) {
		return (lChild->numericalEval(data) 
			  + rChild->numericalEval(data));
	}
	virtual Term * clone() {
		return (Term *) new Plus();
	}
};

#endif