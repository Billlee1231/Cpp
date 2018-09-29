#ifndef MINUS_H
#define MINUS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Term.h"

/*
Minus is a subclass of BinaryOp.
Minus knows how to perform duplicate(), symbolicEval(),
numericalEval(), and clone().
Immediate (known) subclasses of Minus: none.
*/
class Minus : public BinaryOp {
public:
	Minus() : BinaryOp() {}
	Minus(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Minus() {}
	virtual Term * duplicate() {
		Minus * t = new Minus();
		t->lChild = lChild->duplicate();
		t->rChild = rChild->duplicate();
		return t;
	}
	virtual std::string symbolicEval() {
		std::ostringstream oss;
		oss << "(" << lChild->symbolicEval();
		oss << " - ";
		oss << rChild->symbolicEval() << ")";
		return oss.str();
	}
	virtual double numericalEval(std::vector<double> data) {
		return (lChild->numericalEval(data) 
			  - rChild->numericalEval(data));
	}
	virtual Term * clone() {
		return (Term *) new Minus();
	}
};

#endif