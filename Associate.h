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

	//Get Methods
	std::string getWorkName() const;
	int getUniqueID() const;
	std::string getStatus() const;
	std::vector<int> getPaidYears() const;
	int getPersonalWallet() const;

	//Set Methods
	void setInterestAreas(std::vector<Area *> interest);
	void setWork(SubArea* sub);
	void setStatus(std::string newStatus);
	void setPaidYears(std::vector<int> paid);
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
	std::string status;  //contributor, subscriber, normal
	std::vector<int> paidYears;
	SubArea * workingArea;
	int uniqueID;   ///< The unique Identifier
	static int id_provider;   ///< Will ensure that every instance of this class gets a unique identifier
};



#endif /* ASSOCIATE_H_ */
