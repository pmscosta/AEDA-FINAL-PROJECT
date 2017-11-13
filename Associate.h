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


class NotUpToDate{
private:
	int uniqueID;
	int triedYear;

public:
	NotUpToDate(int triedYear, int uniqueID) : triedYear(triedYear), uniqueID(uniqueID) {};
};

class NotEnoughMoney{
private:
	int uniqueID;

public:
	NotEnoughMoney(int uniqueID) : uniqueID(uniqueID) {};
};



class Associate {

public:

	//constructors
	Associate();

	//destructors
	virtual ~Associate();

	//**************************************************************************//

	//Get Methods

	/**
	 * @brief Returns the name of the sub-area where this associate works
	 *
	 */
	std::string getWorkName() const;

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


	//**************************************************************************//

	//Set Methods

	/**
	 * @briefs Sets/Changes the vector containing the interest areas of an associate
	 *
	 * @param interest - vector of pointers to areas
	 */
	void setInterestAreas(std::vector<Area *> interest);

	/**
	 * @briefs Sets/Changes the sub-area/working area of an associate
	 *
	 * @param sub - SubArea pointer
	 */
	void setWork(SubArea* sub);

	/**
	 * @briefs Sets/Changes the string representing the current status of an associate
	 *
	 * The possible status are "normal", "subscriber", "normal".
	 *
	 * @param newStatus - String with the new status
	 */
	void setStatus(std::string newStatus);

	/**
	 * @briefs Sets/Changes the vector containing the years that the associate has paid
	 *
	 * @param paid - a vector of ints representing the years
	 */
	void setPaidYears(std::vector<int> paid);

	/**
	 * @briefs Sets/Changes the
	 *
	 * @param annualPay - int value
	 */
	void setPersonallWallet(int money);

	//General Methods
	void addToWallet(int more_money);
	void payFromWallet(int less_money);
	void addPaidYear(int year);
	void payYear(int year);
	void updateStatus();




private:
	Association * association;
	std::string name;
	float personalWallet;
	std::string institution;
	std::vector<Area *> interestAreas;
	std::string status;  ///< contributor, subscriber, normal, the possible status
	std::vector<int> paidYears;
	SubArea * workingArea;
	int uniqueID;   ///< The unique Identifier
	static int id_provider;   ///< Will ensure that every instance of this class gets a unique identifier
};



#endif /* ASSOCIATE_H_ */
