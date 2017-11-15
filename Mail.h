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

	/**
	 * @brief Default Constructor
	 */
	Mail();

	/**
	 * @brief Creates a new mail from the associate with a title and a body
	 *
	 * @param associate - The Associate who sent the email
	 * @param title - string with the mail name
	 * @param body - string with all the mail body text
	 */
	Mail(Associate * associate, std::string title, std::string body);

	//Destructor

	/**
	 * @brief Default Destructor
	 */
	virtual ~Mail();

	//Get Methods

	/**
	 * @brief Returns the author from the mail
	 */
	Associate * getAuthor() const;

	/**
	 * @brief Returns the mail title
	 */
	std::string getTitle() const;

	/**
	 * @brief Returns the mail body
	 */
	std::string getBody() const;

	//Set Methods

	/**
	 * @brief Sets/Changes the author from a mail
	 *
	 * @param author - Associate who wrote the mail
	 */
	void setAuthor(Associate * author);

	/**
	 * @brief Sets/Changes the title from a mail
	 *
	 * @param title - The title of the mail
	 */
	void setTitle(std::string title);

	/**
	 * @brief Sets/Changes the body from a mail
	 *
	 * @param body - The body of the mail
	 */
	void setBody(std::string body);

private:
	Associate * author; ///< The mail author
	std::string title; ///< The mail title
	std::string body; ///< The mail body
};

#endif /* MAIL_H_ */
