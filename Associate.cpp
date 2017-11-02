/*
 * Associate.cpp
 */

#include "Associate.h"
#include "Area.h"
#include "SubArea.h"
#include "Association.h"

using namespace std;

int Associate::id_provider = 0;

//Constructors
Associate::Associate() : uniqueID(++id_provider), workingArea(nullptr) {}


//Destructors
Associate::~Associate() {
	// TODO Auto-generated destructor stub
}

//Get Methods
string Associate::getWorkName() const{
	return this->workingArea->getName();
}


int Associate::getUniqueID() const{
	return this->uniqueID;
}

string Associate::getStatus() const{
	return this->status;
}

vector<int> Associate::getPaidYears() const{
	return this->paidYears;
}

int Associate::getPersonalWallet() const{
	return this->personalWallet;
}

//Set Methods
void Associate::setWork(SubArea* sub){
	this->workingArea = sub;
}

void Associate::setInterestAreas(vector <Area *> interest){
	this->interestAreas = interest;
}

void Associate::setStatus(string newStatus) {
	this->status = newStatus;
}

void Associate::setPaidYears(vector<int> paid){
	this->paidYears = paid;
}

void Associate::setPersonallWallet(int money) {
	this->personalWallet = money;
}


//General Methods

void Associate::addToWallet(int more_money){
	this->personalWallet += more_money;
}

void Associate::payFromWallet(int less_money){
	this->personalWallet -= less_money;
}

void Associate::addPaidYear(int year){
	this->paidYears.push_back(year);
}


void Associate::payYear(int year){

	int lastYearPaid = this->paidYears.back();

	if (lastYearPaid < (Association::getCurrentYear() - 1))//if his payments are not up to date
		throw  NotUpToDate(year, this->uniqueID);
	else if (this->personalWallet < this->association->getAnnualPay())
		throw NotEnoughMoney(this->uniqueID);
	else{
		this->paidYears.push_back(Association::getCurrentYear());
		this->payFromWallet(this->association->getAnnualPay());
	}
}
