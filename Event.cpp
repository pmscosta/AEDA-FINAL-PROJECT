/*
 * Event.cpp
 *
 *  Created on: Nov 14, 2017
 */

#include "Event.h"
#include "Association.h"
#include "Associate.h"
#include <sstream>

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


Event::Event(Association * association, string file_string){

	/*
	 *Summer School/15-02-1998/Vila Real/Pirocas Piroclásticas/[Requester1/Requester2/Requester3/]/[Organizer4/Organizer5/]/5000/300
	 *Conference/15-02-1998/Vila Real/Pirocas Piroclásticas/[Requester1/Requester2/Requester3/]/[Organizer4/Organizer5/]/5000/[Zé/FEUP/Carlos/FCUP/]
	 *
	 *
	 *Summer School/Date/Local/Theme/[Requesters/]/[Organizers + Requesters/]/GivenSupport/NumeroParticipantes
	 *Conference/Date/Local/Theme/[Requesters/]/[Organizers + Requesters/]/GivenSupport/[Formador1/Instituicao1]
	 *
	 * */

	this->association = association;

	istringstream infoEvent(file_string);

	int type_flag;
	string type, date, local, theme;
	int requester, organizer, money;
	char garbage;

	int predicted_participants;
	string former_name, former_inst;

	getline(infoEvent, type, '/');

	if(type == "Summer School")
		type_flag = 0;
	else if(type == "Conference")
		type_flag = 1;


	getline(infoEvent, date, '/');
	this->date = date;

	getline(infoEvent, local, '/');
	this->local = local;

	getline(infoEvent, theme, '/');
	this->theme = theme;

	infoEvent >> garbage;

	while (infoEvent.peek() != ']') {

		infoEvent >> requester;

		for (size_t t = 0; t < this->association->getAssociates().size(); t++) {

			if (requester
					== this->association->getAssociates().at(t)->getUniqueID()) {
				this->event_request.push_back(
						this->association->getAssociates().at(t));
				this->event_organizers.push_back(
						this->association->getAssociates().at(t));
			}
		}
		infoEvent >> garbage;
	}

	infoEvent >> garbage;		// ']'
	infoEvent >> garbage;		// '/'
	infoEvent >> garbage;		// '['

	while (infoEvent.peek() != ']') {

		infoEvent >> organizer;

		for (size_t t = 0; t < this->association->getAssociates().size(); t++) {

			if (organizer == this->association->getAssociates().at(t)->getUniqueID()) {
				this->event_organizers.push_back(this->association->getAssociates().at(t));
			}
		}
		infoEvent >> garbage;
	}

	infoEvent >> garbage;		// ']'
	infoEvent >> garbage;		// '/'

	infoEvent >> money;
	this->given_support = money;

	infoEvent >> garbage;		// '/'

	if(type_flag == 0){
		infoEvent >> predicted_participants;
		//this-> participantes = predicted_participants
	}
	else if(type_flag == 1){

		infoEvent >> garbage;		// '['

		while(infoEvent.peek() != ']'){

			infoEvent >> former_name;
			infoEvent >> garbage;
			infoEvent >> former_inst;
			infoEvent >> garbage;
			//this-> nome do formador = former_name;
			//this-> instituicao do formador = former_inst;
		}
	}
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

