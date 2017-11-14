/*
 * Event.h
 *
 *  Created on: Nov 14, 2017
 */

#ifndef EVENT_H_
#define EVENT_H_
#include <vector>
#include <string>

class Associate;
class Association;


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
	Event(std::vector<Associate *> event_request, std::vector<Associate *> event_organizers, std::string date, std::string local, std::string theme, Association * association);


	//=========================DESTRUCTORS===============================
	//====================================================================
	virtual ~Event();

	//=========================SET METHODS===============================
	//====================================================================


	//=========================GET METHODS===============================
	//====================================================================

private:
	std::vector<Associate *> event_request;
	std::vector<Associate *> event_organizers;
	std::string date;
	std::string local;
	std::string theme;
	long double given_support;
	Association * association;

};

#endif /* EVENT_H_ */
