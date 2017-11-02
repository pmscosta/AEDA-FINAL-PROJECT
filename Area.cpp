/*
 * Area.cpp
 *
 */

#include "Area.h"
#include "SubArea.h"
#include <sstream>

using namespace std;

Area::Area() {
	this->name = "";

}

Area::Area(string name) {
	this->name = name;
}

void Area::addSubarea(SubArea * newSub) {

	this->subareas.push_back(newSub);

}

Area::Area(string file_string) {

	istringstream input = file_string;

	string areaName, subAreaName, subAreaInitials;

	input >> areaName;

	areaName = areaName.substr(0, areaName.size() - 1);

	this->name = areaName;

	while (!input.eof()) {

		input >> subAreaName;
		subAreaName = subAreaName.substr(0, subAreaName.size() - 1);

		input >> subAreaInitials;
		if (!input.eof())
			subAreaInitials = subAreaInitials.substr(0,
					subAreaInitials.size() - 1);  //removing the comma only if it is not the last initials

		SubArea * subarea = new SubArea(subAreaName, subAreaInitials);

		this->addSubarea(subarea);
	}
}

Area::~Area() {
	// TODO Auto-generated destructor stub
}

//Get Methods

string Area::getName() const {
	return this->name;
}
