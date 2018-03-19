/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: yichu
 *
 * Created on March 13, 2018, 9:46 PM
 */

#include <cstdlib>
# include "point.h"
# include "vector.h"
# include "line.h"
# include <iostream>

using namespace std;

/*
 * 
 */
int main() {
	// input three points on the periphery of the circular plane on top of the tower
	point a(0,1,100);
	point b(1,0,100);
	point c(0,-1,100);
	// input two points on the beam, which will in turn gives the direction vector of the beam
	point beamP1(1,1,50), beamP2(2,2,49.999999999);

	// find the two mid-points of ab and bc
	point abM		=	a.midpoint(&b);
	point bcM		=	b.midpoint(&c);
	// find two lines go across the three points
	line abL(a, b);
	line bcL(b, c);
	// find the vector perpendicular to the plane
        vector bcLDir = bcL.getDir();
        vector abLDir = abL.getDir();
	vector perdV	=	abL.getDir().crossprod(&bcLDir);
	vector tmpV1	=	perdV.crossprod(&abLDir); // find the vector perpendicular to perdV and the abL
	line tmpL1(abM, tmpV1); // find the corresponding line with direction vector tmpV1 and go across mid-point of a, b
	vector tmpV2	=	perdV.crossprod(&bcLDir); // find the vector perpendicular to perdV and the bcL
	line tmpL2(bcM, tmpV2); // find the corresponding line with direction vector tmpV1 and go across mid-point of b, c
	// find the cross point of line tmpL1 and tmpL2, which is the centroid of the circular top plane
	point * center = tmpL1.crossPoint(tmpL2);
	// center axis of the tower
	line axis(*center, perdV);
	// find the line representing the beam
	line beamL(beamP1, beamP2);
	
	// check whether the beam is perpendicular to the axis
        vector axisDir = axis.getDir();
	bool perpResult = beamL.getDir().perpend(&axisDir);
	// check whether it has an intersection with the axis
	point *intersect = beamL.crossPoint(axis);
	
	if (intersect==0 || !perpResult)
		cout<<"Not perpendicular to the wall!"<<endl;
	else
		cout<<"Perpendicular to the wall!"<<endl;

	delete intersect;
	delete center;
        
        return 0;
}

