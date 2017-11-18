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

class Trainer{
public:
	Trainer(std::string name, std::string institution) : name(name), institution(institution){};
	~Trainer();
	std::string getName() const {return this->name;};
	std::string getInstitution() const {return this->institution;};

private:
	std::string name;
	std::string institution;
};

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
			std::list<Trainer *> trainers);


	SummerSchool(std::vector<Associate *> event_request,
				std::vector<Associate *> event_organizers, std::string date,
				std::string local, std::string theme, Association * association,
				std::list<Trainer *> trainers, long double given_support);

	//=========================DESTRUCTORS================================

	//====================================================================

	virtual ~SummerSchool();



	//=========================GET METHODS================================

	//====================================================================

	long double getSupport() const;

	std::string getType() const;

	std::list<Trainer *> getTrainers() const;

	int getEstimative() const;


	//=========================GENERAL METHODS============================

	//====================================================================

	std::string showInfo() const;

private:
	std::string type = "SummerSchool";
	std::list<Trainer *> trainers;
	long double given_support; ///< The value of the monetary support given by the association
};

#endif /* SUMMERSCHOOL_H_ */
