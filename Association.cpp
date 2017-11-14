/*
 * Association.cpp
 *
 */
#include "Association.h"
#include "Associate.h"
#include <algorithm>

using namespace std;

int Association::currentYear = 0;

Association::Association() {
}

Association::Association(string name) : name(name) {};

Association::~Association() {
	// TODO Auto-generated destructor stub
}

//Set Methods

void Association::setName(string name) {
	this->name = name;
}

void Association::setFund(long double fund) {
	this->fund = fund;
}

void Association::setAnnualPay(int annualPay) {
	this->annualPay = annualPay;
}

//Get Methods

string Association::getName() const {
	return this->name;
}

long double Association::getFund() const {
	return this->fund;
}

int Association::getAnnualPay() const {
	return this->annualPay;
}

int Association::getCurrentYear() {
	return Association::currentYear;
}

vector<Associate *> Association::getAssociates() const{
	return associates;
}

//Associate Type Functions

void Association::addAssociate(Associate * newAsso) {
	this->associates.push_back(newAsso);
}

void Association::removeAssociate(int uniqueID) {

	//invoking a lambda function
	auto it = find_if(this->associates.begin(), this->associates.end(),
			[uniqueID](Associate * obj)
			{	return obj->getUniqueID() == uniqueID;});

	if (it != this->associates.end())
		this->associates.erase(it);
	else
		throw NoSuchID(uniqueID);

}

void Association::updateAllAssociates() {
	for (size_t t = 0; t < this->associates.size(); t++) {

		this->associates.at(t)->updateStatus();

	}
}

Associate * Association::getAssoById(int uniqueID)  {

	//invoking a lambda function
	auto it = find_if(this->associates.begin(), this->associates.end(),
			[uniqueID](Associate * obj)
			{	return obj->getUniqueID() == uniqueID;});

	if (it != this->associates.end())
		return (*it);
	else
		throw NoSuchID(uniqueID);

}

//Association Type Functions

void Association::updateYear() {
	Association::currentYear++;
}

void Association::addToFund(float income) {
	this->fund += income;
}



//Area Type Functions


vector<Area*> Association::getAreas() const{
	return this->areas;
}

void Association::addArea(Area * newArea){
	this->areas.push_back(newArea);
}
