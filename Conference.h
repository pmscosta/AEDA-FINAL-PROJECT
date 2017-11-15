/*
 * Conference.h
 *
 *  Created on: Nov 14, 2017
 */

#ifndef CONFERENCE_H_
#define CONFERENCE_H_

#include "Event.h"

class Conference: public Event {
public:

	//=========================CONSTRUCTORS===============================
	//====================================================================
	/*
	 * @brief Default Constructor
	 */
	Conference();

	/*
	 * @brief Full Conference Constructor
	 *
	 */
	Conference(std::vector<Associate *> event_request,
			std::vector<Associate *> event_organizers, std::string date,
			std::string local, std::string theme, Association * association,
			int estimative);

	//=========================DESTRUCTORS================================

	//====================================================================

	virtual ~Conference();

	//=========================GET METHODS================================

	//====================================================================

	int getEstimative() const;

private:
	int estimative;
};

#endif /* CONFERENCE_H_ */
