/*
 * Associate.cpp
 */

#include "Associate.h"
#include "Area.h"
#include "SubArea.h"
#include "Association.h"
#include <sstream>
#include <iostream>
using namespace std;

int Associate::id_provider = 0;

//Constructors
Associate::Associate() :
		uniqueID(++id_provider) {
}

Associate::Associate(Association * asso, string name, string institution,
		vector<Area *> interests) :
		uniqueID(++id_provider) {
	this->association = asso;
	this->name = name;
	this->institution = institution;
	this->interestAreas = interests;
	this->personalWallet = 500.0;  //DEFAULT FOR EVERY ASSOCIATE
	this->divulgations = 0;
}

Associate::Associate(Association * association, string file_string) {

	/*
	 * ID/Name/Instituion/[Interest Areas]/Wallet/[Years Paid]/Divulgations
	 *
	 * */

	this->association = association;

	istringstream infoAssociate(file_string);

	string name, institution, interest;
	int id, years, divulgation;
	float wallet;
	char garbage;

	infoAssociate >> id;

	this->uniqueID = id;

	infoAssociate >> garbage;

	getline(infoAssociate, name, '/');

	this->name = name;

	getline(infoAssociate, institution, '/');

	this->institution = institution;

	infoAssociate >> garbage;


	while (infoAssociate.peek() != ']') {


		getline(infoAssociate, interest, '/');

		for (size_t t = 0; t < this->association->getAreas().size(); t++) {

			if (interest == this->association->getAreas().at(t)->getName())
				this->interestAreas.push_back(
						this->association->getAreas().at(t));

		}

	}


	infoAssociate >> garbage;

	infoAssociate >> garbage;

	infoAssociate >> wallet;

	this->personalWallet = wallet;

	infoAssociate >> garbage;

	infoAssociate >> garbage;


	while (infoAssociate.peek() != ']') {
		infoAssociate >> years;
		this->paidYears.push_back(years);
		infoAssociate >> garbage;

	}


	infoAssociate >> garbage;

	infoAssociate >> divulgation;

	this->divulgations = divulgation;

	this->status = "contributor";

}

//Destructors
Associate::~Associate() {
	// TODO Auto-generated destructor stub
}

//Get Methods

string Associate::getName() const {
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

string Associate::showInfo() const{

	string info = "";

	info += "Associado nº " + to_string(this->uniqueID) + ":\n"
			+ "\t -Nome: " + this->name + ";\n" +
			"\t -Instituicao: " + this->institution + ";\n"
			+ "\t -Status: " + this->status + ";\n" +
			"\t -Wallet: " + to_string(this->personalWallet) + ";\n" +
			"\t -Divulgations: " + to_string(this->divulgations) + ";\n" +
			"\t -Interest Areas: ";

	for (size_t t = 0; t < this->interestAreas.size(); t++) {

		if (t == (this->interestAreas.size() - 1)){
			info += this->interestAreas.at(t)->getName() + ";";
			break;
		}
		info += this->interestAreas.at(t)->getName() + "/ ";

	}

	info += "\n\t -Paid Years: ";

	for (size_t t = 0; t < this->paidYears.size(); t++) {

		if (t == (this->paidYears.size() - 1)){
			info += to_string(this->paidYears.at(t)) + ";";
			break;
		}
		info += to_string(this->paidYears.at(t)) + ", ";
	}

	info += "\n";

	return info;
}

