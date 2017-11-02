/*
 * Area.h
 */

#ifndef AREA_H_
#define AREA_H_

#include <string>


class Area {
public:

	//Constructors
	Area();
	Area(std::string name);


	//Destructors
	virtual ~Area();


	//Get Methods
	std::string getName() const;

private:
	std::string name;

};

#endif /* AREA_H_ */
