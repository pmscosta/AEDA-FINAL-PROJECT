/*
 * Conference.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: jubas
 */

#include "Conference.h"
#include "Association.h"

using namespace std;

//Constructors
Conference::Conference() {
}

Conference::Conference(vector<Associate *> event_request,
		vector<Associate *> event_organizers, string date, string local,
		string theme, Association * association, int estimative) :
		Event(event_request, event_organizers, date, local, theme, association) {
	this->trainers_estimative = estimative;

}

Conference::~Conference() {
	// TODO Auto-generated destructor stub
}

