/*
 * Area.h
 */

#ifndef AREA_H_
#define AREA_H_

#include <string>
#include <vector>

class SubArea;


class Area {
public:

	//Constructors
	Area();
	Area(std::string name);
	Area(std::string file_string);


	//Destructors
	virtual ~Area();


	//Get Methods
	std::string getName() const;


	//SubArea
	void addSubarea(SubArea * newSub);

private:
	std::string name;
	std::vector <SubArea *> subareas;


};

#endif /* AREA_H_ */
