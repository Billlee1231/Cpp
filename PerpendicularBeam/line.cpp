/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "point.h"
# include "vector.h"
# include "line.h"
# include <math.h>
# include <cmath>   

extern const double tolerance;

line::line(const point & P1, const point & P2){
	p1	=	new point(P1); // using copy constructor, left side need a pointer variable because used "new"
	p2	=	new point(P2);
	dir.setDir(p1->x-p2->x, p1->y-p2->y, p1->z-p2->z);
}

line::line(const point & P, const vector & V){
	p1	=	new point(P);
	dir	=	V; // assignment using operator overloading
	p2	=	new point(P.x+V.i,P.y+V.j,P.z+V.k);
}

vector line::getDir() const{
	return dir;
}

point * line::crossPoint(const line & L) const{
	// check whether the two lines are on the same plane
	// first pick up two points from one line and one point from another line, use the three points to get two lines
	line tmpL1(*p1,*L.p1);
	line tmpL2(*p2,*L.p1);
        vector tmpL2Dir = tmpL2.getDir();
	vector tmpV = tmpL1.getDir().crossprod(&tmpL2Dir); // tmpL3 is supposed to perpendicular to the original two lines if they are on the same plane
	vector LDir = L.getDir();
        if (!tmpV.perpend(&LDir))
		return 0;
	// check whether two lines are parallel to each other
	if (dir==L.dir)
		return 0;		
	// if at the same plane and not parallel, then...
	double coef;
	if (std::abs(-dir.i*L.getDir().j+L.getDir().i*dir.j)>tolerance) // denominator not 0
		coef = (-L.getDir().j*(L.p1->x-p1->x)+L.getDir().i*(L.p1->y-p1->y))/(-dir.i*L.getDir().j+L.getDir().i*dir.j);
	else if (std::abs(-dir.i*L.getDir().k+L.getDir().i*dir.k)>tolerance)
		coef = (-L.getDir().k*(L.p1->x-p1->x)+L.getDir().i*(L.p1->z-p1->z))/(-dir.i*L.getDir().k+L.getDir().i*dir.k);
	else
		coef = (-L.getDir().j*(L.p1->z-p1->z)+L.getDir().k*(L.p1->y-p1->y))/(-dir.k*L.getDir().j+L.getDir().k*dir.j);
	point * inter = new point(dir.i*coef+p1->x,dir.j*coef+p1->y,dir.k*coef+p1->z);
	return inter;
}	