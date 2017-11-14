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


//Exception Classes

class NoSuchID{
private:
	int ID;
public:
	NoSuchID(int id) : ID(id) {};
	int getID() const {return this->ID;};
};




class Association {

public:

	//=========================================Constructors===================================================
	//========================================================================================================

	/**
	 * @brief Default Constructor
	 */
	Association();



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
	void setAnnualPay(int annualPay);



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
	int getAnnualPay() const;


	static int getCurrentYear();


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

private:
	std::string name; ///< The Association name
	long double fund;  ///< The Association initial fund to manage events,associates etc..
	int annualPay; ///< The annual pay given by each and every associate
	std::vector<Associate * > associates; ///< Vector of pointers to all the Associates from the Association
	std::vector<Area *> areas; ///< Vector of pointers to all the Scientific Areas from the Association
	static int currentYear; ///< The current year

};

#endif /* ASSOCIATION_H_ */
