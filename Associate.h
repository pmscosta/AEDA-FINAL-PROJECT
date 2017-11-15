/*
 * Associate.h
 *
 */

#ifndef ASSOCIATE_H_
#define ASSOCIATE_H_

#include <vector>
#include <string>

class Area;
class SubArea;
class Association;

class NotUpToDate {
private:
	int uniqueID;
	int triedYear;
	int lastPaid;

public:
	NotUpToDate(int triedYear, int uniqueID, int lastPaid) :
			triedYear(triedYear), uniqueID(uniqueID), lastPaid(lastPaid) {
	}
	;

	int getID() const {
		return this->uniqueID;
	}

	int getYear() const {
		return this->triedYear;
	}

	int getLast() const {
		return this->lastPaid;
	}
};

class NotEnoughMoney {
private:
	int uniqueID;

public:
	NotEnoughMoney(int uniqueID) :
			uniqueID(uniqueID) {
	}
	;

	int getID() const {
		return this->uniqueID;
	}

};

class Associate {

public:

	//=============================================Constructors================================================

	//=========================================================================================================

	/**
	 * @brief Default Associate Constructor
	 *
	 */
	Associate();
	/**
	 * @brief Full Associate Constructor
	 *
	 * The uniqueID is given automatically and incrementally.
	 * Every associate has a predefined 500 personal Wallet start.
	 *
	 */
	Associate(Association * asso, std::string name, std::string institution,
			std::vector<Area*> interests);

	/*
	 * @brief
	 *
	 */

	Associate(Association * association, std::string file_string);
	//=============================================Destructors================================================

	//========================================================================================================

	virtual ~Associate();

	//=============================================Get Methods================================================

	//========================================================================================================

	/**
	 * @brief Returns the name of the Associate
	 *
	 */

	std::string getName() const;

	/**
	 * @brief Returns the uniqueID of the Associate
	 *
	 */
	int getUniqueID() const;

	/**
	 * @brief Returns a string containing the status of the Associate
	 *
	 *  E.g, "contributor", "normal"
	 *
	 */
	std::string getStatus() const;

	/**
	 * @brief Returns a vector containing all the years the Associate has paid
	 *
	 */
	std::vector<int> getPaidYears() const;

	/**
	 * @brief Returns the amount of money the Associate has (in float)
	 *
	 */
	float getPersonalWallet() const;

	//=============================================Set Methods================================================

	//========================================================================================================

	/**
	 * @brief Sets/Changes the vector containing the interest areas of an associate
	 *
	 * @param interest - vector of pointers to areas
	 */
	void setInterestAreas(std::vector<Area *> interest);

	/**
	 * @brief Sets/Changes the string representing the current status of an associate
	 *
	 * The possible status are "normal", "subscriber", "normal".
	 *
	 * @param newStatus - String with the new status
	 */
	void setStatus(std::string newStatus);

	/**
	 * @brief Sets/Changes the vector containing the years that the associate has paid
	 *
	 * @param paid - a vector of ints representing the years
	 */
	void setPaidYears(std::vector<int> paid);

	/**
	 * @brief Sets/Changes the amount of money the associate has paid
	 *
	 * @param money - the new amount of money (float)
	 */
	void setPersonallWallet(float money);

	//=============================================General Methods================================================

	//============================================================================================================

	/**
	 * @brief Adds a certain amount to the associate wallet
	 *
	 * @param more_money - the amount to be added
	 */
	void addToWallet(float more_money);

	/**
	 * @brief Subtracts a certain amount from the associate wallet
	 *
	 * @param less_money - the amount to be subtracted
	 */
	void payFromWallet(float less_money);

	/**
	 * @brief Adds a year to the vector containing all the paid years
	 *
	 * Applicable after doing a yearly payment
	 *
	 * @param year - the year paid
	 */
	void addPaidYear(int year);

	/**
	 * @brief Effectuates the payment of a year
	 *
	 * Checks if the associate has enough money to do such payment
	 * and if the associate has all the years before paid up to date.
	 * If it has no money, throws the correspondent exception (NotEnoughMoney).
	 * If his payments are not up to date, throws the exception NotUpToDate.
	 *
	 * @param year - the year to be paid
	 */
	void payYear(int year);

	/**
	 * @brief Update the string representing the status of the associate
	 *
	 * Checks with the static variable of the Association Current Year to see
	 * if the associate has the payments up to date (with the 5 years delay)
	 * and updates the string to its correspondent value.
	 *
	 */
	void updateStatus();

	/**
	 *
	 * @brief Increments the number of divulgations to the network by the associate.
	 * Occurs every time a new Mail is sent.
	 */

	void incDivulgations();

	/**
	 * @brief Determines if the associate has access to see the contents of the network.
	 * Return true if so, false otherwise;
	 */

	bool accessNetwork();

	/*
	 * @brief Determines if the associate can share a Mail in the network.
	 * Return true if so, false otherwise.
	 */

	bool shareNetwork();


	/*
	 * @brief Returns a string containing all the info of a Associate, in readable and user-friendly format
	 */
	std::string showInfo() const;


	//=============================================Operators================================================

	//=======================================================================================================

	/*
	 * @brief Overloading  < operator
	 */

	bool operator< (const Associate & lhs) const;

private:
	Association * association; ///< The connection between the associate and the association
	std::string name;  ///< The associate's name
	float personalWallet;  ///< The amount of money the associate has
	std::string institution; ///< The institution to which the associate is connected
	std::vector<Area *> interestAreas; ///< A vector containing pointers to all the Associate interest areas
	std::string status; ///< contributor, subscriber, normal, the possible status
	std::vector<int> paidYears; ///< A vector of integers containing all the year the Associate has paid
	int uniqueID;   ///< The unique Identifier
	static int id_provider; ///< Will ensure that every instance of this class gets a unique identifier
	int divulgations; ///< The number of divulgations to the network

};

#endif /* ASSOCIATE_H_ */
