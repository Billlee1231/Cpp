#ifndef DATASET_H
#define DATASET_H
#include "DataRow.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
/*
Holds a vector of DataRows, and provides access to them
*/

class DataSet {
	std::vector<DataRow> dataRows;
	int numIndepVars;
	int numDataRows;
public:
	DataSet(std::string filename) {
		std::ifstream in(filename.c_str());
		in >> numIndepVars;
		in >> numDataRows;
		DataRow temp;
		double d;
		for (int i = 0; i < numDataRows; i++) {
			in >> d;
			temp.setY(d);
			for (int j = 0; j < numIndepVars; j++) {
				in >> d;
				temp.push_back(d);
			}
			push_back(temp);
			temp.erase();
		}
		in.close();
	}
	DataSet(const DataSet & d) {
		//std::cout << "DataSet's copy constructor called" << std::endl;
		dataRows = d.dataRows;
		numIndepVars = d.numIndepVars;
		numDataRows = d.numDataRows;
	}

	void push_back(DataRow d) { dataRows.push_back(d); }
	DataRow getRow(int i) { return dataRows[i]; }
	int getNumRows() { return numDataRows; }
	int getNumIndepVars() { return numIndepVars; }
	void print(std::ostream & out) {
		for (int i = 0; i < int(dataRows.size()); i++) {
			out << dataRows[i].getY() << '\t';
			for (int j = 0; j < dataRows[i].getNumIndepVars(); j++)
				out << dataRows[i].getX(j) << '\t';
			out << std::endl;
		}
	}

};
#endif