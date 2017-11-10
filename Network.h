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
	Network(std::vector<Mail> mails);

	virtual ~Network();


	//Set Methods
	void setMails(std::vector<Mail> mails);


	//Get Methods

	std::vector<Mail> getMails() const;



private:
	std::vector<Mail> mails;
};

#endif /* NETWORK_H_ */
