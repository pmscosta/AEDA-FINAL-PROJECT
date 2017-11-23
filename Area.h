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

	/*
	 * @brief Default Constructor
	 */
	Area();

	/*
	 * @brief File Constructor
	 * Reads a line from a file and creates the area and its subareas based on that information
	 */
	Area(std::string file_string);

	//Destructors
	virtual ~Area();

	//Get Methods

	/**
	 * @brief Returns the name of the Area
	 *
	 */
	std::string getName() const;


	/*
	 * @brief Returns the subareas of the Area
	 */

	std::vector<SubArea *> getSubAreas() const;

	//SubArea

	/**
	 * @brief Adds a SubArea to the vector containing all the SubAreas of the Area
	 *
	 * @param newSub - The SubArea that is supposed to add to the vector
	 */
	void addSubarea(SubArea * newSub);


private:
	std::string name; ///< The Area's name
	std::vector<SubArea *> subareas; ///< The Area's SubAreas

};

#endif /* AREA_H_ */
