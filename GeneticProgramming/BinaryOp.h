
#ifndef BINARYOP_H
#define BINARYOP_H

#include <iostream>
#include "Term.h"

/*
BinaryOp is a subclass of Term.
BinaryOp is still an abstract class, since it hasn't defined the pure virtual
methods symbolicEval() and numericalEval().
Immediate (known) subclasses of BinaryOp are Plus, Minus, Mult and Divide.
*/
class BinaryOp : public Term {
public:
		// The default constructor simply sets child pointers to null.
	BinaryOp() : lChild(0), rChild(0) {}

		// Create a new BinaryOp node with known children.
	BinaryOp(Term * l, Term * r) {
		lChild = l;
		rChild = r;
	}

		// This virtual destructor is the key to cleaning up trees.
		// It calls destructors for the left and right children,
		// and these destructor calls recursively call destructors
		// for their children. In this way, an entire tree is cleaned up.
	virtual ~BinaryOp() {
		delete lChild;
		delete rChild;
	}

		// The only legal child positions for BinaryOp are 1 (left) and 2 (right).
		// Any other position fails, and crashes the program.
	void setChild(Term * t, int position) {
		if (position == 1)
			setLChild(t);
		else if (position == 2)
			setRChild(t);
		else {
			std::cerr << "Attempting to add a BinaryOp child "
				<< "to the illegal position" <<  position << std::endl;
			exit(1);
		}
	}

		// Set a BinaryOp's left child to the Term pointed to by l.
		// l may in fact be itself the root of a subtree.
	void setLChild(Term * l) { lChild = l; }

		// Set a BinaryOp's right child to the Term pointed to by r.
		// r may in fact be itself the root of a subtree.
	void setRChild(Term * r) { rChild = r; }

		// There isn't enough information for a BinaryOp to
		// clone itself (since it doesn't know exactly what kind of
		// BinaryOp it really is (Plus? Minus?...))
		// Subclasses will need to override this method.
	virtual Term * clone() = 0;

		// BinaryOps know how to determine their size, which equals
		// 1 + size of lChild + size of rChild.
	virtual int mySize() {
		int size = 1;
		size += lChild->mySize();
		size += rChild->mySize();
		return size;
	}

		// BinaryOp's version of this method does something useful:
		// If the current Term's depth isn't at maxDepth, 
		// add a left and right child, either an operator or a leaf. 
		// Then ask each new child to do the same, passing along
		// the new depth.
	void addRandomKids(OpFactory & o, LeafFactory & l, int maxDepth) { 
        int i;
        if (depth < maxDepth) {

			// for the left child:
            i = rand() % (o.getNumOps() + l.getNumIndepVars());
            if (i < l.getNumIndepVars()) {
                lChild = l.getLeaf();
                lChild->depth = depth + 1;
                lChild->addRandomKids(o, l, maxDepth);
            }
            else {
                lChild = o.getOperator();
                lChild->depth = depth + 1;
                lChild->addRandomKids(o, l, maxDepth);
            }

			// for the right child:
            i = rand() % (o.getNumOps() + l.getNumIndepVars());
            if (i < l.getNumIndepVars()) {
                rChild = l.getLeaf();
                rChild->depth = depth + 1;
                rChild->addRandomKids(o, l, maxDepth);
            }
            else {
                rChild = o.getOperator();
                rChild->depth = depth + 1;
                rChild->addRandomKids(o, l, maxDepth);
            }
        }

		// otherwise:
        else {
            lChild = l.getLeaf();
            lChild->depth = depth + 1;
            rChild = l.getLeaf();
            rChild->depth = depth + 1;
        }
	}


protected:
		// Each BinaryOp has exactly two children.
	Term * lChild, * rChild;
};

#endif