/*
 * Conference.h
 *
 *  Created on: Nov 14, 2017
 *      Author: jubas
 */

#ifndef SUPER_MEME_CONFERENCE_H_
#define SUPER_MEME_CONFERENCE_H_

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
	virtual ~Conference();
private:
	int trainers_estimative;
};

#endif /* SUPER_MEME_CONFERENCE_H_ */
