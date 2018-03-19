/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.h
 * Author: yichu
 *
 * Created on March 18, 2018, 10:20 AM
 */

#ifndef POINT_H
#define POINT_H
class line;
class point{
	friend line;
	double x,y,z;
	public:
		point(){};
		point(double X, double Y, double Z):x(X),y(Y),z(Z){}; // constructor, using Member initializer list
		point(const point &); // copy constructor
		point midpoint(const point *); // find the mid-point between two points
};


#endif /* POINT_H */

