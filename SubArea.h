/*
 * SubArea.h
 *
 */

#ifndef SUBAREA_H_
#define SUBAREA_H_



#include "Area.h"

class SubArea: public Area {
public:

	//Constructors
	SubArea();
	SubArea(std::string name, std::string initials);


	//Destructors
	virtual ~SubArea();


	//Get Methods
	/**
	 * @brief Returns the name of the SubArea
	 *
	 */
	std::string getName() const;

	std::string getInitials() const;



private:
	std::string name; ///< The SubArea's name
	std::string initials; ///< The SubArea's initials
};

#endif /* SUBAREA_H_ */
