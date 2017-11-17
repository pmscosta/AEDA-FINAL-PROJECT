/*
 * Association.h
 *
 */

#ifndef ASSOCIATION_H_
#define ASSOCIATION_H_

#include <vector>
#include <string>

class Associate;
class Area;
class Event;

//Exception Classes

class NoSuchID {
private:
	int ID;
public:
	NoSuchID(int id) :
			ID(id) {
	}
	;
	int getID() const {
		return this->ID;
	}
	;
};

class Association {

public:

	//=========================================Constructors===================================================
	//========================================================================================================

	/**
	 * @brief Default Constructor
	 */
	Association();

	/*
	 * @brief Association Constructor
	 *
	 * @param file - a string from a file containing all the info in the following order:
	 *  Name/ Fund/ annualPay/ CurrentYear
	 *
	 *  It's vector will be later on initialized
	 */
	Association(std::string file);

	//=========================================Destructors====================================================
	//========================================================================================================
	/**
	 * @brief Default Destructor
	 */
	virtual ~Association();

	//===================================Set Methods==========================================================
	//========================================================================================================

	/**
	 * @brief Sets/Changes the name of the association
	 *
	 *
	 * @param name
	 */
	void setName(std::string name);

	/**
	 * @brief Sets/Changes the mainFund of the association
	 *
	 * @param fund - double type parameter
	 */
	void setFund(long double fund);

	/**
	 * @briefs Sets/Changes the annual pay for every associate
	 *
	 * @param annualPay - int value
	 */
	void setAnnualPay(float annualPay);

	void setEvents(std::vector<Event *> all_events);

	//=============================================Get Methods================================================
	//========================================================================================================
	/**
	 * @brief Returns the name of the association
	 */
	std::string getName() const;

	/**
	 * @brief Returns the value of the monetary fund of the association
	 */
	long double getFund() const;

	/**
	 * @brief Returns the value of the annual pay for every associate
	 */
	float getAnnualPay() const;

	static int getCurrentYear();

	std::vector<Event *> getEvents() const;

	/**
	 * @brief Returns the vector containing pointers to all the associates
	 */
	std::vector<Associate *> getAssociates() const;

	//===============================Associate Type Functions=================================================
	//========================================================================================================

	/**
	 * @brief Adds a new Associate to the association
	 *
	 * @param newAsso - it's a Associate *, given the nature of the vector, a way to save space
	 */
	void addAssociate(Associate * newAsso);

	/**
	 * @brief Removes a Associate from the association (does not delete it, since it can exist out of the Association scope)
	 *
	 * If the uniqueID is not attributed to one associate,
	 * throws a exception (NoSuchID);
	 * @param uniqueID
	 */
	void removeAssociate(int uniqueID);

	/**
	 * @brief Updates the status from all associates to prevent ignoring new changes made to them
	 */
	void updateAllAssociates();

	/*
	 * @brief Returns a pointer to an Associate with a certain ID
	 *
	 * Throws an exception, NoSuchID, if no Associate has that ID
	 *
	 * @param ID - an integer representing the uniqueID of each Associate
	 */
	Associate * getAssoById(int uniqueID);

	//============================Association Type Functions==================================================
	//========================================================================================================

	/**
	 * @brief Adds the money received from the annual payments to the Association fund
	 *
	 * @param income - money received from the annual payments
	 */
	void addToFund(float income);

	/**
	 * @brief Updates the current year
	 */
	void updateYear();

	/**
	 * @brief Makes the annual payment of every associate automatically
	 */
	std::string updatePayment();

	/**
	 * @brief Returns a string containing all the information about every associate in a readable
	 * and user-friendly way.
	 *
	 */
	std::string showAllAssociates();

	//============================Area Type Functions=========================================================
	//========================================================================================================

	/**
	 * @brief Returns the vector containing pointers to all the areas
	 */
	std::vector<Area *> getAreas() const;

	/**
	 * @brief Adds a new Area to the association
	 *
	 * @param newArea - Area pointer of the new Area to be added
	 */
	void addArea(Area * newArea);


	/**
	 * @brief Returns a string containing info about all the areas
	 *
	 */
	std::string showAreas() const;

	//============================Event Type Functions==================================================
	//========================================================================================================

	void addEvent(Event * newEvent);

	std::string showEvents() const;

	void removeEvent(std::string date);




private:
	std::string name; ///< The Association name
	long double fund; ///< The Association initial fund to manage events,associates etc..
	float annualPay; ///< The annual pay given by each and every associate
	std::vector<Associate *> associates; ///< Vector of pointers to all the Associates from the Association
	std::vector<Area *> areas; ///< Vector of pointers to all the Scientific Areas from the Association
	std::vector<Event *> events; ///< Vector of pointers to all the events done by the Associates
	static int currentYear; ///< The current year

};

#endif /* ASSOCIATION_H_ */
