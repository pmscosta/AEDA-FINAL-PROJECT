/*
 * Network.h
 *
 *  Created on: Nov 10, 2017
 *      Author: jubas
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include <vector>


class Mail;

class Network {
public:

	//Constructors
	Network();
	Network(std::vector<Mail *> mails);

	//Destructors
	virtual ~Network();

	//Set Methods
	/**
	 * @brief Sets/Changes the vector containing the mails the network has in it
	 *
	 * @param mails - vector of pointers to mails
	 */
	void setMails(std::vector<Mail *> mails);

	//Get Methods

	/**
	 * @brief Returns, in a vector, all the mails the network has in it
	 *
	 */
	std::vector<Mail *> getMails() const;

	//General

	void addMail(Mail * newMail);

private:
	std::vector<Mail *> mails; ///< A vector of mails containing all the mails the network has in it
};

#endif /* NETWORK_H_ */
