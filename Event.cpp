/*
 * Event.cpp
 *
 *  Created on: Nov 14, 2017
 */

#include "Event.h"
#include "Association.h"

using namespace std;

Event::Event() {
}

Event::Event(vector<Associate *> event_request, vector<Associate *> event_organizers, string date, string local, string theme, Association * association){
	this->association = association;
	this->date = date;
	this->event_organizers = event_organizers;
	this->event_request = event_request;
	this->local = local;
	this->theme = theme;
	this->given_support = ( (rand() % 11) + 5) / 10.0 * association->getFund();
}

Event::~Event() {
	// TODO Auto-generated destructor stub
}

