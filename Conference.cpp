/*
 * Conference.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: jubas
 */

#include "Conference.h"
#include "Association.h"
#include "Associate.h"
using namespace std;

//Constructors
Conference::Conference() {
}

Conference::Conference(vector<Associate *> event_request,
		vector<Associate *> event_organizers, string date, string local,
		string theme, Association * association, int estimative) :
		Event(event_request, event_organizers, date, local, theme, association) {
	this->estimative = estimative;

	//The given support, in the conference type event, will not take in consideration more people than the organizers
	int counter = 0;

	int total = event_organizers.size();

	for (size_t t = 0; t < event_organizers.size(); t++) {

		if (event_organizers.at(t)->getStatus() == "normal") //the associate hasn't paid his payments in the last 5 years

			counter++;

	}

	float ratio = counter / (total * 1.0);

	if (ratio >= 2.0 / 3) //if two thirds or more of the organizers havent got their payments up to date, the association will not give payment

		throw NoSupportGiven(counter, total);

	else if (ratio >= 1.0 / 3) //will be given a monetary support of 10% the total association fund

		this->given_support = 0.10 * association->getFund();

	else if (ratio < 1.0 / 3 && ratio > 0)  //15 percent

		this->given_support = 0.15 * association->getFund();

	else

		//if everyone has his payments up to date,

		this->given_support = 0.20 * association->getFund();

}

//Destructors

Conference::~Conference() {
	// TODO Auto-generated destructor stub
}

//Get Methods

int Conference::getEstimative() const {

	return this->estimative;

}

long double Conference::getSupport() const{
	return this->given_support;
}


//General Methods

string Conference::showInfo() const{
	string info = "";

	info += "Conference Type Event: \n";

	//COMPLETAR COM O RESTO DA INFO

	return info;
}
