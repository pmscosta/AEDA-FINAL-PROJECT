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
	std::string getName() const;



private:
	std::string name;
	std::string initials;
};

#endif /* SUBAREA_H_ */
