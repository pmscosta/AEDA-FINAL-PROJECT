/*
 * Mail.h
 *
 *  Created on: Nov 10, 2017
 *      Author: jubas
 */

#ifndef MAIL_H_
#define MAIL_H_

#include <string>

class Associate;

class Mail {
public:

	//Constructor
	Mail();
	Mail(Associate * associate, std::string title, std::string body);

	//Destructor
	virtual ~Mail();

	//Get Methods
	Associate * getAuthor() const;
	std::string getTitle() const;
	std::string getBody() const;

	//Set Methods
	void setAuthor(Associate *);
	void setTitle(std::string title);
	void setBody(std::string body);

private:
	Associate * author;
	std::string title;
	std::string body;
};

#endif /* MAIL_H_ */
