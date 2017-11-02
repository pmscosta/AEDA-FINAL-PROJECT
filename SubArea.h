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


	//Destructors
	virtual ~SubArea();


	//Get Methods
	std::string getName() const;



private:
	std::string name;
};

#endif /* SUBAREA_H_ */
