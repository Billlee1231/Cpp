#ifndef DATAROW_H
#define DATAROW_H
#include <vector>

/* 
Holds a single row from the regression data set. A better version would hold
a map<double, vector<double> >
*/

class DataRow {
	double y;
	std::vector<double> x;

public:
	DataRow() {}
	DataRow(double d, std::vector<double> v) : y(d), x(v) {
}
	double getX(int i) { return x[i]; }
	std::vector<double> getX() { return x; }
	void push_back(double d) { x.push_back(d); }
	double getY() { return y; }
	void setY(double d) { y = d; }
	int getNumIndepVars() { return int(x.size()); }
	void erase() { x.erase(x.begin(), x.end()); }
};
#endif