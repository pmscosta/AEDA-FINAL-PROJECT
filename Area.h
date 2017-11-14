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
	Area(std::string file_string);


	//Destructors
	virtual ~Area();


	//Get Methods

	/**
	 * @brief Returns the name of the Area
	 *
	 */
	virtual std::string getName() const;
	std::vector<SubArea *> getSubAreas() const;

	//SubArea

	/**
	 * @briefs Adds a SubArea to the vector containing all the SubAreas of the Area
	 *
	 * @param newSub - The SubArea that is supposed to add to the vector
	 */
	void addSubarea(SubArea * newSub);

private:
	std::string name; ///< The Area's name
	std::vector <SubArea *> subareas; ///< The Area's SubAreas


};

#endif /* AREA_H_ */
