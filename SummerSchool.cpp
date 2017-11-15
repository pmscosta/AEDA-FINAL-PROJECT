/*
 * SummerSchool.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: jubas
 */

#include "SummerSchool.h"
#include "Association.h"

using namespace std;

SummerSchool::SummerSchool() {
	// TODO Auto-generated constructor stub

}

SummerSchool::SummerSchool(vector<Associate *> event_request,
		vector<Associate *> event_organizers, string date, string local,
		string theme, Association * association, list<Associate *> involved) :
		Event(event_request, event_organizers, date, local, theme, association) {
	this->persons_involved = involved;

}

SummerSchool::~SummerSchool() {
	// TODO Auto-generated destructor stub
}

