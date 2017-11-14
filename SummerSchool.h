/*
 * SummerSchool.h
 *
 *  Created on: Nov 14, 2017
 */

#ifndef SUMMERSCHOOL_H_
#define SUMMERSCHOOL_H_
#include <list>

#include "Event.h"

class Associate;

class SummerSchool: public Event {
public:

	//=========================CONSTRUCTORS===============================
	//====================================================================
	/*
	 * @brief Default Constructor
	 */
	SummerSchool();

	/*
	 * @brief Full SummerSchool Constructor
	 */
	SummerSchool(std::vector<Associate *> event_request,
				std::vector<Associate *> event_organizers, std::string date,
				std::string local, std::string theme, Association * association,
				std::list<Associate *> involved);
	virtual ~SummerSchool();
private:
	std::list<Associate *> persons_involved;
};

#endif /* SUMMERSCHOOL_H_ */
