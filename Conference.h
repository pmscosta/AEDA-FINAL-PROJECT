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
	Conference();
	virtual ~Conference();
private:
	int trainers_estimative;
};

#endif /* SUPER_MEME_CONFERENCE_H_ */
