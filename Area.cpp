/*
 * Area.cpp
 *
 */

#include "Area.h"


using namespace std;



Area::Area() {
	this->name = "";

}

Area::Area(string name){
	this->name = name;
}

Area::~Area() {
	// TODO Auto-generated destructor stub
}



//Get Methods


string Area::getName() const{
	return this->name;
}
