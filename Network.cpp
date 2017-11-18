/*
 * Network.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: jubas
 */

#include "Network.h"
#include "Mail.h"
#include <algorithm>

using namespace std;

//===========================================SORT FUNCTIONS==============================================

//=======================================================================================================

/*
 * @brief Compares two mails, pointed by.
 * Useful to call in the sort method, defined by the stl library.
 * A Mail is smaller than the other if his title is smaller.
 *
 *@param rhs - pointer to the right-hand side associate
 *@param lhs - pointer to the left-hand side associate
 */
bool cmpMails(Mail * rhs, Mail * lhs) {
	return rhs->getTitle() < lhs->getTitle();
}
;

//Constructors
Network::Network() {
	// TODO Auto-generated constructor stub

}

//Destructors

Network::~Network() {
	// TODO Auto-generated destructor stub
}

//Set Methods

void Network::setMails(vector<Mail*> mails) {
	this->mails = mails;
}

//Get Methods

vector<Mail *> Network::getMails() const {
	return this->mails;
}

//General

void Network::addMail(Mail * newMail) {

	this->mails.push_back(newMail);
	sort(this->mails.begin(), this->mails.end(), cmpMails);

}
