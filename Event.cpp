/*
 * Event.cpp
 *
 *  Created on: Nov 14, 2017
 */

#include "Event.h"
#include "Association.h"
#include "Associate.h"

using namespace std;

//Constructors

Event::Event() {
}

Event::Event(vector<Associate *> event_request,
		vector<Associate *> event_organizers, string date, string local,
		string theme, Association * association) {
	this->association = association;
	this->date = date;
	this->event_organizers = event_organizers;
	this->event_request = event_request;
	this->local = local;
	this->theme = theme;

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

Event::~Event() {
	// TODO Auto-generated destructor stub
}

//Get Methods

vector<Associate *> Event::getRequest() const {
	return this->event_request;
}

vector<Associate *> Event::getOrganizers() const {
	return this->event_organizers;
}

string Event::getDate() const {
	return this->date;
}

string Event::getLocal() const {
	return this->local;
}

string Event::getTheme() const {
	return this->theme;
}

long double Event::getSupport() const {
	return this->given_support;
}
