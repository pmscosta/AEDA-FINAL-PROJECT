/*
 * Event.h
 *
 *  Created on: Nov 14, 2017
 */

#ifndef EVENT_H_
#define EVENT_H_
#include <vector>
#include <string>
#include <list>

class Associate;
class Association;
class Trainer;

//! The NoSupportGiven

/*!

 * NoSupportGiven is a class which instances are called when

 * the main Association decides to not support financially an event.

 * Its useful in throwing exceptions, outside of that it has no real use implementation.

 */

class NoSupportGiven {

private:
	int late; ///< The number of associates whose payments where not up to date, thus creating the decision to not give support
	int total; ///< The total number of associates involved in the event
public:

	/*
	 * @brief Default Construction
	 */
	NoSupportGiven(int late, int total) :

			late(late), total(total) {
	}
	;

	/*
	 * @brief Returns the number of associates whose payments where not up to date.
	 *
	 */

	int getLate() const {
		return this->late;
	}
	/*
	 * @brief Returns the total number of associates involved in the event
	 *
	 */
	int getTotal() const {

		return this->total;
	}
};

//!  The Super Event Class
/*!
 An Event must be requested by at least 3 Associates.
 The given monetary support given by the association is determined randomly,
 taking in consideration the association main fund.
 In this case, we chose to give it a value between 5-15% of the total Fund;
 This given monetary support will be later used to calculate the total number
 of organizers (then selected randomly between all the associates) and trainers.
 */
class Event {
public:

	//=========================CONSTRUCTORS===============================
	//====================================================================

	/*
	 * @brief Default Constructor
	 *
	 */
	Event();

	/*
	 * @brief Full Event Constructor
	 * The given support by the association will be any value between 5-15% of the association main fund.
	 *
	 */

	Event(std::vector<Associate *> event_request,
			std::vector<Associate *> event_organizers, std::string date,
			std::string local, std::string theme, Association * association);

	//Event(Association * association, std::string string_file);

	//=========================DESTRUCTORS===============================
	//====================================================================
	virtual ~Event();

	//=========================SET METHODS===============================
	//====================================================================

	//=========================GET METHODS===============================
	//====================================================================

	/*
	 * Returns the associates that gave the initial request to the event
	 *
	 */

	std::vector<Associate *> getRequest() const;

	/*
	 * Returns all the associates that are involved in the event
	 *
	 */

	std::vector<Associate *> getOrganizers() const;

	/*
	 * Returns the Date of the event
	 *
	 */
	std::string getDate() const;

	/*
	 * Returns the Local of the event
	 *
	 */
	std::string getLocal() const;

	/*
	 * Returns the Theme of the event
	 *
	 */
	std::string getTheme() const;


	/*
	 * Returns the value of the monetary support
	 * given by the association to the e event
	 */
	virtual long double getSupport() const = 0;


	virtual std::string getType() const = 0;

	virtual std::list<Trainer *> getTrainers() const = 0;

	virtual int getEstimative() const = 0;


	virtual std::string showInfo() const = 0;


protected:
	std::vector<Associate *> event_request; ///< The Associates that gave the initial request
	std::vector<Associate *> event_organizers; ///< All the associates involved with the event
	std::string date; ///< The event's date
	std::string local; ///< The event's local
	std::string theme; ///< The event's theme
	Association * association; ///< The connection to the Association

};

#endif /* EVENT_H_ */
