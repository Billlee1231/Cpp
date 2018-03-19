/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.h
 * Author: yichu
 *
 * Created on March 13, 2018, 9:56 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

const double tolerance = 0.000001;

class line;

class vector{
	friend line;
	double i,j,k;
	public:
		//vector(double I, double J, double K):i(I),j(J),k(K){}; // constructor
		vector(){}; // default constructor
		vector(const vector &);// copy constructor
		void setDir(double, double, double);// set direction
		double dotprod(const vector *) const; // dot product
		vector crossprod(const vector * v1) const; // cross product
		bool perpend(const vector *) const; // verify whether it's perpendicular to another vector or not 
		double norm() const; // norm
		const vector & operator=(const vector &); // = operator overloading
		//global operator function, friend it because it needs to access private member of vector class
                friend bool operator==(const vector &, const vector &); // == operator overloading, check whether they are parallel
};

#endif /* VECTOR_H */

