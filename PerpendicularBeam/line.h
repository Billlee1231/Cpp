/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   line.h
 * Author: yichu
 *
 * Created on March 13, 2018, 9:56 PM
 */

#ifndef LINE_H
#define LINE_H

class line{
	point * p1, * p2;
	vector dir;
	public:
		line(){}; // default constructor
		line(const point &, const point &); // constructor, need two points to get a line
		line(const point &, const vector &); // constructor, need one point and a vector to get a line	
		vector getDir() const; // get direction of the line
		point * crossPoint(const line &) const; // return the intersection of two lines, in case there's no intersection, return null
};

#endif /* LINE_H */

