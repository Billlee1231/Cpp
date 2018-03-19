/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

# include "vector.h"
# include <math.h>
# include <cmath>

vector::vector(const vector & v){
	i=v.i;
	j=v.j;
	k=v.k;
}

void vector::setDir(double I, double J, double K){
	i=I;
	j=J;
	k=K;
}

vector vector::crossprod(const vector * v) const{ // cross product
	vector result;
	result.i = j*v->k-k*v->j;
	result.j = k*v->i-i*v->k;
	result.k = i*v->j-j*v->i;
	return result;
}

double vector::dotprod(const vector * v) const{
	double result = i*v->i+j*v->j+k*v->k;
	return result;
}

bool vector::perpend(const vector * v) const{
	double dotProd = dotprod(v);
	return std::abs(dotProd-0)<tolerance;
}

// *this is a dereferenced pointer
// if didn't specify return a reference, like in this case (vector &), then will return a copy of vector
const vector & vector::operator=(const vector & v){
	i = v.i;
	j = v.j;
	k = v.k;

	return *this;
}

double vector::norm() const{
	return pow(pow(i,2.0)+pow(j,2.0)+pow(k,2.0),0.5);
}

bool operator==(const vector & v1, const vector & v2){
	bool result1, result2, result;
	if ( std::abs(v1.norm()-0)>tolerance && std::abs(v2.norm()-0)>tolerance) // both not zero
	{
		// same direction?
		result1 = std::abs(v1.i/v1.norm()-v2.i/v2.norm())<tolerance && std::abs(v1.j/v1.norm()-v2.j/v2.norm())<tolerance && std::abs(v1.k/v1.norm()-v2.k/v2.norm())<tolerance;
		// opposite direction?
		result2 = std::abs(v1.i/v1.norm()+v2.i/v2.norm())<tolerance && std::abs(v1.j/v1.norm()+v2.j/v2.norm())<tolerance && std::abs(v1.k/v1.norm()+v2.k/v2.norm())<tolerance;
		result = result1 || result2;
	}
	else
		result = 0;
	return result;
}