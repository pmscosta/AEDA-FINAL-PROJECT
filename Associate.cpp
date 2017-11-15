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
Associate::Associate() :
		uniqueID(++id_provider) {
}

Associate::Associate(Association * asso, string name, string institution, vector<Area *> interests) : uniqueID(++id_provider){
	this->association = asso;
	this->name = name;
	this->institution = institution;
	this->interestAreas = interests;
	this->personalWallet = 500.0;  //DEFAULT FOR EVERY ASSOCIATE
	this->divulgations = 0;
}

//Destructors
Associate::~Associate() {
	// TODO Auto-generated destructor stub
}

//Get Methods

string Associate::getName() const{
	return name;
}

int Associate::getUniqueID() const {
	return this->uniqueID;
}

string Associate::getStatus() const {
	return this->status;
}

vector<int> Associate::getPaidYears() const {
	return this->paidYears;
}

float Associate::getPersonalWallet() const {
	return this->personalWallet;
}

//Set Methods

void Associate::setInterestAreas(vector<Area *> interest) {
	this->interestAreas = interest;
}

void Associate::setStatus(string newStatus) {
	this->status = newStatus;
}

void Associate::setPaidYears(vector<int> paid) {
	this->paidYears = paid;
}

void Associate::setPersonallWallet(float money) {
	this->personalWallet = money;
}

//General Methods

void Associate::addToWallet(float more_money) {
	this->personalWallet += more_money;
}

void Associate::payFromWallet(float less_money) {
	this->personalWallet -= less_money;
}

void Associate::addPaidYear(int year) {
	this->paidYears.push_back(year);
}

void Associate::payYear(int year) {

	int lastYearPaid = this->paidYears.back();

	if (lastYearPaid < (Association::getCurrentYear() - 1)

	      && year > (lastYearPaid + 1)) //if his payments are not up to date, he has to strictly pay the year after the last one paid

	    throw NotUpToDate(year, this->uniqueID, lastYearPaid);

	else if (this->personalWallet < this->association->getAnnualPay())
		throw NotEnoughMoney(this->uniqueID);
	else {
		 this->addPaidYear(year);

		    this->payFromWallet(this->association->getAnnualPay()); //Makes the payment from the associate wallet

		    this->association->addToFund(this->association->getAnnualPay()); //Adds the payment to the fund

	}
}

void Associate::updateStatus() {

	int lastYearPaid = this->paidYears.back();

	if (lastYearPaid >= Association::getCurrentYear() - 1) //if the last year he paid is the current last year or if he paid ahead
		this->status = "contributor";
	else if (lastYearPaid > (Association::getCurrentYear() - 5))
		this->status = "subscriber";
	else
		this->status = "normal";
}

void Associate::incDivulgations() {

  this->divulgations++;

}



bool Associate::accessNetwork() {

  return !(this->status == "normal"); //can always see except when its a normal associate

}



bool Associate::shareNetwork() {

  return this->status == "contributor"; //can only share if it is a contributor

}

