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
class VirtualTableMetadata;
namespace std {

class VirtualTable {
protected:
	 string name;
	 vector<VirtColum> colums;//holding the meta data about the virtTable;
	 vector<vector<char*> > row;//holding the rows;

	vector<string> tags;

public:
	void setName(string name);
	string getName();
	int getInt();
	void addTag(string tag);
	vector<string> getTags();
	vector<VirtColum> getColumns();
	VirtualTableMetadata* getMetadata();
	long long int getRowCount();
	// Get row or rows by the given criterion.If no result was found will
	// return empty vector.
	 /*!
	  *\param criterion - the criterion to which the rows will be compared.
	  *\The key in the map is the column to which will be compared the block
	  *\and the key of the map.
	  */
	vector<vector<char*> > getRow(map<string, string> criterion);
	short getColumCount();
	// Adding row to the table.
	 /*!
	  *\param row -  the row to be added if there is at least one row in the table.
	  *\the block in the column with autoIncrement will be replaced with the previous
	  *\value incremented with one.If the block in the column which have isNull  is null('\0')
	  *\an exception will be thrown.
	  */
	void addRow(vector<char*> row);
	// Constructor for the virtTable
	 /*!
	  * \param columns - the meta data of the current table.Can be with size zero but there is not
	  * \point in this.
	  */

	VirtualTable(vector<VirtColum> columns ,string name = "",vector<string> tags = {});
	virtual ~VirtualTable();
};

} /* namespace std */

#endif /* VIRTUALTABLE_H_ */
