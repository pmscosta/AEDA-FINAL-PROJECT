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
	SummerSchool();
	virtual ~SummerSchool();
private:
	std::list<Associate *> persons_involved;
};

#endif /* SUMMERSCHOOL_H_ */
