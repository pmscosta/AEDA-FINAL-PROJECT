/*
 * SummerSchool.h
 *
 *  Created on: Nov 14, 2017
 */

#ifndef SUMMERSCHOOL_H_
#define SUMMERSCHOOL_H_
#include <list>
#include <string>
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
			std::list<std::string> trainers);

	//=========================DESTRUCTORS================================

	//====================================================================

	virtual ~SummerSchool();



	//=========================GET METHODS================================

	//====================================================================

	long double getSupport() const;



	//=========================GENERAL METHODS============================

	//====================================================================

	std::string showInfo() const;

private:
	std::list<std::string> trainers;
	long double given_support; ///< The value of the monetary support given by the association
};

#endif /* SUMMERSCHOOL_H_ */
