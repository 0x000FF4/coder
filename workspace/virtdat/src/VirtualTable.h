/*
 * VirtualTable.h
 *
 *  Created on: 20.02.2015 г.
 *      Author: x000ff4
 */

#ifndef VIRTUALTABLE_H_
#define VIRTUALTABLE_H_

#include <vector>
#include <map>
#include <algorithm>
#include "VirtColum.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
namespace std {

class VirtualTable {
	//holding the meta data about the virtTable;
	vector<VirtColum> colums;
	//holding the rows;
	vector<vector<char*> > row;
	friend class boost::serialization::access;

	template<typename Archive>
	void serialize(Archive& ar, const unsigned version) {
		ar & colums & row; // Simply serialize the data members of Obj
	}
public:
	long long int getRowCount();
	vector<vector<char*> > getRow(map<string, string> criterion);
	short getColumCount();
	void addRow(vector<char*> row);
	VirtualTable();
	virtual ~VirtualTable();
};

} /* namespace std */

#endif /* VIRTUALTABLE_H_ */
