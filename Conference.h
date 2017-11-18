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


	Conference(std::vector<Associate *> event_request,
				std::vector<Associate *> event_organizers, std::string date,
				std::string local, std::string theme, Association * association,
				int estimative, long double money);

	//=========================DESTRUCTORS================================

	//====================================================================

	virtual ~Conference();

	//=========================GET METHODS================================

	//====================================================================

	int getEstimative() const;

	std::string getType() const;

	long double getSupport() const;

	std::list<Trainer *> getTrainers() const;



	//=========================GENERAL METHODS================================

	//========================================================================

	std::string showInfo() const;



private:
	std::string type = "Conference";
	int estimative;
	long double given_support; ///< The value of the monetary support given by the association
};

#endif /* CONFERENCE_H_ */
