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

class Event {
public:
	Event();
	virtual ~Event();

private:
	std::vector<Associate *> event_request;
	std::vector<Associate *> event_organizers;
	std::string date;
	std::string local;
	std::string theme;
	float given_support;
	Association * association;

};

#endif /* EVENT_H_ */
