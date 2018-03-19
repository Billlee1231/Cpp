/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "point.h"

point::point(const point & p){ // copy constructor
	x=p.x;
	y=p.y;
	z=p.z;
}

point point::midpoint(const point * pP){ // find the mid-point between two points
	point p((pP->x+x)/2,(pP->y+y)/2,(pP->z+z)/2);
	return p;
}